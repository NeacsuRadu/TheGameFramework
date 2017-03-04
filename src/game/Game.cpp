#include "Game.h"

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

	TextureManager::Instance()->load(std::string("img"), std::string("D:\\MDS\\Bleah\\images\\min.png"));
	m_gameObjects.push_back(new SDLGameObject(new LoaderParams(0, 0, 200, 200, "img")));

	m_bRunning = true;

	return true;
}

void Game::render()
{
	SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
	SDL_RenderClear(m_pRenderer);

	for (auto it = 0; it != m_gameObjects.size(); ++it)
	{
		m_gameObjects[it]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	for (auto it = 0; it != m_gameObjects.size(); ++it)
	{
		m_gameObjects[it]->update();
	}
}

void Game::handleEvents()
{
	InputManager::Instance()->update();
}

void Game::uninit()
{
	std::cout << "Uninitialize things" << std::endl;
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



