//
//  ListTableViewCell.swift
//  CheckTheList
//
//  Created by Melanie MacDonald on 2018-11-14.
//  Copyright © 2018 Melanie MacDonald. All rights reserved.
//

import UIKit

class ListTableViewCell: UITableViewCell {

    //MARK: Properties
    @IBOutlet weak var listName: UILabel!
    @IBOutlet weak var listDueDate: UILabel!
    @IBOutlet weak var participantFlag: UIImageView!
    @IBOutlet weak var completedFlag: UIButton!
    @IBOutlet weak var infoButton: UIButton!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
