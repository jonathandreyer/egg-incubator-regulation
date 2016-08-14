// gOutput.cpp
#include "gOutput.h"
#include "gMBox.h"
#include "Arduino.h"
#include "SeeedOLED.h"
#include "mCloud.h"
//#include "L298.h"

//#define PIN_PWM_TEMP 10
#define FACTOR_CONV_TEMP 1

mCloud mcloud;

gOutput::gOutput() {}

void gOutput::initialize() {
  //pinMode(PIN_PWM_TEMP, OUTPUT);

  SeeedOled.init();  //initialze SEEED OLED display
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();           //Set addressing mode to Page Mode
  //SeeedOled.setTextXY(0,0);          //Set the cursor to Xth Page, Yth Column
  //SeeedOled.putString("Hello World!"); //Print the String

  mcloud.setup();
  mcloud.open();

  //motor.init();
}

void gOutput::execute() {
  output_temp = mbox.computeInter.output_temperature * FACTOR_CONV_TEMP;

  //analogWrite(PIN_PWM_TEMP, output_temp);
  //motor.setAB(output_temp, output_temp);

  //TODO: Refresh value at 2Hz max
  SeeedOled.setTextXY(0,0);
  SeeedOled.putString("Temp: ");
  SeeedOled.putFloat(mbox.inputInter.temperature, 1);
  SeeedOled.putString("C");
  SeeedOled.setTextXY(2,0);
  SeeedOled.putString("Set: ");
  SeeedOled.putFloat(mbox.computeInter.set_temp, 1);
  SeeedOled.putString("C");
  SeeedOled.setTextXY(4,0);
  SeeedOled.putString("Hum : ");
  SeeedOled.putFloat(mbox.inputInter.humidity, 1);
  SeeedOled.putString("%");
  SeeedOled.setTextXY(6,0);
  SeeedOled.putString("Out : ");
  SeeedOled.putFloat(mbox.computeInter.output_temperature, 1);
  SeeedOled.putString("%");

  //TODO: Every X seconds
  mcloud.edit(mbox.inputInter.temperature, mbox.inputInter.humidity, output_temp);
  mcloud.push();
}
