//
//  ListViewController.swift
//  CheckTheList
//
//  Created by Melanie MacDonald on 2018-11-08.
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

class ListViewController: UIViewController, UITextFieldDelegate, UITextViewDelegate, UIPickerViewDelegate, UINavigationControllerDelegate, UIPickerViewDataSource {
    
    //MARK: Properties
    @IBOutlet weak var nameTextField: UITextField!
    @IBOutlet weak var descrTextView: UITextView!
    @IBOutlet weak var dueDatePicker: UIDatePicker!
    @IBOutlet weak var optParticipant1: UILabel!
    @IBOutlet weak var participantPicker: UIPickerView!
    @IBOutlet weak var saveButton: UIBarButtonItem!
    @IBOutlet weak var cancelButton: UIBarButtonItem!
    @IBOutlet weak var addParticipant: UIButton!
    @IBOutlet weak var selectParticipant: UIButton!
    
    //MARK: Firebase variables
    let db = Firestore.firestore()
    let uuid = NSUUID().uuidString.lowercased()
    
    
    var participantOptions : [String] = []
    

    // Controls whether passing in a new or preexisting list
    var checklist: List?
    
    var isEdit: Bool?

    
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        //generating a new unique identifier to add a new checklist everytime
        
        
        // kv: update participants from firebase into the the array participantOptions
        getUserFromUserList()
        
       
        
        nameTextField.delegate = self
        descrTextView.delegate = self
        participantPicker.delegate = self
        participantPicker.dataSource = self

        
        //Create a black border around the description text view
        descrTextView.layer.borderWidth = 1
        descrTextView.layer.borderColor = UIColor(red: 0.9, green: 0.9, blue: 0.9, alpha: 1.0).cgColor
        
        if let checklist = checklist {
            isEdit = true
            navigationItem.title = checklist.name
            nameTextField.text = checklist.name
            descrTextView.text = checklist.descr
            dueDatePicker.setDate(checklist.dueDate, animated: true)
            if checklist.participants.count != 0 {
                optParticipant1.text = checklist.participants.compactMap({$0}).joined(separator: "\n")
            }
            if optParticipant1.text?.components(separatedBy: "\n").count == 3 {
                addParticipant.isHidden = true
            }
        } else {
            saveButton.isEnabled = false
            isEdit = false
        }
        
    }
    
    //MARK: UITextFieldDelegate

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        //Hide the keyboard
        textField.resignFirstResponder()
        
        return true
    }
    
    func textFieldDidEndEditing(_ textField: UITextField) {
        if textField.text != "" {
            saveButton.isEnabled = true
        }
        else {
            saveButton.isEnabled = false
        }
        navigationItem.title = textField.text
    }

    func textFieldDidBeginEditing(_ textField: UITextField) {
        //Executes on user tapping text field to edit
        saveButton.isEnabled = false
    }
    
    //MARK: UITextViewDelegate
    
    //Setup for handling to resign the text view keyboard
    func textViewDidBeginEditing(_ textView: UITextView) {
        cancelButton.title = "Done"
    }
    
    func textViewDidEndEditing(_ textView: UITextView) {
        cancelButton.title = "Cancel"
    }
    
    //MARK: UIPickerDataSource
    
    func numberOfComponents(in dateDuePicker: UIPickerView) -> Int {
        return 1
    }
    
    // Sets the number of options for the pickers as according to their tag values, and the number of elements in
    // their "options" arrays
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return self.participantOptions.count
    }
    
    // Sets the values of the pickers as according to their tag values
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return "\(self.participantOptions[row])"
    }
    
    //MARK: Navigation
    
    @IBAction func cancel(_ sender: Any) {
        // This button should dismiss the text view keyboard if it is open
        if cancelButton.title == "Done" {
            descrTextView.resignFirstResponder()
            return
        }
        
        //Depending on style of presentation (modal or push), this view should be dismissed differently (is treated differently whether it was used to "Add" or "Edit")
        let isPresentingInAddMode = presentingViewController is UINavigationController
        
        if isPresentingInAddMode && !isEdit!{
            dismiss(animated: true, completion: nil)
        }
        else if let owningNavigationController = navigationController {
            owningNavigationController.popViewController(animated: true)
        }
        else {
            fatalError("The List View Controller is not inside a navigation controller")
        }
    }
    
    // Configure a view controller before it's presented
    
     override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        super.prepare(for: segue, sender: sender)

     // Confgure the destination view controller only when save button is pressed
     guard let button = sender as? UIBarButtonItem, button === saveButton else {
     os_log("The save button was not pressed, cancelling", log: OSLog.default, type: .debug)
     return
     }
   
     let name = nameTextField.text ?? ""
     let descr = descrTextView.text ?? ""
     let dueDate = dueDatePicker.date
     var participants = optParticipant1.text?.components(separatedBy: "\n")
    if optParticipant1.text == "None" {
        participants = []
    }
    let isPresentingInAddItemMode = presentingViewController is UINavigationController
     
     if isPresentingInAddItemMode {
     }
 
    
    participants?.append(Auth.auth().currentUser!.email!)
    
   
        
    //KV :Saving into Firebase
        // objects to add
       let docData: [String: Any] = [
            "User": Auth.auth().currentUser?.uid ?? "UID missing",
            "checklistName": name,
            "status": false,
            "description": descr,
            "dueDate": dueDate,
            "dateCreated" : NSDate(),
            "participants" : participants!,
            "checklistId" : uuid,
            
        ]
        let docData1: [String: Any] = [
                "checklistID" : uuid,

            ]
        
        // add the checklist into checklist collection
        db.collection("Cheklists").document(uuid).setData(docData) { err in
            if let err = err {
                print("Error writing document: \(err)")
            } else {
                print("New Checklist Document successfully written!")
                
            }
        }
        
    
        if (participants!.count > 0) {
            for participant in participants!{
 
                db.collection("Users").document(participant).collection("sharedChecklist").document().setData(docData1) { err in
                    if let err = err {
                        print("Error writing document: \(err)")
                    } else {
                        print("New Checklist Document successfully written!")
                        
                    }
                }
            
                
            }
         }
    }
    
    //MARK: Custom Functions
    
    func getUserFromUserList(){
        
        db.collection("Userlist")
            .getDocuments() { (querySnapshot, err) in
                if let err = err {
                    print("Error getting documents: \(err)")
                } else {
                    for document in querySnapshot!.documents {
                        let data = document.data()
                        
                        let email = data["email"] as? String ?? "none"
                        if !(self.optParticipant1.text?.components(separatedBy: "\n").contains(email))! {
                            self.participantOptions.append(email)
                        }
                    }
                    
                }
                
        }
        self.participantPicker.reloadAllComponents()
    }
    
    @IBAction func saveChecklist(_ sender: UIBarButtonItem) {
        
        
    }
    @IBAction func addParticipant(_ sender: Any) {
        participantPicker.isHidden = false
        selectParticipant.isHidden = false
        addParticipant.isHidden = true
        self.participantPicker.reloadAllComponents()
    }
    @IBAction func commitParticipant(_ sender: Any) {
        selectParticipant.isHidden = true
        participantPicker.isHidden = true
        addParticipant.isHidden = false
        if optParticipant1.text == "None" {
            optParticipant1.text = participantOptions[participantPicker.selectedRow(inComponent: 0)]
        }
        else {
            var participants = optParticipant1.text?.components(separatedBy: "\n")
        participants!.append(participantOptions[participantPicker.selectedRow(inComponent: 0)])
            optParticipant1.text = participants.flatMap({$0})!.joined(separator: "\n")
        }
        
        if optParticipant1.text?.components(separatedBy: "\n").count == 3 {
            addParticipant.isHidden = true
        }
        self.participantOptions = participantOptions.filter {$0 != participantOptions[participantPicker.selectedRow(inComponent: 0)]}
        if participantOptions.count == 0 {
            addParticipant.isHidden = true
        }
    }
    
  

}
