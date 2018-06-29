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
		void update();
		void finish();

	private:
		std::string mTitle;
		sf::Window mWindow;
	};
}