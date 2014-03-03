#ifndef MOTORCONT_H_
#define MOTORCONT_H_

class MotorController {
public:
    MotorController(int pwm_l);
    virtual ~MotorController();

    virtual void Set(float value);
    virtual float Get();

private:
    float value;
    int pwm;
};

class Jaguar : public MotorController {
public:
    Jaguar(int pwm) : MotorController(pwm) { }
    virtual ~Jaguar() { }
};

class Talon : public MotorController {
public:
    Talon(int pwm) : MotorController(pwm) { }
    virtual ~Talon() { }
};

class Victor : public MotorController {
public:
    Victor(int pwm) : MotorController(pwm) { }
    virtual ~Victor() { }
};

#endif
