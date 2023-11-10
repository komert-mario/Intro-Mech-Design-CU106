#include <sbus.h>

#include "sbus.h"
#include <Servo.h>

Servo servo1;
SBUS sbus;

#define SBUS_PIN 11
int ppos = 0;

void setup() {
  Serial.begin(115200);
  sbus.begin(SBUS_PIN, sbusNonBlocking);
  
  servo1.attach (46);
}

void loop() {
  // Range 1110 - 1930 , center 1520
  /*
  int ch1 = sbus.getChannel(1); //Right L-R
  int ch2 = sbus.getChannel(2); //Right U-D
  int ch3 = sbus.getChannel(3); //Left U-D
  int ch4 = sbus.getChannel(4); //Left L-R
  */


  if(sbus.waitFrame()){

    servo1.writeMicroseconds(sbus.getChannel(3));
    
  }

  delay(20);

  /*
  Serial.print(ch3);
  Serial.print("    ");
  Serial.println(pos);
  
  Serial.print(ch1);
  Serial.print("        ");
  Serial.print(ch2);
  Serial.print("        ");
  Serial.print(ch3);
  Serial.print("        ");
  Serial.println(ch4);*/

}
