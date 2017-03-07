#pragma once

#include "../objects/SDLGameObject.h"

enum MOUSE_STATES {
	MOUSE_OUT = 0,
	MOUSE_OVER = 1,
	MOUSE_CLICKED = 2
};

typedef void (*CallbackFunction)();

class Button : public SDLGameObject
{
public:
	Button(LoaderParams* pParams, CallbackFunction func);

    virtual void draw();
	virtual void update();
	virtual void clean();
private:
	bool button_released_;

	CallbackFunction func;
};
