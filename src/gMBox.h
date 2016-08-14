// gMBox.h
#ifndef __GMBOX_H__
#define __GMBOX_H__

enum eEncoder { backward, zero, forward };

typedef struct {
  float temperature;
  float humidity;
  eEncoder rotary;
} InputInterStruct;

typedef struct {
  double output_temperature;
  double set_temp;
} ComputeInterStruct;

class gMBox {
  public:
    InputInterStruct inputInter;
    ComputeInterStruct computeInter;
};

extern gMBox mbox;

#endif
