#pragma once

#ifndef BLEAH_GAMESTATES_PAUSEGAMESTATE_H_
#define BLEAH_GAMESTATES_PAUSEGAMESTATE_H_

#include <vector>

#include "../GameStates/GameState.h"
#include "../objects/GameObject.h"

class PauseGameState : public GameState
{
public:
	PauseGameState();
	~PauseGameState();

	virtual void Update();
	virtual void Render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateId() const;

private:
	static std::string pause_state_id_;	

	static void ResumeButtonCallback();
	static void MenuButtonCallback();

	void SetCallbacks();

	std::vector<GameObject*> m_objects;
	std::vector<std::string> m_TextureIDs;
	std::vector<CallbackFunction> m_Callbacks;
};

class PauseStateCreator : public GameStateCreator
{
public:
	virtual GameState* create();
};

#endif // !BLEAH_GAMESTATES_PAUSEGAMESTATE_H_

