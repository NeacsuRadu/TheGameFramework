#include "../GameStates/MenuGameState.h"

#include <iostream>

#include "../TextureManager/TextureManager.h"
#include "../objects/Button.h"
#include "../GameStates/PlayGameState.h"
#include "../xmlparser/StateParser.h"

std::string MenuGameState::game_state_id_ = "MENU";

MenuGameState::MenuGameState()
{
}

MenuGameState::~MenuGameState()
{
}

void MenuGameState::Render()
{
	for (auto it = 0; it != game_objects_.size(); ++it)
	{
		game_objects_[it]->draw();
	}
}

void MenuGameState::Update()
{
	for (auto it = 0; it != game_objects_.size(); ++it)
	{
		game_objects_[it]->update();
	}
}

bool MenuGameState::onEnter()
{
	StateParser* myStateParser = new StateParser();

	bool bResult = myStateParser->parseState("settings\\states.xml", game_state_id_, &game_objects_, &m_TextureIDs);

	if (!bResult)
		return false;

	m_Callbacks.push_back(nullptr);
	m_Callbacks.push_back(PlayButtonCallBack);
	m_Callbacks.push_back(QuitButtonCallBack);

	SetCallbacks();
	
	delete myStateParser;

	std::cout << "Entering menu game state" << std::endl;
	return true;
}

bool MenuGameState::onExit()
{
	std::cout << "Exiting menu game state" << std::endl;
	for (unsigned it = 0; it < game_objects_.size(); ++it)
	{
		game_objects_[it]->clean();
		delete game_objects_[it];
		game_objects_[it] = nullptr;
	}
	game_objects_.clear();
	return true;
}

std::string MenuGameState::getStateId() const
{
	return game_state_id_;
}

void MenuGameState::PlayButtonCallBack()
{
	Game::Instance()->GetGameStateMachine()->SetNextState("play");
}

void MenuGameState::QuitButtonCallBack()
{
	Game::Instance()->quit();
}

void MenuGameState::SetCallbacks()
{
	for (auto it : game_objects_)
	{
		Button* button = dynamic_cast<Button*>(it);
		if (button != nullptr)
		{
			button->SetCallback(m_Callbacks[button->GetCallbackID()]);
		}
	}
}

//
//			MENU STATE CREATOR 
//

GameState* MenuStateCreator::create()
{
	return new MenuGameState();
}