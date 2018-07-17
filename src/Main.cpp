#include <iostream>
#include "Game.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main(int argc, char* argv[])
{
	LilyTin::Game game("Lily Tin");
	sf::Clock clock;
	sf::Time lag = sf::Time::Zero;
	const sf::Time frameLimit = sf::seconds(1.0f / 60.0f); // 60 FPS limit

	game.start();

	while (game.getWindow().isOpen())
	{
		// Get how much time has elapsed since the game started
		sf::Time elapsedTime = clock.restart();

		// Accumulate lag depending on how long the frame took to render
		lag += elapsedTime;

		// Perform gameplay functions until there is no lag remaining
		while (lag > frameLimit)
		{
			lag -= frameLimit;

			game.pollEvents();
			game.update(frameLimit.asSeconds());
			game.detectCollisions();
		}
		
		game.draw();
	}

	game.finish();

	return EXIT_SUCCESS;
}