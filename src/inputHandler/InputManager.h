#pragma once

#ifndef BLEAH_INPUTMANAGER_INPUTMANAGER_H_
#define BLEAH_INPUTMANAGER_INPUTMANAGER_H_

#include "../../include/SDL.h"
#include "../../include/SDL_keyboard.h"

#include "../game/Game.h"

class InputManager
{
public:

	~InputManager();

	static InputManager* Instance();

	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);

private:

	InputManager();


	static InputManager* instance_;

	const Uint8* key_state_;
	int number_of_keys_;
};

#endif