#include <iostream>
#include <thread>
#include <chrono>
#include <stdio.h>
#include <cctype>

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
        case 'g': {
            char nparam = ' ';
            while (std::isspace(nparam) && std::cin >> nparam);

            switch (nparam) {
            case 'p': {
                int pwm = -1;
                if (!(std::cin >> pwm) || pwm < 1 || pwm > 10) {
                    std::printf("Invalid PWM value: %d\n", pwm);
                    break;
                }
                if (robot->HasPWM(pwm)) {
                    std::printf("Value: %d\n", robot->GetPWM(pwm));
                }
                else {
                    std::printf("PWM is not writable or is not allocated: %d.\n", pwm);
                }
                break;
            }
            case 'd': {
                int dio = -1;
                if (!(std::cin >> dio) || dio < 1 || dio > 10) {
                    std::printf("Invalid DIO value: %d\n", dio);
                    break;
                }
                if (robot->HasDIO(dio)) {
                    std::printf("Value: %d\n", robot->GetDIO(dio));
                }
                else {
                    std::printf("DIO is not writable or is not allocated: %d.\n", dio);
                }
                break;
            }
            case 'r': {
                int relay = -1;
                if (!(std::cin >> relay) || relay < 1 || relay > 10) {
                    std::printf("Invalid relay value: %d\n", relay);
                    break;
                }
                if (robot->HasRelay(relay)) {
                    std::printf("Value: %d\n", robot->GetRelay(relay));
                }
                else {
                    std::printf("Relay is not writable or is not allocated: %d.\n", relay);
                }
                break;
            }
            }
            
            break;
        }
        case 's': {
            char nparam = ' ';
            while (std::isspace(nparam) && std::cin >> nparam);

            switch (nparam) {
            case 'p': {
                int pwm = -1;
                if (!(std::cin >> pwm) || pwm < 1 || pwm > 10) {
                    std::printf("Invalid PWM value: %d\n", pwm);
                    break;
                }

                int pwm_val = -1;
                if (!(std::cin >> pwm_val)) {
                    std::printf("Invalid value: %d\n", pwm_val);
                    break;
                }
                
                if (robot->HasPWM(pwm)) {
                    if (!robot->SetPWM(pwm, pwm_val)) {
                        std::printf("Invalid PWM value: %d.\n", pwm_val);
                    }
                    else {
                        std::printf("PWM successfully written!\n");
                    }
                }
                else {
                    std::printf("PWM is not writable or is not allocated: %d.\n", pwm);
                }
                break;
            }
            case 'd': {
                int dio = -1;
                if (!(std::cin >> dio) || dio < 1 || dio > 14) {
                    std::printf("Invalid DIO value: %d\n", dio);
                    break;
                }

                int dio_val = -1;
                if (!(std::cin >> dio_val)) {
                    std::printf("Invalid value: %d\n", dio_val);
                    break;
                }
                
                if (robot->HasDIO(dio)) {
                    if (!robot->SetDIO(dio, dio_val)) {
                        std::printf("Invalid DIO value: %d.\n", dio_val);
                    }
                    else {
                        std::printf("DIO successfully written!\n");
                    }
                }
                else {
                    std::printf("DIO is not writable or is not allocated: %d.\n", dio);
                }
                break;
            }
            case 'r': {
                int relay = -1;
                if (!(std::cin >> relay) || relay < 1 || relay > 8) {
                    std::printf("Invalid relay value: %d\n", relay);
                    break;
                }

                int relay_val = -1;
                if (!(std::cin >> relay_val)) {
                    std::printf("Invalid value: %d\n", relay_val);
                    break;
                }
                
                if (robot->HasRelay(relay)) {
                    if (!robot->SetRelay(relay, relay_val)) {
                        std::printf("Invalid relay value: %d.\n", relay_val);
                    }
                    else {
                        std::printf("Relay successfully written!\n");
                    }
                }
                else {
                    std::printf("Relay is not writable or is not allocated: %d.\n", relay);
                }
                break;
            }
            }
        }
        }
    }

    // Request a stop and wait for the robot thread to die.
    stop = true;
    rThread.join();

    return 0;
}
