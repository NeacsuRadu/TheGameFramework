#include "../objects/SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* params):
	GameObject(params),
	position_(params->x, params->y),
	width_(params->width),
	height_(params->height),
	texture_id_(params->texture_id)
{

}

void SDLGameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->draw(texture_id_, (int)position_.getX(), (int)position_.getY(), width_, height_, pRenderer);
}

void SDLGameObject::update()
{
	velocity_ += acceleration_;
	position_ += velocity_;
}

void SDLGameObject::clean()
{

}