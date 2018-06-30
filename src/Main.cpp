#include <iostream>
#include "Game.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

int main(int argc, char* argv[])
{
	LilyTin::Game game("Lily Tin");

	game.start();

	while (game.getWindow().isOpen())
	{
		game.pollEvents();
		game.update();
		game.render();
	}

	game.finish();

	return EXIT_SUCCESS;
}