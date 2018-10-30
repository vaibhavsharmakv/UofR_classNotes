//
//  todoItem.swift
//  Assignment2
//
//  Created by Vaibhav Sharma on 2018-10-27.
//  Copyright © 2018 Vaibhav Sharma. All rights reserved.
//

import Foundation


struct TodoItem: Codable {
    
    var tittle:String
    var completed:Bool
    var photo:String
    var notes:String?=nil
    var dateCreated:Date
    var DueDate:String
     
    var priority:String
    var itemId:UUID
    
   

    func addItem(){
        DataManager.save(self, with: itemId.uuidString)
    }
    
    func deleteItem(){
        DataManager.delete(itemId.uuidString)
    }
    
    mutating func taskComplete(){
        self.completed = true
        DataManager.save(self, with: itemId.uuidString)
        
    }
    
   
    
    
}

