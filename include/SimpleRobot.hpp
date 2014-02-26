#ifndef SIMPLEROBOT_H_
#define SIMPLEROBOT_H_

#include <vector>
#include "Modifiable.hpp"

class SimpleRobot {
    public:
        enum RobotState {
            STOP,
            DISABLED,
            AUTO,
            TELEOP,
            TEST
        };

        SimpleRobot();
        virtual ~SimpleRobot();

        virtual void Disabled();
        bool IsDisabled();
        virtual void Autonomous();
        bool IsAutonomous();
        virtual void OperatorControl();
        bool IsOperatorControl();
        virtual void Test();
        bool IsTest();
        bool IsEnabled();

        RobotState GetState();
        void SetState(RobotState state);

        void RegisterPWM(Modifiable *m, int pwm);
        void RegisterDIO(Modifiable *m, int dio);
        void RegisterRelay(Modifiable *m, int relay);

        int GetPWM(int pwm);
        int GetDIO(int dio);
        int GetRelay(int relay);

        void SetPWM(int pwm, int value);
        void SetDIO(int dio, int value);
        void SetRelay(int relay, int value);

        SimpleRobot *Get();

    private:
        RobotState state;
        static SimpleRobot *inst_;
        
        std::vector<Modifiable*> pwms;
        std::vector<Modifiable*> dios;
        std::vector<Modifiable*> relays;
};

#endif
