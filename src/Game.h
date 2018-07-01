#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "GameObject.h"

namespace LilyTin
{
	class Game
	{
	public:
		Game(const std::string& title);
		~Game();

		void start();
		void pollEvents();
		void update();
		void render();
		void finish();

		const sf::RenderWindow& getWindow();

	private:
		std::string mTitle;
		sf::RenderWindow mWindow;
		std::vector<GameObject*> mObjects;

	};
}