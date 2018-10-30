//
//  secondViewController.swift
//  Assignment2
//
//  Created by Vaibhav Sharma on 2018-10-29.
//  Copyright © 2018 Vaibhav Sharma. All rights reserved.
//

import UIKit

class secondViewController: UIViewController {
    
    @IBOutlet weak var taskName: UITextField!
    @IBOutlet weak var photoImageView: UIImageView!
    @IBOutlet weak var Priority: UITextField!
    @IBOutlet weak var dueDate: UITextField!
    @IBOutlet weak var notes: UITextField!
    
    var passTitle1:String?
    var passDueDate1:String?
    var passNotes1:String?
    var passImage1:UIImage?
    var passPriority1:String?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        taskName.text = passTitle1!
        photoImageView.image = passImage1!
        Priority.text = passPriority1!
        dueDate.text = passDueDate1!
        notes.text = passNotes1!
        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

    @IBAction func selectImageFromPhotoLibrary(_ sender: UITapGestureRecognizer) {
        
    }
}
