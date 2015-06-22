// Code to test optimized division by 3
// Jose Gama June, 2015

#include <Arduino.h>
#include "HackersDelight.h"

void setup()
 {
 Serial.begin(9600);
 Serial.println("Start");
 }
 
void loop()
 {
 
uint16_t i, a, b;
 for (i=0;i<65535;i++) 
 {
// the result is exactly the same
   a = divu3(i);
b = (i / 3U);
  if (a != b)
  {
   Serial.print(i);Serial.print(" /3 ");Serial.print(" = ");
   Serial.print(a);Serial.print("   ");Serial.println(b);
  }
 }
 Serial.println("Done");
 
 
 }
