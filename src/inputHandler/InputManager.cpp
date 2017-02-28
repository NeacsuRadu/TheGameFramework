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

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::update()
{

}

void InputManager::clean()
{

}

