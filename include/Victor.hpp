#ifndef _VICTOR_H_
#define _VICTOR_H_

#include "MotorController.hpp"

/** \brief brief
 *
 * detailed
 */
class Victor : MotorController
{
public:
    Victor(int pwm) : MotorController(pwm) {}
    virtual ~Victor() {}
};

#endif /* _VICTOR_H_ */
