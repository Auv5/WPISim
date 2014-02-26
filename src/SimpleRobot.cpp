#include "SimpleRobot.hpp"
#include <stdio.h>

SimpleRobot *SimpleRobot::inst_ = nullptr;

SimpleRobot::SimpleRobot() :
    state(SimpleRobot::DISABLED),
    pwms(10),
    dios(15),
    relays(8) {
    inst_ = this;
} 

SimpleRobot::~SimpleRobot() { }

SimpleRobot *SimpleRobot::Get() {
    return inst_;
}

void SimpleRobot::Disabled() {
    printf("DEFAULT Disabled() - Consider overriding.\n");
}

bool SimpleRobot::IsDisabled() {
    return this->state == SimpleRobot::DISABLED;
}

void SimpleRobot::Autonomous() {
    printf("DEFAULT Autonomous() - Consider overriding.\n");
}

bool SimpleRobot::IsAutonomous() {
    return this->state == SimpleRobot::AUTO;
}

void SimpleRobot::OperatorControl() {
    printf("DEFAULT OperatorControl() - Consider overriding.\n");
}

bool SimpleRobot::IsOperatorControl() {
    return this->state == SimpleRobot::TELEOP;
}

void SimpleRobot::Test() {
    printf("DEFAULT Test() - Consider overriding.\n");
}

bool SimpleRobot::IsTest() {
    return this->state == SimpleRobot::TEST;
}

bool SimpleRobot::IsEnabled() {
    return this->state != SimpleRobot::DISABLED;
}

SimpleRobot::RobotState SimpleRobot::GetState() {
    return this->state;
}

void SimpleRobot::SetState(SimpleRobot::RobotState state) {
    this->state = state;
}

void SimpleRobot::RegisterPWM(Modifiable *m, int pwm) {
    pwms[pwm] = m;
}

int SimpleRobot::GetPWM(int pwm) {
    return pwms[pwm]->Get();
}

void SimpleRobot::SetPWM(int pwm, int value) {
    pwms[pwm]->Set(value);
}

void SimpleRobot::RegisterDIO(Modifiable *m, int dio) {
    dios[dio] = m;
}

int SimpleRobot::GetDIO(int dio) {
    return dios[dio]->Get();
}

void SimpleRobot::SetDIO(int dio, int value) {
    dios[dio]->Set(value);
}

void SimpleRobot::RegisterRelay(Modifiable *m, int relay) {
    relays[relay] = m;
}

int SimpleRobot::GetRelay(int relay) {
    return relays[relay]->Get();
}

void SimpleRobot::SetRelay(int relay, int value) {
    relays[relay]->Set(value);
}
