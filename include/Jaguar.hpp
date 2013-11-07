#ifndef _JAGUAR_H_
#define _JAGUAR_H_

#include "MotorController.hpp"

/** \brief brief
 *
 * detailed
 */
class Jaguar : MotorController
{
public:
    Jaguar(int pwm) : MotorController(pwm) {}
    virtual ~Jaguar() {}
};

#endif /* _JAGUAR_H_ */
