//
//  ViewController.swift
//  Simulator-iOSKiteKitExample
//

import UIKit

import AVFoundation
import JavaScriptCore
import KiteKit

class ViewController: UIViewController {

    var kiteViewController: KitePresentationViewController?
    @IBOutlet var placeholderView: UIView?

    override func viewDidLoad()
    {
        super.viewDidLoad()

        // Get a URL to the embedded Kite document 'Heart.kite'
        //
        guard let documentURL = Bundle.main.url(forResource: "Heart", withExtension: "kite") else {
            fatalError("Bundled kite document not found!")
        }

        // Create a KiteDocument object to load the file
        //
        let kiteDocument = KiteDocument(fileURL: documentURL)

        // Create a KitePresentationViewController to present the view
        //
        guard let kitePresentationViewController = KitePresentationViewController(kiteDocument: kiteDocument) else {
            fatalError("Could not create Kite Presentation View Controller")
        }

        // Hold on to a strong reference to the view controller
        //
        self.kiteViewController = kitePresentationViewController

        // Add the KitePresentationView to the view hierarchy
        //
        self.placeholderView?.addSubview(kitePresentationViewController.view)

        // Start the document playback
        //
        self.kiteViewController?.startPresenting()
    }
}
