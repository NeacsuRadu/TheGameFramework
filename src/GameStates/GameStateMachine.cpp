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
	// TO DO: DE FACUT O NOUA METODA PRIVATA CARE SA FACA MANAGE LA CACATURILE ASTEA DE MAI JOS 
	if (next_state_ == "pop")
	{
		next_state_ = "none";
		PopState();
	}
	else if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_P))
	{
		PushState(Game::Instance()->GetGameStateFactory()->Create("pause"));
	} 
	else if (next_state_ != "none")
	{
		if(game_states_container_.back()->getStateId() != "PAUSE")
			ChangeState(Game::Instance()->GetGameStateFactory()->Create(next_state_));
		else
		{
			std::cout << "Din pause in alta" << std::endl;
			PopState();
			ChangeState(Game::Instance()->GetGameStateFactory()->Create(next_state_));
		}
		next_state_ = "none";
	}
}

void GameStateMachine::PopState()
{
	if (!game_states_container_.empty())
	{
		if (game_states_container_.back()->onExit())
		{
			delete game_states_container_.back();
			game_states_container_.pop_back();
		}
	}
}

void GameStateMachine::PushState(GameState* game_state)
{
	if (!game_states_container_.empty() && game_state->getStateId() == game_states_container_.back()->getStateId())
		return;
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
