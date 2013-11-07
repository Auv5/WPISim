#include "MotorController.hpp"

MotorController::MotorController(int pwm) : PWM() {
    this->pwm = pwm;
}

void MotorController::Set(float value) {
    this->value = value;
}

float MotorController::Get() {
    return this->value;
}
