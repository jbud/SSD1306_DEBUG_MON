#include <SSD1306_DEBUG_MON.h>
SSD1306_DEBUG_MON debug;

void setup() {
  debug.begin();
}

void loop() {
  debug.writeln("Hello World!");
}
