#include <iostream>
#include "Game.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

int main(int argc, char* argv[])
{
	LilyTin::Game game("Lily Tin");
	sf::Clock clock;

	game.start();

	while (game.getWindow().isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		game.pollEvents();
		game.update(deltaTime);
		game.draw();
	}

	game.finish();

	return EXIT_SUCCESS;
}