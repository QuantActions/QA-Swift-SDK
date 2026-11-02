// swift-tools-version: 5.9

import PackageDescription

let package = Package(
    name: "QASwiftSDK",
    platforms: [
        .iOS(.v17)
    ],
    products: [
        .library(
            name: "QASwiftSDK",
            targets: ["QASwiftSDK", "QuantActionsSDK"]
        ),
    ],
    dependencies: [
        .package(url: "https://github.com/KeyboardKit/KeyboardKit.git", exact: "11.1.6"),
    ],
    targets: [
        .target(
            name: "QASwiftSDK",
            dependencies: [
                .product(name: "KeyboardKit", package: "KeyboardKit"),
                "QuantActionsSDK"
            ]
        ),
        .binaryTarget(
            name: "QuantActionsSDK",
            path: "./Sources/QuantActionsSDK.xcframework"
        ),
    ]
)
