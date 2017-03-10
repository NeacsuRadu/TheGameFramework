#include "../GameStates/PauseGameState.h"

#include "../TextureManager/TextureManager.h"
#include "../game/Game.h"


std::string PauseGameState::pause_state_id_ = "PAUSE";

PauseGameState::PauseGameState()
{

}

PauseGameState::~PauseGameState()
{

}

std::string PauseGameState::getStateId() const
{
	return pause_state_id_;
}

void PauseGameState::Update()
{
	for (auto it : m_objects)
	{
		it->update();
	}
}

void PauseGameState::Render()
{
	for (auto it : m_objects)
	{
		it->draw();
	}
}

bool PauseGameState::onEnter()
{
	std::cout << "Entering pause game state" << std::endl;
	GameObject* object;

	TextureManager::Instance()->load("resume_button", "..\\images\\resume.png");
	object = Game::Instance()->GetGameObjectFactory()->Create("button");
	object->load(new LoaderParams(10, 10, 300, 100, "resume_button", ResumeButtonCallback));
	m_objects.push_back(object);

	/*TextureManager::Instance()->load("quit_button", "..\\images\\quit.png");
	object = Game::Instance()->GetGameObjectFactory()->Create("button");
	object->load(new LoaderParams(10, 400, 300, 100, "quit_button", MenuButtonCallback));
	m_objects.push_back(object);*/

	return true;
}

bool PauseGameState::onExit()
{
	for (auto it : m_objects)
	{
		it->clean();
		delete it;
	}
	m_objects.clear();
	return true;
}

void PauseGameState::ResumeButtonCallback()
{
	Game::Instance()->GetGameStateMachine()->SetNextState("pop");
}



GameState* PauseStateCreator::create()
{
	return new PauseGameState();
}