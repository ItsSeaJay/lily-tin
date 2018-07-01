#pragma once

#include <iostream>
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "SFML\Window.hpp"

namespace LilyTin
{
	class Paddle : public GameObject
	{
	public:
		Paddle();
		~Paddle();
		
		void start();
		void update();
		void draw(sf::RenderWindow& window);

	private:
		sf::Texture mTexture;
		sf::Sprite mSprite;

	};
}