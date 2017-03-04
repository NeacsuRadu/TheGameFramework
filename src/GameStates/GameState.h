#pragma once
#ifndef BLEAH_GAMESTATES_GAMESTATE_H_
#define BLEAH_GAMESTATES_GAMESTATE_H_

#include <iostream>

class GameState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;

	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;

	virtual std::string getStateId() const = 0;

};


#endif // !GAMESTATES_GAMESTATE_H_

