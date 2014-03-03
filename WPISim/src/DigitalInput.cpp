#include "DigitalInput.hpp"
#include "SimpleRobot.hpp"

DigitalInput::DigitalInput(int dio) : on(false) {
    SimpleRobot::Get()->RegisterDIO(this, dio);
}

DigitalInput::DigitalInput(int channel, int dio) : on(false) {
    SimpleRobot::Get()->RegisterDIO(this, dio);
}

bool DigitalInput::Get() {
    return on;
}

bool DigitalInput::SetMod(int value) {
    if (value > 1 || value < 0) {
        return false;
    }
    this->on = value;
    return true;
}

int DigitalInput::GetMod() {
    return on;
}
