#include <SSD1306_DEBUG_MON.h>
SSD1306_DEBUG_MON debug(128, 64, 0x3C);

void setup() {
  debug.begin();
}
static const uint8_t analog_pins[] = {A0,A1,A2,A3,A4,A5,A6,A7};
void loop() {
  
    char v[30];
    char temp[6];
    dtostrf((analogRead(analog_pins[3])* (5.0 / 1023.0)), 6, 4, temp);
    sprintf(v, "Pin A%d is: %sV", 3, temp);
    debug.print(v);
}
