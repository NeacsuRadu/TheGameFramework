#pragma once
#ifndef BLEAH_GAMESTATES_GAMESTATE_H_
#define BLEAH_GAMESTATES_GAMESTATE_H_

#include <iostream>

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


#endif // !GAMESTATES_GAMESTATE_H_

