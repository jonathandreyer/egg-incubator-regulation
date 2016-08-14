// iRti.cpp
#include "iRti.h"
#include "Arduino.h"

#define QtyOfDelay 10

typedef struct delay_t {
  unsigned int Counter;
  bool IsFree;
  bool IsDone;
} DelayStruct;

static DelayStruct arrayDelay[QtyOfDelay];

// Interrupt Routine
void iRti_INT() {
  int i;
  //TODO clear flag in ISR

  //clear flag

  //Parse array
  for(i=0 ; i<10 ; i++) {
    if(false == arrayDelay[i].IsFree) {
      arrayDelay[i].Counter -= 1;
      if(arrayDelay[i].Counter <= 0) {
        arrayDelay[i].IsDone = true;
      }
    }
  }
}

iRti::iRti() {

}

void iRti::config(DiviFrequ aDivise) {
  //Configure timer 1 of Arduino

  //TODO config ISR interrupt

}

void iRti::initialize() {
  int i;
  for(i=0 ; i<10 ; i++) {
    release(i);
  }
}

int iRti::get(int count_delay) {
  int indexFind = -1;
  int i;

  for(i=0 ; (i<QtyOfDelay)&&(indexFind<0) ; i++) {
    if (true == arrayDelay[i].IsFree) {
      arrayDelay[i].Counter = count_delay;
      arrayDelay[i].IsFree = false;
      arrayDelay[i].IsDone = false;
      indexFind = i;
    }
  }

  return indexFind;
}

void iRti::release(int index) {
  arrayDelay[index].Counter = 0;
  arrayDelay[index].IsFree = true;
  arrayDelay[index].IsDone = false;
}

bool iRti::isDone(int index) {
  return arrayDelay[index].IsDone;
}
