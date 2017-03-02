<!--
[![header](https://kiteapp.co/assets/logo-for-intro.png)](https://kiteapp.co)
-->

# KiteKit for iOS and Mac

<br>

## Overview
KiteKit is an iOS and macOS framework you can embed in your application that allows you to view and play Kite documents (.kite) made with [Kite Compositor](http://kiteapp.co).

<br>

## Requirements
* **iOS**: 10.0+
* **macOS**: 10.12+

KiteKit is written in Swift and currently requires your app to embed the Swift standard libraries. This will only be a concern to you if your app is 100% Objective-C and contains no existing Swift sources.

<br>

## Getting Started

To use the framework, clone/download this repository and locate the example project for the platform you're targeting. Inside the repo there are three example projects:

* **iOS Simulator** – The framework compiled to target the iOS Simularator.<br>
`/iOSKiteKitExample (Simulator)/KiteKit.framework`


* **iOS Device** – The framework compiled to target arm and arm64 devices. <br>
`/iOSKiteKitExample (Device)/KiteKit.framework`


* **macOS** – The framework compiled to target macOS.<br>
`/MacKiteKitExample/KiteKitMac.framework`

Copy the framework bundle into your own project as shown in the example project. Apple has a helpful guide for embedding frameworks [here](https://developer.apple.com/library/content/technotes/tn2435/_index.html) if you need help with this step.

<br>

## Loading and Playing a Kite Document

In your `UIViewController` or `NSViewController` subclass, you can load and create a `KitePresentationViewController` to display and play a Kite document.

**Step by step**

**1.** Import the KiteKit module in your Swift file
```swift
import KiteKit
```

**2.** Get a URL for your embedded Kite document<br>
```swift
let documentURL = Bundle.main.url(forResource: "Heart", withExtension: "kite")
```

**3.** Create a `KiteDocument` object to load the document from the URL
```swift
let kiteDocument = KiteDocument(fileURL: documentURL)
```

**4.** Create a `KitePresentationViewController` to control playback of the Kite view
```swift
let kitePresentationViewController = KitePresentationViewController(kiteDocument: kiteDocument)!
```

**5.** Add the `KitePresentationViewController`'s view to the view hieararchy of your app
```swift
self.placeholderView?.addSubview(kitePresentationViewController.view)
```

**6.** Play the document
```swift
kitePresentationViewController.startPresenting()
```

<br>

**All together:**

```swift
import KiteKit

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
```
