#pragma once

#ifndef BLEAH_GAMESTATES_MENUGAMESTATE_H_
#define BLEAH_GAMESTATES_MENUGAMESTATE_H_

#include <Windows.h>
#include <vector>

#include "../GameStates/GameState.h"
#include "../objects/GameObject.h"

class MenuGameState : public GameState
{
public:
	MenuGameState();
	virtual ~MenuGameState();

	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const;
private:
	static std::string game_state_id_;

	static void PlayButtonCallBack();
	static void QuitButtonCallBack();

	std::vector<GameObject*> game_objects_;
};

class MenuStateCreator : public GameStateCreator
{
	virtual GameState* create();
};

#endif // !BLEAH_GAMESTATES_MENUGAMESTATE_H_

