#pragma once

#include <iostream>
#include <string>
#include "SFML\Window.hpp"

namespace LilyTin
{
	class Game
	{
	public:
		Game(std::string title);
		~Game();

		void start();
		void pollEvents();
		void update();
		void finish();

	private:
		float mElapsedTime;

		std::string mTitle;
		sf::Window mWindow;
	};
}