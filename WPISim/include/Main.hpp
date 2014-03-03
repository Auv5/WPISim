#ifndef MAIN_H_
#define MAIN_H_

// Pretty much a no-op at this point. Just for clarity.
#include "SimpleRobot.hpp"

int RobotMain(SimpleRobot *robot, int argc, char **argv);

// The purpose of int unused__ is so the user can end the statement in a ; and to emulate WPILib behaviour.
#define START_ROBOT_CLASS(T) int main(int argc, char **argv) { return RobotMain( new T () , argc, argv); } int unused__

#endif
