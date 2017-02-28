#pragma once

#ifndef BLEAH_INPUTMANAGER_INPUTMANAGER_H_
#define BLEAH_INPUTMANAGER_INPUTMANAGER_H_

#include "../../include/SDL_keyboard.h"

class InputManager
{
public:

	~InputManager();

	static InputManager* Instance();

	void update();
	void clean();

private:

	InputManager();


	static InputManager* instance_;

	Uint8* key_state_;
};

#endif