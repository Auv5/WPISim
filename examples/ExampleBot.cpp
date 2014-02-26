#include "WPILib.h"

class ExampleBot : public SimpleRobot {
    public:
        Jaguar m_test;

        ExampleBot() : m_test(1) {}
        virtual ~ExampleBot() {}
};

START_ROBOT_CLASS(ExampleBot);
