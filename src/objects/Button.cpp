#include "../objects/Button.h"

#include <iostream>

Button::Button() :
	SDLGameObject(),
	button_released_(true)
{

}

void Button::load(LoaderParams* pParams)
{
	SDLGameObject::load(pParams);
	m_callbackID = pParams->callbackID;
}

void Button::draw()
{
	SDLGameObject::draw();
}

void Button::update()
{
	Vector2D* mouse_position = InputManager::Instance()->GetMousePosition();

	if (mouse_position->getX() >= position_.getX() &&
		mouse_position->getX() <= position_.getX() + width_ &&
		mouse_position->getY() >= position_.getY() &&
		mouse_position->getY() <= position_.getY() + height_)
	{
		if (InputManager::Instance()->GetMouseButtonState(LEFT))
		{
			if (button_released_)
			{
				button_released_ = false;
				frame_ = MOUSE_CLICKED;
				func();
			}
		}
		else
		{
			button_released_ = true;
			frame_ = MOUSE_OVER;
		}
	}
	else
	{
		frame_ = MOUSE_OUT;
	}
}

void Button::clean()
{
	SDLGameObject::clean();
}

int Button::GetCallbackID()
{
	return m_callbackID;
}

void Button::SetCallback(CallbackFunction fn)
{
	func = fn;
}

//
//		ButtonCreator
//

GameObject* ButtonCreator::CreateGameObject()
{
	return new Button();
}


