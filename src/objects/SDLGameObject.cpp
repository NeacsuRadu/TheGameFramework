#include "../objects/SDLGameObject.h"

#include <iostream>

SDLGameObject::SDLGameObject(const LoaderParams* params):
	GameObject(params),
	position_(params->x, params->y),
	velocity_(0,0),
	acceleration_(0,0),
	row_(0),
	frame_(0),
	width_(params->width),
	height_(params->height),
	texture_id_(params->texture_id)
{

}

void SDLGameObject::draw()
{
	TextureManager::Instance()->draw(texture_id_, (int)position_.getX(), (int)position_.getY(), width_, height_, row_, frame_);
}

void SDLGameObject::update()
{
	velocity_ += acceleration_;
	position_ += velocity_;
}

void SDLGameObject::clean()
{
	TextureManager::Instance()->remove(texture_id_);
}