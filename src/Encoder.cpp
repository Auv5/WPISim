#include "Encoder.hpp"

Encoder::Encoder(int a, int b) : PWM() {
    this->a = a;
    this->b = b;
}

void Encoder::SetDistancePerPulse(double per_pulse) {
    this->per_pulse = per_pulse;
}

void Encoder::SetMaxPeriod(unsigned long max_period) {
    this->max_period = max_period;
}

void Encoder::SetReverseDirection(bool reverse) {
    this->reverse = reverse;
}

void Encoder::Start() {
    // START (Mario Party voice...)
}
