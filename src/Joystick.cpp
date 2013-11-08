#include <SDL2/SDL.h>

#include "Joystick.hpp"

Joystick::Joystick(int index) {
    if (!(SDL_WasInit(SDL_INIT_EVERYTHING) & SDL_INIT_JOYSTICK))
    {
	SDL_Init(SDL_INIT_JOYSTICK);
    }

    this->js = SDL_JoystickOpen(index);
}

float Joystick::GetX() {
    Sint16 x = SDL_JoystickGetAxis(this->js, 0);
    if (x > 0) {
	return (x) / 32767;
    }
    else if (x < 0) {
	return (x) / 32768;
    }
    else {
	return 0;
    }
}

float Joystick::GetY() {
    Sint16 y = SDL_JoystickGetAxis(this->js, 1);

    if (y > 0) {
	return (y) / 32767;
    }
    else if (y > 0) {
	return (y) / 32768;
    }
    else {
	return 0;
    }
}

bool Joystick::GetRawButton(int b_index) {
    SDL_JoystickGetButton(this->js, b_index);
}
