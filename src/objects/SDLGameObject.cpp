#include "../objects/SDLGameObject.h"

SDLGameObject::SDLGameObject(const LoaderParams* params):
	GameObject(params),
	x_(params->x),
	y_(params->y),
	width_(params->width),
	height_(params->height),
	texture_id_(params->texture_id)
{

}

void SDLGameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->draw(texture_id_, x_, y_, width_, height_, pRenderer);
}

void SDLGameObject::update()
{

}

void SDLGameObject::clean()
{

}