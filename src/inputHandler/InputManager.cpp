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
	number_of_keys_(0),
	mouse_position_(new Vector2D(0,0))
{
	for (int i = 0; i < 3; ++i)
	{
		mouse_buttons_states_.push_back(false);
	}
}

InputManager::~InputManager()
{
	if (mouse_position_ != nullptr)
	{
		delete mouse_position_;
	}
	if (instance_ != nullptr)
	{
		delete instance_;
	}
}

void InputManager::update()
{
	SDL_Event ev;
	if (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
		case SDL_QUIT:
			Game::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			OnKeyDown();
			break;
		case SDL_MOUSEBUTTONDOWN:
			OnMouseButtonDown(ev);
			break;
		case SDL_MOUSEBUTTONUP:
			OnMouseButtonUp(ev);
			break;
		case SDL_MOUSEMOTION:
			OnMouseMove(ev);
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

void InputManager::OnKeyDown()
{
	key_state_ = SDL_GetKeyboardState(&number_of_keys_);
}

void InputManager::OnMouseButtonDown(SDL_Event ev)
{
	if (ev.button.button == SDL_BUTTON_LEFT)
	{
		mouse_buttons_states_[LEFT] = true;
	}
	else if (ev.button.button == SDL_BUTTON_MIDDLE)
	{
		mouse_buttons_states_[MIDDLE] = true;
	}
	else if (ev.button.button == SDL_BUTTON_RIGHT)
	{
		mouse_buttons_states_[RIGHT] = true;
	}
}

void InputManager::OnMouseButtonUp(SDL_Event ev)
{
	if (ev.button.button == SDL_BUTTON_LEFT)
	{
		mouse_buttons_states_[LEFT] = false;
	}
	else if (ev.button.button == SDL_BUTTON_MIDDLE)
	{
		mouse_buttons_states_[MIDDLE] = false;
	}
	else if (ev.button.button == SDL_BUTTON_RIGHT)
	{
		mouse_buttons_states_[RIGHT] = false;
	}
}

void InputManager::OnMouseMove(SDL_Event ev)
{
	mouse_position_->setX(ev.motion.x);
	mouse_position_->setY(ev.motion.y);
}

Vector2D* InputManager::GetMousePosition() const
{
	return mouse_position_;
}

bool InputManager::GetMouseButtonState(MOUSE_BUTTONS button)
{
	return mouse_buttons_states_[button];
}
