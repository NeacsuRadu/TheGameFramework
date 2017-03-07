#include "../GameStates/GameStateMachine.h"

#include "../game/Game.h"

GameStateMachine::GameStateMachine() :
	next_state_(std::string("none"))
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
	if (next_state_ != "none")
	{
		ChangeState(Game::Instance()->GetGameStateFactory()->Create(next_state_));
		next_state_ = "none";
	}
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

void GameStateMachine::SetNextState(std::string next_state)
{
	next_state_ = next_state;
}
