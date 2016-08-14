// mCloud.cpp
#include "mCloud.h"
#include "Arduino.h"

mCloud::mCloud() {}

void mCloud::setup() {}

void mCloud::open() {
  Serial.begin(9600);
  Serial.println("[BY SERIAL] Data to push on cloud:");
}

void mCloud::edit(double temperature, double humidity, double temperature_output_percentage) {
  temp = temperature;
  hum = humidity;
  temp_out = temperature_output_percentage;
}

void mCloud::push() {
  if (isnan(hum) || isnan(temp) || isnan(temp_out)) {
    Serial.println("Failed to push data!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print("%\tTemperature: ");
    Serial.print(temp);
    Serial.print("*C\tOutput: ");
    Serial.print(temp_out);
    Serial.println("%");
  }
}
