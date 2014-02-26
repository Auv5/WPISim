#ifndef MODIFIABLE_H_
#define MODIFIABLE_H_

class Modifiable {
public:
    virtual void Set(int value) = 0;
    virtual int Get() = 0;
};

#endif
