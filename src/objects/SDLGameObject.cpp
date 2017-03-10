#include "../objects/SDLGameObject.h"

#include <iostream>

SDLGameObject::SDLGameObject():
	velocity_(0,0),
	acceleration_(0,0),
	row_(0),
	frame_(0)
{

}


void SDLGameObject::load(LoaderParams* pParams)
{
	width_ = pParams->width;
	height_ = pParams->height;
	texture_id_ = pParams->texture_id;
	position_ = Vector2D(pParams->x, pParams->y);
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->draw(texture_id_, (int)position_.getX(), (int)position_.getY(), width_, height_, row_, frame_);
}

void SDLGameObject::update()
{
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		position_ += Vector2D(0, -2);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		position_ += Vector2D(0, 2);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		position_ += Vector2D(-2, 0);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		position_ += Vector2D(2, 0);
	}

	velocity_ += acceleration_;
	position_ += velocity_;
}

void SDLGameObject::clean()
{
	TextureManager::Instance()->remove(texture_id_);
}

GameObject* RandomCreator::CreateGameObject()
{
	return new SDLGameObject();
}