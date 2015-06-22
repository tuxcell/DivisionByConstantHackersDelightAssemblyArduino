// Code to test optimized division by 1000
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
 for (i=0;i<60000;i++) 
 {
// the result is not exactly the same, because divu1000 does not always truncate like / does:
// divu1000(11744) = 12
// 11744 /1000  = 11
// also for many numbers >11744
   
   a = divu1000(i);
b = (i / 1000U);
  if (a != b)
  {
   Serial.print(i);Serial.print(" /1000 ");Serial.print(" = ");
   Serial.print(a);Serial.print("   ");Serial.println(b);
  }
 }
 Serial.println("Done");
 
 
 }
