#pragma once
#ifndef BLEAH_GAME_GAME_H_
#define BLEAH_GAME_GAME_H_

#include "../../include/SDL.h"

class Game
{
public:
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void uninit();

	bool running();

	static Game* Instance();
private:
	Game();

	static Game* m_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
};
#endif


