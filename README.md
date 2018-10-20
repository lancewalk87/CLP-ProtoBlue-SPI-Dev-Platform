## ProtoBlue - General Purpose Digital Dev/Debug Platform
##### CLP SPI-Dev Platform

#### The ProtoBlue is capable of interfacing with any USB or Wifi/BlueTooth Enabled device, this allows for dynamic and convenient production testing via it's numerous onboard GPIO configurations and peripheral I/0. Capable of transceiving data of up to 72.2Mbps, the ESP8266EX Wireless chip offers a standard Wifi enabled (implementing TCP/IP as well as WLAN MAC protocols) baseband, clocked at 2.4GHz (Rx/Tx) making connection to the debugger ubiquitious amoungest all modern devices. In addition to efficent onboard power management (See Schematic Pg.3 - System Power Diagram), the device is capable of functioning independent of a sustained power supply and has an onboard 3.7v 560mAH LIPO battery complete with Temp Sense for safe and efficent battery rechargablity when the device is plugged in. 

#### The Client Portal, available on iOS, Android, macOS, and Windows, acts as a fully functional MCU SDK, and Debug IDE. Allowing for both standard Assembly C/C++ binaries, as well as the Ardunio IDE (Objective-C) equivalent. The versataile operating system, and accessible GPIO makes the ProtoBlue the most reliable and efficent Debug platform available for any and all MCUs. In addition to the convinent ability to fix code reliably, the ProtoBlue Client Portal allows you to view (either post or pre debug session) individual bit states at any given device I/O Port, ADC, EEPROM, Interrupt, Clock, or SPI, you can investigate each of your device's operations at a binary level.  

#### Given an additional 16GB of Non-Volataile NAND Flash Memory, you can store, edit, and review existing debug sessions in order to illustrate a more clear and foundational understanding of the intricate circuit you are trying to work the kinks out of. This storage also allows you to keep your projects together in a virtual space that is always connected to the hardware capable of performing real-world tests, without the tedious and redundant act of building new testing modules everytime you want to start or resume a different project.  

#### The ProtoBlue, as mentioned above, is capable of performing debug sessions without an additional MCU because the Primary MCU is not integral to the device's Power Management, USB, Wireless, or NAND Flash Memory functionality. Meaning the massive WS2812Bx48 Individually Addressable RGB LED Arrary can be used for a vast number of things ranging from validating data manipulative software (i.e. bitwise tests, timer tests, ttl comparisons), to the implementation of algorithms (i.e. Recursive, Backtracking, Divide/Conquer, Randomizing), to the optimization of the Device RunCycle (i.e. Multithreading, Preprocessing, Error/Exception Handling), to the efficent delegation of finite System resources (SRAM Deallocation/Allocation, Encryption/Overwriting of superfluous data, Conserving Energy by Shifting Power Modes). In conjunction to the LED Array, there are also Buttons connected to the Primary MCU, allowing for variable tacticle user inputs. 

## Architecture Support & Device Compatibility


## Debugging & Programming Targets

### Programming Your Target 
#### Make the proper ICSP connections to your target device's SPI (VCC, GND, MOSI, MISO, SCK, RESET), the ProtoBlue will interpret the target's signature and attempt to evaluate any preexisting EEPROM data. After configuring any neccesary ICSP variables, and cacheing a record of the debug session to it's NAND Flash Storage for later evaluation, the ProtoBlue will begin programming your target with the specefied code. You can review active or past debug sessions in the "debug" view of whatever client device you're using to carry out your tests (See Project Overview for full details on the Native Client environments).

### Debugging Your Target
#### 

### Bootloading Your Target
#### 

