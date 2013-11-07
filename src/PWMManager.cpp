#include "PWMManager.hpp"

PWMManager::PWMManager() :
    pwms(NUM_PWMS) {
    // Nothing...
}

void PWMManager::reg_pwm(int pwm, PWM reg) {

}

const std::unique_ptr<PWMManager>&  PWMManager::get() {
    if (!instance)
    {
	instance = std::unique_ptr<PWMManager>(new PWMManager());
    }
    return instance;
}
