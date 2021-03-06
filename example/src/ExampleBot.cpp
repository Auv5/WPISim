#include <cstdio>

#include "WPILib.h"

#include "EDigitalInput.h"

class ExampleBot : public SimpleRobot {
    public:
        Jaguar m_test;
        EDigitalInput in_test;
        Compressor compressor;

        ExampleBot() : m_test(1), in_test(1), compressor(1, 0) {}
        virtual ~ExampleBot() {}

        void OperatorControl() {
            // Do an Update() to clean the buffers.
            in_test.Update();
            compressor.Start();

            while (IsOperatorControl()) {
                if (in_test.GetEvent() == kEventClosed) {
                    std::printf("Switch closed!\n");
                }
                else if (in_test.GetEvent() == kEventOpened) {
                    std::printf("Switch opened!\n");
                }

                in_test.Update();
            }
        }
};

START_ROBOT_CLASS(ExampleBot);
