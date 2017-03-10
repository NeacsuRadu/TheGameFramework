#include "Game.h"

#include "../objects/Button.h"
#include "../GameStates/MenuGameState.h"
#include "../GameStates/PlayGameState.h"
#include "../GameStates/PauseGameState.h"

Game* Game::m_pInstance = nullptr;

Game::Game() :
	m_bRunning(false)
{
}

Game::~Game()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
	}
}

Game* Game::Instance()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new Game();
	}
	return m_pInstance;
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	bool flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success" << std::endl;
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != nullptr)
		{
			std::cout << "Window creation successfull" << std::endl;
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			if (m_pRenderer != nullptr)
			{
				std::cout << "Renderer creation successful" << std::endl;
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else
			{
				std::cout << "Creation of renderer failed" << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << "Creation of window failed" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "SDL init failed" << std::endl;
		return false;
	}

	game_object_factory_ = new GameObjectFactory();
	game_object_factory_->Register("button", new ButtonCreator());
	game_object_factory_->Register("min", new RandomCreator());

	game_state_factory_ = new GameStateFactory();
	game_state_factory_->Register("menu", new MenuStateCreator());
	game_state_factory_->Register("play", new PlayStateCreator());
	game_state_factory_->Register("pause", new PauseStateCreator());

	game_state_machine_ = new GameStateMachine();
	game_state_machine_->PushState(game_state_factory_->Create("menu"));

	m_bRunning = true;

	return true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
	SDL_RenderClear(m_pRenderer);

	game_state_machine_->Render();

	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	game_state_machine_->Update();
}

void Game::handleEvents()
{
	InputManager::Instance()->update();

	if (InputManager::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		game_state_machine_->ChangeState(new PlayGameState());
	}
}

void Game::uninit()
{
	std::cout << "Uninitialize things" << std::endl;
	delete game_state_machine_;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

bool Game::running()
{
	return m_bRunning;
}

SDL_Renderer* Game::getRenderer()
{
	return m_pRenderer;
}

void Game::quit()
{
	m_bRunning = false;
}

GameStateMachine* Game::GetGameStateMachine() const
{
	return game_state_machine_;
}

GameObjectFactory* Game::GetGameObjectFactory() const
{
	return game_object_factory_;
}

GameStateFactory* Game::GetGameStateFactory() const
{
	return game_state_factory_;
}




