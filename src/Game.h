#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObject.h"
#include "Paddle.h"

namespace LilyTin
{
	class Game
	{
	public:
		Game(const std::string& title);
		~Game();

		void start();
		void pollEvents();
		void update(float deltaTime);
		void draw();
		void finish();

		const sf::RenderWindow& getWindow();

	private:
		std::string mTitle;
		sf::RenderWindow mWindow;
		std::vector<GameObject*> mObjects;
	};
}