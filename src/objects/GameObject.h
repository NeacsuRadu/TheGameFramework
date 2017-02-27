#pragma once

#ifndef BLEAH_OBJECTS_GAMEOBJECT_H_
#define BLEAH_OBJECTS_GAMEOBJECT_H_

#include <iostream>

#include "../TextureManager/TextureManager.h"

struct LoaderParams
{
	LoaderParams(int x, int y, int width, int height, std::string texture_id) :
		x(x), y(y), width(width), height(height), texture_id(texture_id) {}
	int x;
	int y;
	int width;
	int height;
	std::string texture_id;
};



class GameObject
{
public:
	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;

protected:

	GameObject(const LoaderParams* pParams) {};
	virtual ~GameObject() {};
};

#endif
