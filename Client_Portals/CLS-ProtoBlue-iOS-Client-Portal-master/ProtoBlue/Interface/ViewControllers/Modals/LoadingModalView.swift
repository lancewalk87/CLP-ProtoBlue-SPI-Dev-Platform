//
//  LoadingModalView.swift
//  ProtoBlue
//
//  Created by Lance T. Walker on 10/19/18.
//  Copyright © 2018 CodeLife-Productions. All rights reserved.
//

// MARK: - Loading Modal Main
class LoadingModalView: UIViewController {
    // MARK: - Initializers
    var loadPrompt: Any!;
    required init(promt: Any?) {
        self.loadPrompt = promt;
        super.init(nibName: nil, bundle: nil);
        print("\(#file): \(#function)");
    }
    required public init?(coder aDecoder: NSCoder) { fatalError("init(coder:) has not been implemented"); }
    
    // MARK: - Modal RunCycle
    override func viewDidLoad() {
        super.viewDidLoad();
        
    }
}
