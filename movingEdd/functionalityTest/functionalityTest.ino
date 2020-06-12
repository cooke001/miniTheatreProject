#include <Servo.h>
#include "SoftwareSerial.h"
#include "Adafruit_Pixie.h"
SoftwareSerial pixieSerial(-1, 7);
Adafruit_Pixie strip = Adafruit_Pixie(1, &pixieSerial);
Servo pan;
Servo tilt;
int pos,r,g,b;
void setup() {
  pixieSerial.begin(115200);
  strip.setBrightness(200);
  pan.attach(6);
  tilt.attach(5);
  pos=0;
  r=0;
  g=0;
  b=0;
}

void loop() {
  strip.show();
  for (pos = 0; pos <= 360; pos += 1) {
    pan.write(90*(sin(pos*2*3.141/360)+1));
    tilt.write(90*(cos(pos*2*3.141/360)+1));
    r = (int)127*(sin((pos)*2*3.141/360)+1);
    g = (int)127*(sin((pos+120)*2*3.141/360)+1);
    b = (int)127*(sin((pos+240)*2*3.141/360)+1);
    strip.setPixelColor(0, r, g, b);
    strip.show();
    delay(5);
  }
}
