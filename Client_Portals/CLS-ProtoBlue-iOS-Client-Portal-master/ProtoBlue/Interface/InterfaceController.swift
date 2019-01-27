//
//  InterfaceController.swift
//  ProtoBlue
//
//  Created by Lance T. Walker on 10/19/18.
//  Copyright © 2018 CodeLife-Productions. All rights reserved.
//

// MARK: - Root Interface Controller
open class InterfaceController: UIViewController {
    // MARK: - Interface Initialization
    var allocatedViewController: UIViewController!;
    init() {
        self.allocatedViewController = LoadingModalView(promt: nil); 
        super.init(nibName: nil, bundle: nil);
        print("\(#file):\(#function)");
    }
    required public init?(coder aDecoder: NSCoder) { fatalError("init(coder:) has not been implemented"); }
    
    // MARK: - Interface RunCycle
    override open func viewDidLoad() {
        super.viewDidLoad();
        print("Initialized Interface");
    }
    deinit { print("Deallocated Interface"); }

    override open func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning();
        print("\(#file):\(#function)");
    }
    
    // MARK: - Root UI Configuration
}

// MARK: - CLPDevice -> Interface Data Parse
extension InterfaceController {
    
}

// MARK: - UI Event Handlers
extension InterfaceController {
    // MARK: - Inputs
    func keyboardWillShow(_ notifier: NSNotification) {
        
    }
    
    func keyboardWillHide(_ notifer: NSNotification) {
        
    }
    
    // MARK: - Touches & Gestures
    override open func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        
    }
    
    override open func touchesMoved(_ touches: Set<UITouch>, with event: UIEvent?) {
        
    }
    
    override open func touchesEnded(_ touches: Set<UITouch>, with event: UIEvent?) {
        
    }
}

// MARK: - Main ViewController SuperClass
open class PrimaryChildViewController: UINavigationController {
    // MARK: - Initialization
    let navigation_bar: UINavigationBar = {
        let this = UINavigationBar(frame: .zero);
        return this;
    }();
    
    // MARK: - Interface Navigation RunCycle
    override open func viewDidLoad() {
        super.viewDidLoad();
        // Navigation Controller Config:
        delegate = self;
        setNavigationBarHidden(false, animated: true);
    }
}

extension PrimaryChildViewController: UINavigationControllerDelegate {
    public func navigationController(_ navigationController: UINavigationController, willShow viewController: UIViewController, animated: Bool) {

        print("\(#file):\(#function)");
    }
 }
