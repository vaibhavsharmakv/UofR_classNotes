//
//  todoTableViewController.swift
//  Assignment2
//
//  Created by Vaibhav Sharma on 2018-10-28.
//  Copyright © 2018 Vaibhav Sharma. All rights reserved.
//

import UIKit

class todoTableViewController: UITableViewController, TodoCellDelegate {
   
   
    
    var passTitle:String = ""
    var passDueDate:String = ""
    var passNotes:String = ""
    var passImage:UIImage? = nil
    var passPriority:String = ""

    var todoItem:[TodoItem]!
    
    override func viewWillAppear(_ animated:Bool) {
         super.viewWillAppear(animated)
        didLoad()
    }
    
    override func viewDidLoad() {
        
        super.viewDidLoad()
        didLoad()
        
        
        
      //  prepare(for: UIStoryboardSegue, sender: ){
            
        
        // Uncomment the following line to preserve selection between presentations
        // self.clearsSelectionOnViewWillAppear = false

        // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
        // self.navigationItem.rightBarButtonItem = self.editButtonItem
    }
    func didLoad(){
        todoItem = [TodoItem]()
        todoItem = DataManager.loadAll(TodoItem.self).sorted(by: {
            $0.dateCreated < $1.dateCreated
        })
        tableView.reloadData()
    }

    func didRequestDelete(_ cell: todoTableViewCell) {
        if let indexPath = tableView.indexPath(for: cell) {
            todoItem[indexPath.row].deleteItem()
            todoItem.remove(at: indexPath.row)
            tableView.deleteRows(at: [indexPath], with: .automatic)
        }
    }
    
    func didRequestComplete(_ cell: todoTableViewCell) {
            if let indexPath = tableView.indexPath(for: cell) {
                var todoItems = todoItem[indexPath.row]
                todoItems.taskComplete()
               cell.TableCellTittle.attributedText = strikeThroughText(todoItems.tittle)
            }
            
        }
    
    func strikeThroughText (_ text:String) -> NSAttributedString {
        let attributeString: NSMutableAttributedString =  NSMutableAttributedString(string: text)
        attributeString.addAttribute(NSAttributedString.Key.strikethroughStyle, value: 1, range: NSMakeRange(0, attributeString.length))
        
        return attributeString
    }
    
    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        
        return todoItem.count
    }

    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "cellId", for: indexPath) as! todoTableViewCell

        cell.delegate = self
        // Configure the cell...
        let item = todoItem[indexPath.row]
       
       
           
            
           cell.TableCellTittle.text = item.tittle
            
            //
          
            func getImageFromBase64(base64:String) -> UIImage {
                let data = Data(base64Encoded: base64)
                return UIImage(data: data!)!
            }
            
            //
          let imageData = item.photo
            let imageRecived = getImageFromBase64(base64: imageData)
            cell.TableCellImage.image = imageRecived
        
            
            
            if item.priority == "High" {
                cell.TableCellPriority.text =  "!!!"
                cell.TableCellPriority.textColor = UIColor.red
            }
            if item.priority == "Medium"{
                cell.TableCellPriority.text =  "!!"
                cell.TableCellPriority.textColor = UIColor.red
            }
            if item.priority == "Low"{
                cell.TableCellPriority.text =  "!"
                cell.TableCellPriority.textColor = UIColor.red
            }
            
            passTitle = item.tittle
            passDueDate = item.DueDate
            passNotes = item.notes!
            passImage = imageRecived
            passPriority = item.priority
            
            
        if item.completed{
            cell.TableCellTittle.attributedText = strikeThroughText(item.tittle )
        }
           
            
       //  performSegue(withIdentifier: , sender: self)
       
        
        return cell
        
    }
    
    
    
    
    
    
    /*override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        
        let item = todoItem[indexPath.row]
        
        func getImageFromBase64(base64:String) -> UIImage {
            let data = Data(base64Encoded: base64)
            return UIImage(data: data!)!
        }
        
        //
        let imageData = item.photo
        let imageRecived = getImageFromBase64(base64: imageData)*/
        
   
        
    //}
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
    
            super.prepare(for: segue, sender: sender)
            print("not even here")
            if(segue.identifier == "showtask") {
            
            if let secondViewController = segue.destination as? secondViewController{
            print("here")
            secondViewController.passImage1 = passImage!
            secondViewController.passNotes1 = passNotes
            secondViewController.passPriority1 = passPriority
            secondViewController.passTitle1 = passTitle
            secondViewController.passDueDate1 = passDueDate
            
            }else{print("nope")
                
                }
        
        }
    }
    
   

    /*
    // Override to support conditional editing of the table view.
    override func tableView(_ tableView: UITableView, canEditRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the specified item to be editable.
        return true
    }
    */

    /*
    // Override to support editing the table view.
    override func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if editingStyle == .delete {
            // Delete the row from the data source
            tableView.deleteRows(at: [indexPath], with: .fade)
        } else if editingStyle == .insert {
            // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
        }    
    }
    */

    /*
    // Override to support rearranging the table view.
    override func tableView(_ tableView: UITableView, moveRowAt fromIndexPath: IndexPath, to: IndexPath) {

    }
    */

    /*
    // Override to support conditional rearranging of the table view.
    override func tableView(_ tableView: UITableView, canMoveRowAt indexPath: IndexPath) -> Bool {
        // Return false if you do not want the item to be re-orderable.
        return true
    }
    */

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}

