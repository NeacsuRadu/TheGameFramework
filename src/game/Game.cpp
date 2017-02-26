#include "Game.h"

#include <iostream>

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

	m_bRunning = true;

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{

}

void Game::handleEvents()
{
	SDL_Event ev;
	if (SDL_PollEvent(&ev))
	{
		switch (ev.type)
		{
			case SDL_QUIT:
			{
				m_bRunning = false;
				break;
			}

			default:
				break;
		}
	}
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




