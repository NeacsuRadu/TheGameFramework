#pragma once
#ifndef BLEAH_GAMESTATES_GAMESTATE_H_
#define BLEAH_GAMESTATES_GAMESTATE_H_

#include <iostream>
#include <map>

class GameState
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateId() const = 0;

	virtual ~GameState() {};
};

class GameStateCreator
{
public:
	virtual GameState* create() = 0;
	virtual ~GameStateCreator() {};
};

class GameStateFactory
{
public:
	bool Register(std::string creatorId, GameStateCreator* creator);
	GameState* Create(std::string creatorId);
	~GameStateFactory();
private:
	std::map<std::string, GameStateCreator*> m_creators;
};
#endif // !GAMESTATES_GAMESTATE_H_

