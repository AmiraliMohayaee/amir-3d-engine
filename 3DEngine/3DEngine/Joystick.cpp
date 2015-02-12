#include "Joystick.h"
#include <iostream>
#include <string>
#include <SDL.h>

void EnableJoysticks()
{
	static int oldNumJoys = 0;
	int newNumJoys = SDL_NumJoysticks();

	for (int i = 0; i < newNumJoys; i++)
	{
		for (int i = oldNumJoys; i < newNumJoys; i++)
		{
			SDL_JoystickOpen(i);
			std::string name = SDL_JoystickName(i);
			std::cout << "Found this Joystick " << name << "\n";
		}
	}

	oldNumJoys = newNumJoys;

	SDL_JoystickEventState(SDL_ENABLE);
}