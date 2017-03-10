#include "../GameStates/PlayGameState.h"

#include <iostream>

#include "../game/Game.h"
#include "../objects/SDLGameObject.h"

std::string PlayGameState::game_state_id_ = "PLAY";

PlayGameState::PlayGameState()
{

}

PlayGameState::~PlayGameState()
{

}

void PlayGameState::Render()
{
	for (auto it : m_objects)
	{
		it->draw();
	}
}

void PlayGameState::Update()
{
	for (auto it : m_objects)
	{
		it->update();
	}
}

bool PlayGameState::onEnter()
{
	std::cout << "Entering play game state" << std::endl;
	GameObject* object;

	TextureManager::Instance()->load("min", "..\\images\\min.png");
	object = Game::Instance()->GetGameObjectFactory()->Create("min");
	object->load(new LoaderParams(10, 10, 400, 400, "min"));
	m_objects.push_back(object);
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


GameState* PlayStateCreator::create()
{
	return new PlayGameState();
}