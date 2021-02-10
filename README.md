# SSD1306 Debug Monitor Library
Simple Debug Console for SSD1306
This is a library for a Monochrome OLEDs based on SSD1306 drivers running I2C interface

## Requirements
  * A Monochrome OLEDs based on SSD1306 drivers running I2C interface
  * Arduino (not ATTINY)
  * Adafruit's Adafruit_SSD1306 library and dependencies.
  
  
## Implementation
Very easy to implement, simply run include the header, run the constructor, and call begin() in setup(). then you can writeln() anything or just print() a single value repeatedly.

![Alt text](use.jpg?raw=true "Use Case")
