// gCompute.cpp
#include "gCompute.h"
#include "gMBox.h"
#include "PID_v1.h"

#define INCREMENT_SETPOINT 0.2

double temp_input;
double temp_output;
double temp_setPoint;
//double temp_Kp;
//double temp_Ki;
//double temp_Kd;

//TODO: Find solution for link to internal variables of class
PID pidTemp(&temp_input, &temp_output, &temp_setPoint, 2, 5, 1, DIRECT);

gCompute::gCompute() {}

void gCompute::initialize() {
  //Restore PID value??
  temp_setPoint = 22;
  //temp_Kd = 2;
  //temp_Ki = 5;
  //temp_Kd = 1;

  pidTemp.SetMode(AUTOMATIC);
  pidTemp.SetSampleTime(250);
}

void gCompute::execute() {
  temp_input = mbox.inputInter.temperature;

  if(mbox.inputInter.rotary == backward) {
    temp_setPoint -= INCREMENT_SETPOINT;
  } else if(mbox.inputInter.rotary == forward) {
    temp_setPoint += INCREMENT_SETPOINT;
  }

  //Compute both PID with library
  pidTemp.Compute();

  mbox.computeInter.output_temperature = temp_output;
  mbox.computeInter.set_temp = temp_setPoint;
}
