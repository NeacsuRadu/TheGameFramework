#include "../objects/SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* params):
	GameObject(params),
	position_(params->x, params->y),
	velocity_(0,0),
	acceleration_(0,0),
	width_(params->width),
	height_(params->height),
	texture_id_(params->texture_id)
{

}

void SDLGameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->draw(texture_id_, (int)position_.getX(), (int)position_.getY(), width_, height_);
}

void SDLGameObject::update()
{
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		position_ += Vector2D(2, 0);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		position_ += Vector2D(-2, 0);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		position_ += Vector2D(0, -2);
	}
	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		position_ += Vector2D(0, 2);
	}

	/*velocity_ += acceleration_;
	position_ += velocity_;*/

}

void SDLGameObject::clean()
{

}