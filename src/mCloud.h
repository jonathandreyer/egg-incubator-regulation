// mCloud.h
#ifndef __MCLOUD_H__
#define __MCLOUD_H__

class mCloud {
  public:
    mCloud();
    void setup();
    void open();
    void edit(double temperature, double humidity, double temperature_output_percentage);
    void push();

  private:
    double temp;
    double hum;
    double temp_out;
};

#endif
