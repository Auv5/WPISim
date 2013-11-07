#ifndef _SIMPLEROBOT_H_
#define _SIMPLEROBOT_H_

/** \brief brief
 *
 * detailed
 */
class SimpleRobot
{
public:
    SimpleRobot();
    virtual ~SimpleRobot();

    virtual void Autonomous();

    virtual void OperatorControl();

    virtual void Test();

    void Main();
};

#endif /* _SIMPLEROBOT_H_ */
