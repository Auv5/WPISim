#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>

#include "Main.hpp"
#include "SimpleRobot.hpp"

bool stop = false;

static void RobotThread(SimpleRobot *robot) {
    // Drop right into the loop: Run methods and wait for mode-end.
    while (!stop) {
        switch (robot->GetState()) {
        case SimpleRobot::AUTO:
            robot->Autonomous();
            while (robot->IsAutonomous());
            break;
        case SimpleRobot::TELEOP:
            robot->OperatorControl();
            while (robot->IsOperatorControl());
            break;
        case SimpleRobot::TEST:
            robot->Test();
            while (robot->IsTest());
            break;
        case SimpleRobot::DISABLED:
            robot->Disabled();
            while (robot->IsDisabled());
            break;
        case SimpleRobot::STOP:
            // End the thread when we see a STOP event.
            return;
        default:
            printf("Invalid robot state. Aborting.");
            stop = true;
            return;
        }
    }
}

int RobotMain(SimpleRobot *robot, int argc, char **argv) {
    std::thread rThread(RobotThread, robot);
    
    char c;

    while (!stop && std::cin >> c) {
        switch (c) {
            case 'a':
                robot->SetState(SimpleRobot::AUTO);
                break;
            case 'o':
                robot->SetState(SimpleRobot::TELEOP);
                break;
            case 't':
                robot->SetState(SimpleRobot::TEST);
                break;
            case 'd':
                robot->SetState(SimpleRobot::DISABLED);
                break;
            case 'q':
                robot->SetState(SimpleRobot::STOP);
                stop = true;
                break;
        }
    }

    // Request and stop and wait for the robot thread to die.
    stop = true;
    rThread.join();

    return 0;
}
