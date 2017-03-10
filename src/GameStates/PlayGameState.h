#pragma once
#ifndef BLEAH_GAMESTATES_PLAYGAMESTATE_H_
#define BLEAH_GAMESTATES_PLAYGAMESTATE_H_

#include <vector>

#include "../GameStates/GameState.h"
#include "../objects/GameObject.h"

class PlayGameState : public GameState
{
public:
	PlayGameState();
	virtual ~PlayGameState();

	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const;
private:
	static std::string game_state_id_;

	std::vector<GameObject*> m_objects;
};

class PlayStateCreator : public GameStateCreator
{
public:
	virtual GameState* create();
	virtual ~PlayStateCreator() {}
};

#endif // !BLEAH_GAMESTATES_PLAYGAMESTATE_H_

