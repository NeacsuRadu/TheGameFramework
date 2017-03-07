#pragma once
#ifndef BLEAH_OBJECTS_BUTTON_H_
#define BLEAH_OBJECTS_BUTTON_H_
#include "../objects/SDLGameObject.h"

enum MOUSE_STATES {
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	MOUSE_CLICKED = 2
};

class Button : public SDLGameObject
{
public:
	Button();

    virtual void draw();
	virtual void update();
	virtual void clean();
	virtual void load(LoaderParams* pParams);
private:
	bool button_released_;

	CallbackFunction func;
};


class ButtonCreator : public GameObjectCreator
{
public:
	virtual GameObject* CreateGameObject();
};

#endif