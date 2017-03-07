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
	velocity_ += acceleration_;
	position_ += velocity_;
}

void SDLGameObject::clean()
{
	TextureManager::Instance()->remove(texture_id_);
}