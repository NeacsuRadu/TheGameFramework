#include "game/Game.h"

const int kFramesPerSecond = 60; 
const int kDelayTime = 1000.0f / kFramesPerSecond;




int main(int argc, char* args[])
{
	unsigned long long frame_start, frame_time;
	Game* game = Game::Instance();

	game->init("First try", 100, 100, 1080, 960, false);

	while (game->running())
	{
		frame_start = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frame_time = SDL_GetTicks();
		if (frame_time < kDelayTime)
		{
			SDL_Delay((int)(kDelayTime - frame_time));
		}
	}

	game->uninit();

	return 0;
}