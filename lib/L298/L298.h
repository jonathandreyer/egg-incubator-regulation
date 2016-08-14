// L298 Library
// by Ronald Schmid <schmron+dev@gmail.com>
// Created 08 May 2011
// Version 0.0.1
//
// Control Grove I2CMotorDriver (L298)

#ifndef L298_h
#define L298_h

#if defined(ARDUINO) && ARDUINO >= 100
#warning "Use 'Arduino.h' because Arduino Version >= 1.0"
#include "Arduino.h"
#else
#warning "Use 'WProgram.h' because Arduino Version < 1.0"
#include "WProgram.h"
#endif

#define L298_DEFAULT_ADDRESS 0x28
#define SETPWMAB          0x82
#define SETFREQ           0x84
#define CHANGEADDR        0x83
#define CHANNELSET        0xaa
#define MOTOR1            0xa1
#define MOTOR2            0xa5
#define SAVEADDR          'S'
#define NOTSAVEADDR       'N'

class L298 {
  public:
    L298(uint8_t address = L298_DEFAULT_ADDRESS);
    uint8_t isPresent(void);
    uint8_t init(void);
    void setAB(uint8_t spda, uint8_t spdb);
    void setPrescaler(uint8_t pres);
    void setAddress(uint8_t new_adr, uint8_t save_or_not);
    void setChannel(uint8_t i4);
    void setMotor(uint8_t motor_s, uint8_t Mstatus, uint8_t spd);
  private:
    void sendCommand(uint8_t com1, uint8_t com2, uint8_t com3);
    uint8_t devAddress;
};

extern L298 motor;

#endif
