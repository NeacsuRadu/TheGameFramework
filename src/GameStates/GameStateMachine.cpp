#include "../GameStates/GameStateMachine.h"

GameStateMachine::GameStateMachine()
{

}

GameStateMachine::~GameStateMachine()
{

}

void GameStateMachine::Render()
{
	game_states_container_.back()->Render();
}

void GameStateMachine::Update()
{
	game_states_container_.back()->Update();
}

void GameStateMachine::PopState()
{
	if (!game_states_container_.empty())
	{
		if (!game_states_container_.back()->onExit())
		{
			delete game_states_container_.back();
			game_states_container_.pop_back();
		}
	}
}

void GameStateMachine::PushState(GameState* game_state)
{
	game_states_container_.push_back(game_state);
	game_states_container_.back()->onEnter();
}

void GameStateMachine::ChangeState(GameState* game_state)
{
	if (!game_states_container_.empty())
	{
		if (game_states_container_.back()->getStateId() == game_state->getStateId())
		{
			return;
		}

		if (game_states_container_.back()->onExit())
		{
			delete game_states_container_.back();
			game_states_container_.pop_back();
		}
	}

	game_states_container_.push_back(game_state);
	game_states_container_.back()->onEnter();
}

