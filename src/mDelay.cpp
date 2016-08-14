// mDelay.cpp
#include "mDelay.h"
#include "iRti.h"


iRti rti;

mDelay::mDelay(int base_periode_ms) {
  base_periode = base_periode_ms;
}

void mDelay::setup() {
  //TODO check how configure iRti
  rti.config((DiviFrequ)base_periode);
  rti.initialize();
}

int mDelay::get(int count_delay) {
  return rti.get(count_delay);
}

void mDelay::release(int index) {
  rti.release(index);
}

bool mDelay::isDone(int index) {
  return rti.isDone(index);
}
