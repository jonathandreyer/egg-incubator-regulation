// gInput.cpp
#include "gInput.h"
#include "gMBox.h"
#include "SHT2x.h"
#include "Encoder.h"
#include "TimerOne.h"

gInput::gInput() {}

void gInput::initialize() {
  encoder.Timer_init();
}

void gInput::execute() {
  //TODO: Check if possible to reduce time to read value on sensor:
  //  In SHT2xClass::readSensor(...):
  //      - Wire.endTransmission() -> Take time on function twi_writeTo(...)
  //      - Wire.requestFrom(eSHT2xAddress, 3) -> Take time different function
  mbox.inputInter.temperature = SHT2x.GetTemperature();
  mbox.inputInter.humidity = SHT2x.GetHumidity();

  if(encoder.rotate_flag == 1) {
    if(encoder.direct == 0) {
      mbox.inputInter.rotary = backward;
    } else {
      mbox.inputInter.rotary = forward;
    }
    encoder.rotate_flag = 0;
  } else {
    mbox.inputInter.rotary = zero;
  }


}
