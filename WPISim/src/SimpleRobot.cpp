#include <stdio.h>
#include <vector>
#include "SimpleRobot.hpp"

SimpleRobot *SimpleRobot::inst_ = nullptr;

SimpleRobot::SimpleRobot() :
    state(SimpleRobot::DISABLED),
    pwms(10),
    dios(15),
    relays(8) {
    inst_ = this;
    
    for (Modifiable*& m : pwms) {
        m = nullptr;
    }

    for (Modifiable*& m : dios) {
        m = nullptr;
    }

    for (Modifiable*& m : relays) {
        m = nullptr;
    }
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
    pwms[pwm-1] = m;
}

int SimpleRobot::GetPWM(int pwm) {
    return pwms[pwm-1]->GetMod();
}

bool SimpleRobot::SetPWM(int pwm, int value) {
    return pwms[pwm-1]->SetMod(value);
}

bool SimpleRobot::HasPWM(int pwm) {
    return pwms[pwm-1] != nullptr;
}

void SimpleRobot::RegisterDIO(Modifiable *m, int dio) {
    dios[dio-1] = m;
}

int SimpleRobot::GetDIO(int dio) {
    return dios[dio-1]->GetMod();
}

bool SimpleRobot::SetDIO(int dio, int value) {
    return dios[dio-1]->SetMod(value);
}

bool SimpleRobot::HasDIO(int dio) {
    return dios[dio-1] != nullptr;
}

void SimpleRobot::RegisterRelay(Modifiable *m, int relay) {
    relays[relay-1] = m;
}

int SimpleRobot::GetRelay(int relay) {
    return relays[relay-1]->GetMod();
}

bool SimpleRobot::SetRelay(int relay, int value) {
    return relays[relay-1]->SetMod(value);
}

bool SimpleRobot::HasRelay(int relay) {
    return relays[relay-1] != nullptr;
}
