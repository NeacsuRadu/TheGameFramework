#include "../inputHandler/InputManager.h"

InputManager* InputManager::instance_ = nullptr;

InputManager* InputManager::Instance()
{
	if (instance_ == nullptr)
	{
		instance_ = new InputManager();
	}
	return instance_;
}

InputManager::InputManager():
	key_state_(nullptr),
	number_of_keys_(0)
{

}

InputManager::~InputManager()
{

}

void InputManager::update()
{
	key_state_ = SDL_GetKeyboardState(&number_of_keys_);

	SDL_Event ev;
	if (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		default:
			break;
		}
		
	}
}

void InputManager::clean()
{

}

bool InputManager::isKeyDown(SDL_Scancode key)
{
	if (key_state_ != nullptr && key_state_[key] == 1)
		return true;
	return false;
}

