#include <Adafruit_AS7341.h>
#include <Wire.h>
Adafruit_AS7341 as7341;
void setup() {
  // communication with the host computer serial monitor
  Serial.begin(115200);
  while (!Serial) {
    delay(1);
  }
  if (!as7341.begin()){
    Serial.println("Could not find AS7341");
    while (1) { delay(10); }
  }
  as7341.setLEDCurrent(0); // 40mA  
  as7341.enableLED(true);
  as7341.setATIME(100);
  as7341.setASTEP(100);
  as7341.setGain(AS7341_GAIN_256X);
}
void loop() {
  uint16_t readings[6];
  if (!as7341.readAllChannels(readings)){
    Serial.println("Error reading all channels!");
    return;
  }
  // #1 blue
  Serial.print(readings[2]); // F3 Blue
  Serial.print(", ");
  // #2 red
  Serial.print(readings[8]); // F7 red
  Serial.print(", ");
  // #3 green
  Serial.print(readings[3]);  // F4 green
  Serial.print(", ");
  // #4 orange
  Serial.print(readings[7]); // F6 orange
  Serial.print(", ");
  // #5 purple
  Serial.print(readings[0]); // F1 violet
  Serial.print(", ");
  Serial.println();
}