#ifndef MODIFIABLE_H_
#define MODIFIABLE_H_

class Modifiable {
public:
    virtual bool SetMod(int value) = 0;
    virtual int GetMod() = 0;
};

#endif
