#include "MotorController.hpp"

MotorController::MotorController(int pwm_l) :
    pwm(pwm_l),
    value(0.0f) {

}

MotorController::~MotorController() {

}

void MotorController::Set(float value) {
    this->value = value;
}

float MotorController::Get() {
    return value;
}
