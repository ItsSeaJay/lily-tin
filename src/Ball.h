#pragma once

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
		float mSpeed = 256.0f;

		sf::Texture mTexture;
		sf::Sprite mSprite;
		sf::Vector2f mVelocity;

	};
}