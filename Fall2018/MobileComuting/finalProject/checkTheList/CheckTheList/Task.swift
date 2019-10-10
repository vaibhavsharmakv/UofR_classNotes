//
//  Task.swift
//  CheckTheList
//
//  Created by Melanie MacDonald on 2018-11-30.
//  Copyright © 2018 Melanie MacDonald. All rights reserved.
//

import UIKit
import os.log

class Task {
    
    //MARK: Properties
    var name: String
    var descr: String
    var dueDate: Date
    var participants: [String]
    var status: String
    var isCompleted: Bool
    var taskId : String
    
    //MARK: Initialization
    init?(name: String, descr: String, dueDate: Date, participants: [String], status: String, isCompleted: Bool, taskId : String) {
        // Name and status must have a value
        guard !name.isEmpty else {
            return nil
        }
        
        
        // Initialize with given values
        self.name = name
        self.descr = descr
        self.dueDate = dueDate
        self.participants = participants
        self.status = status
        self.isCompleted = isCompleted
        self.taskId = taskId
    }
    
    
}
