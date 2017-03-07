#pragma once
#ifndef BLEAH_GAMESTATES_GAMESTATEMACHINE_H_
#define BLEAH_GAMESTATES_GAMESTATEMACHINE_H_

#include <vector>

#include "../GameStates/GameState.h"

class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	void ChangeState(GameState* game_state);
	void PushState(GameState* game_state);
	void PopState();

	void Render();
	void Update();

	void SetNextState(std::string next_state);
private:
	std::vector<GameState*> game_states_container_;
	std::string next_state_;
};

#endif // !BLEAH_GAMESTATES_GAMESTATEMACHINE_H_
