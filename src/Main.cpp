#include <iostream>
#include "Game.h"
#include "SFML\Window.hpp"

int main(int argc, char* argv[])
{
	LilyTin::Game game("Lily Tin");

	game.start();
	game.update();
	game.finish();

	return EXIT_SUCCESS;
}