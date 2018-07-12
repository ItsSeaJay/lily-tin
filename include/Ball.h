#pragma once

#include <iostream>
#include "GameObject.h"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

namespace LilyTin
{
	class Ball : public GameObject
	{
	public:
		Ball();
		~Ball();

		void start();
		void update(float deltaTime);
		void draw(sf::RenderWindow& window);

	private:
		const float mGravity = 2.0f;
		const float mRestitution = 1.0f;
		const float mTerminalVelocity = 256.0f;

		sf::Texture mTexture;
		sf::Sprite mSprite;
		sf::Vector2f mVelocity;
	};
}