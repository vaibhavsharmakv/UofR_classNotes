//
//  TaskTableViewController.swift
//  CheckTheList
//
//  Created by Melanie MacDonald on 2018-11-26.
//  Copyright © 2018 Melanie MacDonald. All rights reserved.
//

import UIKit
import os.log
import Firebase
import FirebaseUI
import GoogleSignIn
import CoreData
import Firebase
import FirebaseAuth

class TaskTableViewController: UITableViewController {

    //MARK: Properties
    
    // this is sent from the ListTableViewController
    var checklist: List?
    
    let db = Firestore.firestore()
    
    var taskName:String = ""
    var taskDesc:String = ""
    var taskDueDate:Timestamp = Timestamp.init()
    var date : Date = Date()
    var userP : [String] = []
    var status: String = ""
    
    var tasks = [Task]()
    
    var checklistID: String  = ""
    
    override func viewDidLoad() {
        super.viewDidLoad()
        print(checklistID)
        self.navigationItem.rightBarButtonItem = self.editButtonItem
        
        loadSampleItems()
        
        
    }
    
    
   
    

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        // #warning Incomplete implementation, return the number of sections
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        // #warning Incomplete implementation, return the number of rows
        return tasks.count
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 110
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        // Table view cells are reused and should be dequeued using a cell identifier
        let cellIdentifier = "TaskTableViewCell"
        
        guard let cell = tableView.dequeueReusableCell(withIdentifier: cellIdentifier, for: indexPath) as? TaskTableViewCell else {
            fatalError("The dequeued cell is not an instance of TaskTableViewCell")
        }
        
        // Fetches the appropriate list
        let task = tasks[indexPath.row]
        
        cell.taskName.text = task.name
        cell.taskDueDate.text = convertDateToString(date: task.dueDate)
        if task.participants.count == 0 {
          cell.participantFlag.isHidden = true
        }
        cell.taskStatus.text = task.status
        if task.isCompleted {
            cell.completedFlag.setImage(UIImage(named: "checked"), for: .normal)
            cell.isUserInteractionEnabled = false
            cell.textLabel!.isEnabled = false
            cell.contentView.alpha = 0.3
        }
        else {
            cell.completedFlag.setImage(UIImage(named: "checkbox"), for: .normal)
            cell.isUserInteractionEnabled = true
            cell.textLabel!.isEnabled = true
            cell.contentView.alpha = 1.0
        }
        
        return cell
    }

    // Override to support conditional editing of the table view.
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }

    // Override to support editing the table view.
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCell.EditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            //TODO: Check here if list is complete, prompt user if they are sure if it isn't
            // Delete the row from the data source
            let task = tasks[indexPath.row]
            print(task.taskId)
            deleteTask(checklistId: task.taskId)
            
            tasks.remove(at: indexPath.row)
            
            tableView.deleteRows(at: [indexPath], with: .fade)
            //save items
        } else if editingStyle == .insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }
    }

    // MARK: - Navigation
    @IBAction func cancel(_ sender: Any) {
        if let owningNavigationController = navigationController {
            owningNavigationController.popViewController(animated: true)
        }
        else {
            fatalError("The List View Controller is not inside a navigation controller")
        }
    }
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        super.prepare(for: segue, sender: sender)
        
        switch(segue.identifier ?? "") {
        case "AddTask":
            
            // Create a new variable to store the instance of PlayerTableViewController
            let destinationVC = segue.destination as! TaskViewController
            destinationVC.checklistId = self.checklistID
            destinationVC.checklist = self.checklist
            
            
        case "EditTask":
            guard let tasksViewController = segue.destination as? TaskViewController else {
                fatalError("Unexpected destination: \(segue.destination)")
            }
            
            guard let selectedItemCell = sender as? TaskTableViewCell else {
                fatalError("Unexpected destination: \(segue.destination)")
            }
            
            guard let indexPath = tableView.indexPath(for: selectedItemCell) else {
                fatalError("The selected cell is not being displayed by the table")
            }
            
            let selectedItem = tasks[indexPath.row]
            tasksViewController.task = selectedItem
            tasksViewController.checklist = checklist
            
            let destinationVC = segue.destination as! TaskViewController
            destinationVC.checklistId = self.checklistID
            destinationVC.checklist = self.checklist
        default:
            fatalError("Unexpected Segue Identifer; \(String(describing: segue.identifier))")
        }
    }

    
    //MARK: Actions
    @IBAction func unwindToItemList(sender: UIStoryboardSegue) {
        if let sourceViewController = sender.source as? TaskViewController, let
            task = sourceViewController.task {}
        
    }
    
    // TODO: Propagate this to Firebase when checked, should be marked completed
    func toggleCompletion(_ cell : TaskTableViewCell) {
        cell.completedFlag.setImage(UIImage(named: "checked"), for: .normal)
        cell.isUserInteractionEnabled = false
        cell.textLabel!.isEnabled = false
        cell.alpha = 0.3
        // mark isCompleted for the specific task to true
        tasks[self.tableView.indexPath(for: cell)!.row].isCompleted = true
    }
    
    @IBAction func markCompleted(_ sender: AnyObject?) {
        let cell = (sender?.superview?.superview as? TaskTableViewCell)!
        if cell.completedFlag.image(for: .normal) == UIImage(named: "checked") {
            return
        }
        let alert = UIAlertController(title: "Are you sure you want to continue?", message: "Marking the task completed will alert all participants and prevent any future changes.", preferredStyle: .actionSheet)
        
        alert.addAction(UIAlertAction(title: "Continue", style: .default, handler: { action in self.toggleCompletion(cell)
        }))
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        
        self.present(alert, animated: true)
        
    }
    
    func sortCompletion() {
        let sortedList = tasks.sorted {
            let number1 = $0.isCompleted ? 1 : 0
            let number2 = $1.isCompleted ? 1 : 0
            return number1 < number2
        }
        tasks = sortedList
        self.tableView.reloadData()
    }
    
    func sortDueDate() {
        let sortedList = tasks.sorted {
            return $0.dueDate < $1.dueDate
        }
        tasks = sortedList
        self.tableView.reloadData()
    }
    
    func sortTitle() {
        let sortedList = tasks.sorted {
            return $0.name < $1.name
        }
        tasks = sortedList
        self.tableView.reloadData()
    }
    
    @IBAction func sortOptionsDisplay(_ sender: Any) {
        let alert = UIAlertController(title: "How would you like to sort?", message: nil, preferredStyle: .actionSheet)
        
        alert.addAction(UIAlertAction(title: "Sort by Completion", style: .default, handler: { action in self.sortCompletion()
        }))
        alert.addAction(UIAlertAction(title: "Sort by Due Date", style: .default, handler: { action in self.sortDueDate()
        }))
        alert.addAction(UIAlertAction(title: "Sort by Title", style: .default, handler: { action in self.sortTitle()
        }))
        alert.addAction(UIAlertAction(title: "Cancel", style: .cancel, handler: nil))
        
        self.present(alert, animated: true)
    }
    
    //MARK: Private Methods
    
    private func loadSampleItems() {
        
        db.collection("Cheklists").document(checklistID).collection("shareTask")
            .addSnapshotListener { (querySnapshot, err) in
            if let err = err {
                print("Error getting documents: \(err)")
            } else {
                for document in querySnapshot!.documents {
                    var data = document.data()
                    self.taskName = data["taskName"] as! String
                    self.taskDueDate = data["dueDate"] as! Timestamp
                    self.taskDesc = data["description"] as! String
                    var taskId = data["taskId"] as! String
                    self.date = self.taskDueDate.dateValue()
                    self.status = data["status"] as! String
                    print(self.status)
                    
                    
                    var participants = data["participants"]
                    
                    if participants != nil {
                        self.userP = ["user1", "user2", "user3"]
                        
                    }
                    else {
                        participants = []
                    }
                    
                    guard let task1 = Task(name: self.taskName, descr:  self.taskDesc, dueDate: self.date , participants: participants as! [String], status: self.status, isCompleted: false, taskId : taskId) else {
                        fatalError("Unable to instantiate list item1")
                    }
                    
                    var isPresent = false
                    for key in self.tasks{
                        
                        if key.name == self.taskName{
                            isPresent = true
                        }
                        
                    }
                    if !isPresent {
                        self.tasks.append(task1)
                        self.tableView.reloadData()
                    }
                    
                   
                }
            }
        }
        
    
        }
    // Converts a Date object into a readable String
    func convertDateToString(date: Date) -> String {
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = .long
        dateFormatter.timeStyle = .short
        
        dateFormatter.locale = Locale(identifier: "en_US")
        return dateFormatter.string(from: date)
    }
    func deleteTask(checklistId:String){
        
        db.collection("Cheklists").document(self.checklistID).collection("shareTask").whereField("taskId", isEqualTo: checklistId)
            .getDocuments() { (querySnapshot, err) in
                if let err = err {
                    print("Error getting documents: \(err)")
                } else {
                    for document in querySnapshot!.documents {
                        
                        
                        self.db.collection("Checklist").document(checklistId).collection("shareTask") .document(document.data()["taskId"] as! String).delete(){ err in
                            if let err = err {
                                print("Error removing document: \(err)")
                            } else {
                                print("Document successfully removed!")
                            }
                        }
                    }
                }
        }
        
        
}
}

