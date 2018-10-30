//
//  todoTableViewCell.swift
//  Assignment2
//
//  Created by Vaibhav Sharma on 2018-10-28.
//  Copyright © 2018 Vaibhav Sharma. All rights reserved.
//

import UIKit

protocol TodoCellDelegate {
    func didRequestDelete(_ cell:todoTableViewCell)
    func didRequestComplete(_ cell:todoTableViewCell)
    
}

class todoTableViewCell: UITableViewCell{
   
    

    @IBOutlet weak var TableCellImage: UIImageView!

    var delegate:TodoCellDelegate?

    @IBOutlet weak var TableCellTittle: UILabel!
    
    @IBOutlet weak var TableCellPriority: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
   
    
    @IBAction func itemComplete(_ sender: UIButton) {
        if let delegateObject = self.delegate{
            delegateObject.didRequestComplete(self)
        }
    }
    
    @IBAction func itemDelete(_ sender: UIButton) {
        if let delegateObject = self.delegate{
            delegateObject.didRequestDelete(self)
        }
    }
    
  
    
   
    
}
