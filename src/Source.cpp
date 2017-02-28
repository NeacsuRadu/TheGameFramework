/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "game\\Game.h"

//Screen dimension constants


int main(int argc, char* args[])
{
	Game* game = Game::Instance();

	game->init("First try", 100, 100, 640, 480, 0);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->uninit();

	return 0;
}