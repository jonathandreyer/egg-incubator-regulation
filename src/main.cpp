/**
 * TODO Change description of project
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include "main.h"
#include "Arduino.h"
#include "Wire.h"
#include "mDelay.h"
#include "gMBox.h"
#include "gInput.h"
#include "gCompute.h"
#include "gOutput.h"


mDelay mdelay(10);

gInput input;
gCompute compute;
gOutput output;

void setup()
{
  // Initialize modules
  Wire.begin();
  mdelay.setup();

  // Initialize managers
  input.initialize();
  compute.initialize();
  output.initialize();
}

void loop()
{
  input.execute();
  compute.execute();
  output.execute();
}
