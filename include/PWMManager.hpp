#ifndef _PWMMANAGER_H_
#define _PWMMANAGER_H_

#include "PWM.hpp"

#include <vector>

// TODO: Check robot...
#define NUM_PWMS 12

/** \brief brief
 *
 * detailed
 */
class PWMManager
{
public:
    virtual ~PWMManager() {}
    void reg_pwm(int pwm, PWM reg);

    static const std::unique_ptr<PWMManager> &get();

private:
    PWMManager();

    std::vector<PWM> pwms;

    const std::unique_ptr<PWMManager> instance;
};

#endif /* _PWMMANAGER_H_ */
