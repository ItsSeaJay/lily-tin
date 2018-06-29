#include "..\include\Game.h"

LilyTin::Game::Game(std::string title) : mTitle(title)
{
}

LilyTin::Game::~Game()
{
}

void LilyTin::Game::start()
{
	std::cout << mTitle;
	mWindow.create(sf::VideoMode(800, 600), mTitle);
}

void LilyTin::Game::update()
{
	while (mWindow.isOpen())
	{
		sf::Event event;

		// Handle polled events
		while (mWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				mWindow.close();
				break;
			default:
				break;
			}
		}
	}
}

void LilyTin::Game::finish()
{
	std::cout << "Finished";
}
