# KiteKit for iOS and Mac

### Overview
KiteKit is an iOS and macOS framework you can embed in your application that allows you to view and play Kite documents (.kite) made with [Kite Compositor](http://kiteapp.co).

### Requirements
* **iOS**: 10.0+
* **macOS**: 10.12+

KiteKit is written in Swift and currently requires your app to embed the Swift standard libraries. This will only be a concern to you if your app is 100% Objective-C and contains no existing Swift sources.

### Getting Started

To use the framework, clone/download this repository and locate the example project for the platform you're targeting. Inside the repo there are three example projects:

* **iOS Simulator** – The framework compiled to target the iOS Simularator. `/iOSKiteKitExample (Simulator)/KiteKit.framework`
* **iOS Device** – The framework compiled to target arm and arm64 devices. `/iOSKiteKitExample (Device)/KiteKit.framework`
* **macOS** – The framework compiled to target macOS. `/MacKiteKitExample/KiteKitMac.framework`

Copy the framework bundle into your own project as shown in the example project. Apple has a helpful guide for embedding frameworks [here](https://developer.apple.com/library/content/technotes/tn2435/_index.html) if you need help with this step.

### Loading and Playing a Kite Document

In your `UIViewController` or `NSViewController` subclass, you can load and create a `KitePresentationViewController` to display and play a Kite document.

**Step by step**

1. Get a URL for your embedded Kite document<br>
    `let documentURL = Bundle.main.url(forResource: "Heart", withExtension: "kite")`

2. Create a `KiteDocument` object to load the document URL<br>
    `let kiteDocument = KiteDocument(fileURL: documentURL)`

3. Create a `KitePresentationViewController` to control playback of the Kite view
    `let kitePresentationViewController = KitePresentationViewController(kiteDocument: kiteDocument)!`

4. Add the `KitePresentationViewController`'s view to the view hieararchy of your app<br>
    `self.placeholderView?.addSubview(kitePresentationViewController.view)`

5. Play the document<br>
    `kitePresentationViewController.startPresenting()`


**All together:**

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
