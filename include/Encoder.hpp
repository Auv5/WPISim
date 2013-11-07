#ifndef _ENCODER_H_
#define _ENCODER_H_

#include "PWM.hpp"

/** \brief brief
 *
 * detailed
 */
class Encoder : PWM
{
public:
    Encoder(int a, int b);
    virtual ~Encoder();

    void SetDistancePerPulse(double per_pulse);
    void SetMaxPeriod(unsigned long max_period);
    void SetReverseDirection(bool reverse);
    void Start();

private:
    int a, b;
    double per_pulse;
    unsigned long max_period;
    bool reverse;
};

#endif /* _ENCODER_H_ */
