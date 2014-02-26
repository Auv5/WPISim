#ifndef SIMPLEROBOT_H_
#define SIMPLEROBOT_H_

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

    private:
        RobotState state;
};

#endif
