#include <thread>
#include <stdio.h>

#include "Main.hpp"
#include "SimpleRobot.hpp"

static void RobotThread(SimpleRobot *robot) {
    printf("Hello, robot world!\n");
}

int RobotMain(SimpleRobot *robot, int argc, char **argv) {
    std::thread rThread(RobotThread, robot);

    // Begin console output
    rThread.join();
}
