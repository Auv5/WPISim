#ifndef DIGITALIN_H_
#define DIGITALIN_H_

#include "Modifiable.hpp"

class DigitalInput : public Modifiable {
public:
    DigitalInput(int dio);
    DigitalInput(int module, int channel);

    bool Get();

    int GetMod();
    bool SetMod(int value);

private:
    bool on;
};

#endif
