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
        default:
            printf("Invalid robot state. Aborting.");
            stop = true;
            return;
        }
    }
}

int RobotMain(SimpleRobot *robot, int argc, char **argv) {
    std::thread rThread(RobotThread, robot);

    // Test the event loop.
    std::this_thread::sleep_for(std::chrono::seconds(3));
    robot->SetState(SimpleRobot::AUTO);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    robot->SetState(SimpleRobot::TELEOP);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    robot->SetState(SimpleRobot::TEST);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    robot->SetState(SimpleRobot::DISABLED);

    // Request and stop and wait for the robot thread to die.
    stop = true;
    rThread.join();

    return 0;
}
