// L298 Library
// by Ronald Schmid <schmron@gmail.com>
// Created 08 May 2011
// Version 0.0.1
//
// Control Grove I2CMotorDriver (L298)

#include <Wire.h>
#include "L298.h"

L298::L298(uint8_t address) {
  devAddress = address;               // save device address
}

uint8_t L298::init(void) {
  if(isPresent() == 1)
    return 1;
  return 0;
}

uint8_t L298::isPresent(void) {
  Wire.beginTransmission(devAddress); // transmit to device MOTORSHIELDaddr
#if defined(ARDUINO) && ARDUINO >= 100
  Wire.write((byte)0x00);                // try to send data
#else
  Wire.send(0x00);
#endif
  if(Wire.endTransmission() == 0)
    return 1;
  return 0;
}

void L298::setAB(uint8_t spda , uint8_t spdb) {
  sendCommand(SETPWMAB, spda, spdb);
}

void L298::setPrescaler(uint8_t pres) {
  sendCommand(SETFREQ, pres, (byte)0x00);
}

void L298::setAddress(uint8_t new_adr, uint8_t save_or_not) {
  sendCommand(CHANGEADDR, new_adr, save_or_not);
  delayMicroseconds(100);             // this command needs at least 6 us
}
 
void L298::setChannel(uint8_t i4) {   // 0b 0000 I4 I3 I2 I1
//  delayMicroseconds(4);
  sendCommand(CHANNELSET, i4, (byte)0x00);
}

void L298::setMotor(uint8_t motor_s, uint8_t Mstatus, uint8_t spd) {
  sendCommand(motor_s, Mstatus, spd);
}

/////////////////////////////////// private  ///////////////////////////////////

void L298::sendCommand(uint8_t com1, uint8_t com2, uint8_t com3) {
  Wire.beginTransmission(devAddress);
#if defined(ARDUINO) && ARDUINO >= 100
  Wire.write(com1);
  Wire.write(com2);
  Wire.write(com3);
#else
  Wire.send(com1);
  Wire.send(com2);
  Wire.send(com3);
#endif
  Wire.endTransmission();
}

// Make a instance for the user
L298 motor = L298();
