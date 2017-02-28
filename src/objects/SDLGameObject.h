#pragma once
#ifndef BLEAH_OBJECTS_SDLGAMEOBJECT_H_
#define BLEAH_OBJECTS_SDLGAMEOBJECT_H_

#include "../objects/GameObject.h"

class SDLGameObject : public GameObject
{
public:
	SDLGameObject(const LoaderParams* params);

	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
	virtual void clean();

protected:

	int x_;
	int y_;
	int width_;
	int height_;
	std::string texture_id_;
};

#endif // !BLEAH_OBJECTS_SDLGAMEOBJECT_H_
