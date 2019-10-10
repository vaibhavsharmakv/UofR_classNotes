//
//  TaskTableViewCell.swift
//  CheckTheList
//
//  Created by Melanie MacDonald on 2018-11-26.
//  Copyright © 2018 Melanie MacDonald. All rights reserved.
//

import UIKit

class TaskTableViewCell: UITableViewCell {

    //MARK: Properties
    @IBOutlet weak var taskName: UILabel!
    @IBOutlet weak var taskDueDate: UILabel!
    @IBOutlet weak var taskStatus: UILabel!
    @IBOutlet weak var participantFlag: UIImageView!
    @IBOutlet weak var infoButton: UIButton!
    @IBOutlet weak var completedFlag: UIButton!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
