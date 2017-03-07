#include "../GameStates/MenuGameState.h"

#include <iostream>

#include "../TextureManager/TextureManager.h"
#include "../objects/Button.h"
#include "../GameStates/PlayGameState.h"

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
	std::cout << "Entering menu game state" << std::endl;

	TextureManager::Instance()->load("play_button", "..\\images\\play.png");
	game_objects_.push_back(new Button(new LoaderParams(10, 10, 300, 100, "play_button"), PlayButtonCallBack));

	TextureManager::Instance()->load("quit_button", "D:\\MDS\\Bleah\\images\\quit.png");
	game_objects_.push_back(new Button(new LoaderParams(10, 400, 300, 100, "quit_button"), QuitButtonCallBack));
	
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
	Game::Instance()->GetGameStateMachine()->ChangeState(new PlayGameState());
}

void MenuGameState::QuitButtonCallBack()
{
	Game::Instance()->quit();
}