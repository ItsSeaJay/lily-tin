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
		LilyTin::Paddle::Paddle(sf::Vector2f position);
		~Paddle();
		
		void start();
		void update(float deltaTime);
		void draw(sf::RenderWindow& window);

	private:
		float speed = 1.6f;

		sf::Texture mTexture;
		sf::Sprite mSprite;
		sf::Vector2f mVelocity;
	};
}