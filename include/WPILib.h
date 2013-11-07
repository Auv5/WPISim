#ifndef _WPILIB_H_
#define _WPILIB_H_

#include "SimpleRobot.hpp"

#define START_ROBOT_CLASS(cls) int main () { SimpleRobot * rbt = new cls(); rbt->Main(); }

#endif /* _WPILIB_H_ */
