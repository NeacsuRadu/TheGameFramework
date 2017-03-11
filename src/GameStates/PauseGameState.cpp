#include "../GameStates/PauseGameState.h"

#include "../TextureManager/TextureManager.h"
#include "../game/Game.h"
#include "../objects/Button.h"
#include "../xmlparser/StateParser.h"

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
	
	StateParser* myStateParser = new StateParser();
	bool bResult = myStateParser->parseState("settings\\states.xml", pause_state_id_, &m_objects, &m_TextureIDs);
	if (bResult == false)
	{
		return false;
	}
	
	m_Callbacks.push_back(nullptr);
	m_Callbacks.push_back(ResumeButtonCallback);
	m_Callbacks.push_back(MenuButtonCallback);

	SetCallbacks();

	delete myStateParser;

	return true;
}

void PauseGameState::SetCallbacks()
{
	for (auto it : m_objects)
	{
		Button* button = dynamic_cast<Button*>(it);
		button->SetCallback(m_Callbacks[button->GetCallbackID()]);
	}
}

bool PauseGameState::onExit()
{
	std::cout << "Exiting pause game state" << std::endl;
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

void PauseGameState::MenuButtonCallback()
{
	Game::Instance()->GetGameStateMachine()->SetNextState("menu");
}

//
//			PAUSE STATE CREATOR 
//

GameState* PauseStateCreator::create()
{
	return new PauseGameState();
}