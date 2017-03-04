#pragma once

#ifndef BLEAH_INPUTMANAGER_INPUTMANAGER_H_
#define BLEAH_INPUTMANAGER_INPUTMANAGER_H_

#include <iostream>
#include <vector>

#include "../../include/SDL.h"
#include "../../include/SDL_keyboard.h"

#include "../game/Game.h"
#include "../vector2d/Vector2D.h"

enum MOUSE_BUTTONS {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputManager
{
public:

	~InputManager();

	static InputManager* Instance();

	void update();
	void clean();

	bool isKeyDown(SDL_Scancode key);
	Vector2D* GetMousePosition() const;
	bool GetMouseButtonState(MOUSE_BUTTONS button);
private:

	InputManager();

	void OnKeyDown();
	void OnMouseButtonDown(SDL_Event ev);
	void OnMouseButtonUp(SDL_Event ev);
	void OnMouseMove(SDL_Event ev);

	static InputManager* instance_;

	const Uint8* key_state_;
	int number_of_keys_;

	std::vector<bool> mouse_buttons_states_;
	Vector2D* mouse_position_;
};

#endif