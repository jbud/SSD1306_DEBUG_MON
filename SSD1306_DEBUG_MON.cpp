/*
  SSD1306_DEBUG_MON.cpp - Library for debugging with SSD1306 as a monitor.
  Created by Joe Jackson, February 9, 2021.
  Released into the public domain.
*/

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "SSD1306_DEBUG_MON.h"
#include "splash.h"

SSD1306_DEBUG_MON::SSD1306_DEBUG_MON()
{
    _width = 128;
    _height = 32;
    _i2cAddr = 0x3C;
}


SSD1306_DEBUG_MON::SSD1306_DEBUG_MON(uint8_t w, uint8_t h, uint8_t addr)
{
    _width = w;
    _height = h;
    _i2cAddr = addr;
}

void SSD1306_DEBUG_MON::writeln(char* v)
{
    _display.println(v);
    _display.display();
    _i++;
    if (_i >= 8) {
        _i = 0;
        delay(500);
        _display.clearDisplay();
        _display.setCursor(0, 0);
    }
}

void SSD1306_DEBUG_MON::print(char* v)
{
    _display.clearDisplay();
    _display.print(v);
}

void SSD1306_DEBUG_MON::begin()
{
    _display = new Adafruit_SSD1306(_width, _height, &Wire, -1);
    _display.begin(SSD1306_SWITCHCAPVCC, _i2cAddr);
    _display.clearDisplay();
    _display.drawBitmap((_width - splash1_width) / 2, (_height - splash1_height) / 2,
        splash1_data, splash1_width, splash1_height, 1);
    _display.display();
    delay(2000); // Pause for 2 seconds

    // Clear the buffer
    _display.clearDisplay();
    _display.setTextSize(2);      
    _display.setTextColor(SSD1306_WHITE); // Draw white text
    _display.setCursor(0, 0);     // Start at middle
    _display.cp437(true);
    _display.writeln("SSD1306");
    _display.writeln("Debug Monitor");
    _display.setTextSize(1);
    _display.write("v0.9.2");
    _display.display();
    delay(2000);
    _display.clearDisplay();
    _display.setCursor(0, 0);     // Start at top-left corner
    _display.cp437(true);
    _i = 0;
}