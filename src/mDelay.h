// mDelay.h
#ifndef __MDELAY_H__
#define __MDELAY_H__

class mDelay {
  public:
    mDelay(int base_periode_ms);
    void setup();
    //bool getFlag();       //Useless
    //void resetFlag();     //Useless
    int get(int count_delay);
    void release(int index);
    bool isDone(int index);

  private:
    int base_periode;
};

#endif
