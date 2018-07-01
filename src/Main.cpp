#include <iostream>
#include "Game.h"
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"

int main(int argc, char* argv[])
{
	LilyTin::Game game("Lily Tin");
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time frameLimit = sf::seconds(1.0f / 60.0f); // 60 frames per second

	game.start();

	while (game.getWindow().isOpen())
	{
		sf::Time elapsedTime = clock.restart();

		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > frameLimit)
		{
			timeSinceLastUpdate -= frameLimit;

			game.pollEvents();
			game.update(frameLimit.asSeconds());
		}
		
		game.draw();
	}

	game.finish();

	return EXIT_SUCCESS;
}