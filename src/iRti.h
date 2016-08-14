// iRti.h
#ifndef __IRTI_H__
#define __IRTI_H__

//TODO a revoir (facteur de division!!)
typedef enum
{
    kDiv2_14 = 0x50,
    kDiv2_13 = 0x40,
    kDiv2_12 = 0x30,
    kDiv2_11 = 0x20,
    kDiv2_10 = 0x10,
    kDivOFF = 0
} DiviFrequ;

class iRti {
  public:
    iRti();
    void config(DiviFrequ aDivise);
    void initialize();
    int get(int count_delay);
    void release(int index);
    bool isDone(int index);

  private:
    //int base_periode;

    //TODO Add struct delay in private???
};

#endif
