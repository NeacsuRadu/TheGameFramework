#include "../GameStates/PlayGameState.h"

#include <iostream>

std::string PlayGameState::game_state_id_ = "PLAY";

PlayGameState::PlayGameState()
{

}

PlayGameState::~PlayGameState()
{

}

void PlayGameState::Render()
{

}

void PlayGameState::Update()
{

}

bool PlayGameState::onEnter()
{
	std::cout << "Entering play game state" << std::endl;
	return true;
}

bool PlayGameState::onExit()
{
	std::cout << "Exiting play game state" << std::endl;
	return true;
}

std::string PlayGameState::getStateId() const
{
	return game_state_id_;
}