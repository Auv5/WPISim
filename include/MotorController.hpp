#ifndef _MOTORCONTROLLER_H_
#define _MOTORCONTROLLER_H_

#include "PWM.hpp"

/** \brief brief
 *
 * detailed
 */
class MotorController
{
public:
    MotorController(int pwm);
    virtual ~MotorController() {}

    void Set(float value);
    float Get();

private:
    int pwm;
    float value;
};

#endif /* _MOTORCONTROLLER_H_ */
