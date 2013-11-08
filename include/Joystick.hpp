#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#include <SDL2/SDL.h>

/** \brief brief
 *
 * detailed
 */
class Joystick
{
public:
    Joystick(int index);
    virtual ~Joystick();

    bool GetRawButton(int index);

    float GetX();

    float GetY();

private:
    SDL_Joystick *js;
};

#endif /* _JOYSTICK_H_ */
