#pragma once
#ifndef BLEAH_GAME_GAME_H_
#define BLEAH_GAME_GAME_H_

#include <iostream>
#include <vector>

#include "../../include/SDL.h"

#include "../objects/SDLGameObject.h"
#include "../GameStates/GameStateMachine.h"
#include "../GameStates/MenuGameState.h"
#include "../GameStates/PlayGameState.h"

class Game
{
public:
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void uninit();
	void quit();
	bool running();
	GameStateMachine* GetGameStateMachine();

	SDL_Renderer* getRenderer();

	static Game* Instance();
private:
	Game();

	static Game* m_pInstance;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	GameStateMachine* game_state_machine_;

};
#endif


