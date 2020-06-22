#include <DMXSerial.h>
#include <Servo.h>
#include "SoftwareSerial.h"
#include "Adafruit_Pixie.h"
SoftwareSerial pixieSerial(-1, 7);
Adafruit_Pixie strip = Adafruit_Pixie(1, &pixieSerial);
Servo pan;
Servo tilt;
int dim,r,g,b;
void setup() {
  DMXSerial.init(DMXReceiver);
  pixieSerial.begin(115200);
  strip.setBrightness(200);
  pan.attach(6);
  tilt.attach(5);
  dim=0;
  r=0;
  g=0;
  b=0;
}

void loop() {
  unsigned long lastPacket = DMXSerial.noDataSince();
  if (lastPacket < 5000) {
    pan.write(DMXSerial.read(1));
    tilt.write(DMXSerial.read(2));
    r = DMXSerial.read(4);
    g = DMXSerial.read(5);
    b = DMXSerial.read(6);
    strip.setPixelColor(0, r, g, b);
    strip.show();
  }
  else{
    strip.setPixelColor(0,0,0,0);
    strip.show();
    pan.write(90);
    tilt.write(90);
  }
}
