/*
  SSD1306_DEBUG_MON.h - Library for debugging with SSD1306 on KSDM3, REQUIRES Adafruit SSD1306 libs.
  Created by Joe Jackson, February 9, 2021.
  Released into the public domain.
*/
#ifndef SSD1306_DEBUG_MON_h
#define SSD1306_DEBUG_MON_h

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>




class SSD1306_DEBUG_MON
{
public:
    SSD1306_DEBUG_MON();
    SSD1306_DEBUG_MON(uint8_t w, uint8_t h, uint8_t addr);
    void writeln(char* v);
    void print(char* v);
    void begin();
private:
    int _width;
    int _height;
    int _i2cAddr;
    int _i;
    Adafruit_SSD1306 _display;
};

#endif