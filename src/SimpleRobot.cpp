#include "SimpleRobot.hpp"
#include <stdio.h>

SimpleRobot::SimpleRobot() :
    state(SimpleRobot::DISABLED) {
    // No code
} 

SimpleRobot::~SimpleRobot() { }

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
