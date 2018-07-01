#pragma once

#include <iostream>
#include "GameObject.h"
#include "SFML\Graphics.hpp"

namespace LilyTin
{
	class Paddle : public GameObject
	{
	public:
		Paddle();
		~Paddle();
		
		void update();
		void draw();

	private:
		sf::Texture mTexture;
		sf::Sprite mSprite;
	};
}