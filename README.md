### CS50 Final Project

For this course i need to make a final project. The final project is an opportunity to take my newfound savvy with programming out for a spin and develop my very own piece of software. The task is that i build something of interest to me, and that i solve an actual problem, that impact my community. The choice of my final project is a hardware-based application for which you program some device.

### Apple HomeKit
I will build a HomeKit device that will work with a ESP8266 Wifi Module.In my final project I will show you how to setup the hardware, write te code in c and compile it to a binary file, here after i will show you how t flash it to a ESP module, and at last how to connect it to you Homekit.

### ESP8266
The ESP8266 is a low-cost Wi-Fi microchip, with a full TCP/IP stack and microcontroller capability, produced by Espressif Systems[1] in Shanghai, China.

The chip first came to the attention of Western makers in August 2014 with the ESP-01 module, made by a third-party manufacturer Ai-Thinker. This small module allows microcontrollers to connect to a Wi-Fi network and make simple TCP/IP connections using Hayes-style commands. However, at first there was almost no English-language documentation on the chip and the commands it accepted.[2] The very low price and the fact that there were very few external components on the module, which suggested that it could eventually be very inexpensive in volume, attracted many hackers to explore the module, the chip, and the software on it, as well as to translate the Chinese documentation.

### Library
For my final project I use the Apple HomeKit accessory server library for ESP-OPEN-RTOS.

### Project
My project will be a HomeKit Security System. Build from scratch. It will enable the user to combine other HomeKit sensors (e.g. contact sensors) to act as a Security system for HomeKit.

### Credits

Maxim Kulkin for providing the esp-homekit library. https://github.com/maximkulkin/esp-homekit (MIT License)
HomeACcessoryKid for providing LifeCycle Manger 2. https://github.com/HomeACcessoryKid/life-cycle-manager (Apache License)

<img src="https://raw.githubusercontent.com/AchimPieters/ESP8266-HomeKit-Fountain-light/master/Images/apple_logo.png" width="20"/>

###### HomeKit Accessory Protocol (HAP) is Apple’s proprietary protocol that enables third-party accessories in the home (e.g., lights, thermostats and door locks) and Apple products to communicate with each other. HAP supports two transports, IP and Bluetooth LE. The information provided in the HomeKit Accessory Protocol Specification (Non-Commercial Version) describes how to implement HAP in an accessory that you create for non-commercial use and that will not be distributed or sold.

###### The HomeKit Accessory Protocol Specification (Non-Commercial Version) can be downloaded from the [HomeKit Apple Developer page.](https://developer.apple.com/homekit/)

###### Copyright © 2019 Apple Inc. All rights reserved.
