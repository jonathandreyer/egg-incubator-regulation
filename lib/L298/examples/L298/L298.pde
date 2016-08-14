// MMA7660 Library
// by Ronald Schmid <schmron+dev@gmail.com>
// Created 18 May 2012
// Version 0.0.1
//
// Control Grove I2CMotorDriver (L298)

#include "Wire.h"
#include "L298.h"

void setup() {
  Wire.begin();
  
  motor.init();
  
  // wait a while
  delay(100);
}

void loop() {

}
