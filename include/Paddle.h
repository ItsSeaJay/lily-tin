#pragma once

#include <iostream>
#include <string>
#include "GameObject.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window.hpp"

namespace LilyTin
{
	class Paddle : public GameObject
	{
	public:
		Paddle();
		~Paddle();
		
		void start();
		void update(float deltaTime);
		void collision();
		void draw(sf::RenderWindow& window);

	private:
		float mSpeed = 256.0f;

		sf::Texture mTexture;
		sf::Sprite mSprite;
		sf::Vector2f mVelocity;
	};
}