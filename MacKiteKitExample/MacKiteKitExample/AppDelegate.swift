//
//  AppDelegate.swift
//  MacKiteKitExample
//

import Cocoa
import AVFoundation
import JavaScriptCore
import KiteKitMac

@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    @IBOutlet weak var window: NSWindow!
    var kiteViewController: KitePresentationViewController?
    @IBOutlet var placeholderView: NSView?


    func applicationDidFinishLaunching(_ aNotification: Notification) {

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

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }
}
