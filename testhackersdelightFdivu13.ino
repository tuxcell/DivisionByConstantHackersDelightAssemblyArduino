// Code to test optimized division by 13
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
// the result is not exactly the same, because divu13 does not always truncate like / does:
// divu13(1026) = 79
// 1026 /13  =  78
// also for many numbers >1026
   a = divu13(i);
b = (i / 13U);
  if (a != b)
  {
   Serial.print(i);Serial.print(" /13 ");Serial.print(" = ");
   Serial.print(a);Serial.print("   ");Serial.println(b);
  }
 }
 Serial.println("Done");
 
 
 }
