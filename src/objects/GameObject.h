#pragma once

#ifndef BLEAH_OBJECTS_GAMEOBJECT_H_
#define BLEAH_OBJECTS_GAMEOBJECT_H_

#include <iostream>
#include <map>

#include "../../include/SDL.h"

typedef void(*CallbackFunction)();

struct LoaderParams
{
	LoaderParams(int x, int y, int width, int height, std::string texture_id, CallbackFunction func = 0) :
		x(x), y(y), width(width), height(height), texture_id(texture_id), func(func) {}
	int x;
	int y;
	int width;
	int height;
	std::string texture_id;
	CallbackFunction func;
};



class GameObject
{
public:
	
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void clean() = 0;
	virtual void load(LoaderParams* pParams) = 0;
	virtual ~GameObject() {};
protected:

	GameObject() {};
};

class GameObjectCreator
{
public:
	virtual GameObject* CreateGameObject() = 0;
	virtual ~GameObjectCreator() { }
};

class GameObjectFactory
{
public:
	bool Register(std::string creatorId, GameObjectCreator* creator);
	GameObject* Create(std::string creatorId);
	~GameObjectFactory();
private:
	std::map<std::string, GameObjectCreator*> m_creators;
};

#endif
