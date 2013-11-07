#ifndef _TALON_H_
#define _TALON_H_

#include "MotorController.hpp"

/** \brief brief
 *
 * detailed
 */
class Talon : MotorController
{
public:
    Talon(int pwm) : MotorController(pwm) {}
    virtual ~Talon() {}
};

#endif /* _TALON_H_ */
