#include "sbus.h"

#include <Servo.h>
Servo servo1;

SBUS sbus;

int ppos = 0;

void setup() {
  Serial.begin(9600);
  sbus.begin(11, sbusNonBlocking);
  
  // put your setup code here, to run once:
  servo1.attach (46);
}

void loop() {
  // Range 1110 - 1930 , center 1520
  int ch1 = sbus.getChannel(1); //Right L-R
  int ch2 = sbus.getChannel(2); //Right U-D
  int ch3 = sbus.getChannel(3); //Left U-D
  int ch4 = sbus.getChannel(4); //Left L-R


  int pos = ceil(0.11 * ch3 - 121.83) - 1;

  if(ppos != pos)
  {
    for(int i=ppos ; i<=pos ; i+=1)
    {
      servo1.write(i);
      delay(10);
    }
    ppos = pos;
  }
  
  Serial.print(ch3);
  Serial.print("    ");
  Serial.println(pos);
  /*
  Serial.print(ch1);
  Serial.print("        ");
  Serial.print(ch2);
  Serial.print("        ");
  Serial.print(ch3);
  Serial.print("        ");
  Serial.println(ch4);*/
  // put your main code here, to run repeatedly:

}
