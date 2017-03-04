#pragma once
#ifndef BLEAH_OBJECTS_SDLGAMEOBJECT_H_
#define BLEAH_OBJECTS_SDLGAMEOBJECT_H_

#include "../objects/GameObject.h"
#include "../vector2d/Vector2D.h"
#include "../TextureManager/TextureManager.h"
#include "../inputHandler/InputManager.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* params);

	virtual void draw();
	virtual void update();
	virtual void clean();

protected:

	Vector2D position_;
	Vector2D velocity_;
	Vector2D acceleration_;
	int width_;
	int height_;
	std::string texture_id_;
};

#endif // !BLEAH_OBJECTS_SDLGAMEOBJECT_H_
