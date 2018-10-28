//
//  ViewController.swift
//  Assignment2
//
//  Created by Vaibhav Sharma on 2018-10-24.
//  Copyright © 2018 Vaibhav Sharma. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UINavigationControllerDelegate, UIImagePickerControllerDelegate, UIPickerViewDelegate, UIPickerViewDataSource{
    

    // mark : outlets from front End
    @IBOutlet weak var taskName: UITextField!
    @IBOutlet weak var photoImageView: UIImageView!
    @IBOutlet weak var Priority: UITextField!
    @IBOutlet weak var dueDate: UITextField!
    @IBOutlet weak var notes: UITextField!
    
    // mark : View Did Load
    override func viewDidLoad() {
        super.viewDidLoad()
        choosePriority()
        toolbarForPicker()
        
     //  let newItem = 
         
       
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    // mark: Priority picker variables
    let priorityOptions = ["High", "Medium", "Low"]
    var chosenPriority: String?
    var imageData:Data!
    var priorityData:String!
    var dueDataData:String!
    
    
  
    
    @IBAction func saveTodoItem(_ sender: Any) {
  
        
        
        
    }
    
}




extension ViewController{

    // mark : UItext field
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        // Hide the keyboard.
     taskName.resignFirstResponder()
        return true
    }
    func textFieldDidEndEditing(_ textField: UITextField) {
        
    }
    
}




extension ViewController{
    // mark : Priority Picker Controller
    
    func choosePriority(){
        let pickerView = UIPickerView()
        pickerView.delegate = self
        Priority.inputView = pickerView
    }
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return 1
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return priorityOptions.count
    }
    
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        return priorityOptions[row]
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        chosenPriority = priorityOptions[row]
        Priority.text = priorityOptions[row]
        priorityData = Priority.text!
        print(priorityData!)
    }
    
    
    /////toobar for Picker Controller////////////////////////////////////
    @objc func dismissKeyboard() {
        //Causes the view (or one of its embedded text fields) to resign the first responder status.
        view.endEditing(true)
    }
    @objc func cancelKeyboard(){
        view.endEditing(true)
        Priority.text = ""
    }
    
    
    func toolbarForPicker(){
        let toolbar = UIToolbar()
        toolbar.sizeToFit()
        let doneButton = UIBarButtonItem(title: "Done", style: .plain, target: self, action:  #selector(ViewController.dismissKeyboard))
        
        let cancelButton = UIBarButtonItem(title: "Reset", style: .plain, target: self, action: #selector(ViewController.cancelKeyboard))
        toolbar.setItems([cancelButton,doneButton], animated: false)
       
        toolbar.isUserInteractionEnabled = true
        Priority.inputAccessoryView = toolbar
    }
    
    
}







extension ViewController{
    // ImagePicker
    
    // mark : Image picker
    func imagePickerControllerDidCancel(_ picker: UIImagePickerController) {
        dismiss(animated: true, completion: nil)
        
    }
    func imagePickerController(_ picker: UIImagePickerController,
                               didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey : Any]) {
        
        // The info dictionary may contain multiple representations of the image. You want to use the original.
        guard let selectedImage = info[.originalImage] as? UIImage else {
            fatalError("Expected a dictionary containing an image, but was provided the following: \(info)")
        }
        
        // Set photoImageView to display the selected image.
       photoImageView.image = selectedImage
       /* let x = selectedImage.pngData()!
        print("starting")
        print(x)
        print("ending")
        photoImageView.image = UIImage(data: x)
        */
        // Dismiss the picker.
        dismiss(animated: true, completion: nil)
    }
    
    @IBAction func selectImageFromPhotoLibrary(_ sender: UITapGestureRecognizer) {
        
        taskName.resignFirstResponder()
        
        // UIImagePickerController is a view controller that lets a user pick media from their photo library.
        let imagePickerController = UIImagePickerController()
        
        // Only allow photos to be picked, not taken.
        imagePickerController.sourceType = .photoLibrary
        
        // Make sure ViewController is notified when the user picks an image.
        imagePickerController.delegate = self
        present(imagePickerController, animated: true, completion: nil)
    }
    
    
}


extension ViewController{
    

/*
 extension ViewController{
 
 
 
 @IBAction func saveTodoItem(_ sender: Any) {
 
 
 
 
 var newItem = TodoItem.init(tittle: taskName.text!, completed: false, photo: imageData, notes: notes.text!, dateCreated: Date(), priority: <#T##String#>, itemId: <#T##UUID#>)
 
 
 
 
 }
 
 }
 
*/
}



