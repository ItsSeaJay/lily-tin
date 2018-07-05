#pragma once

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Transformable.hpp"

namespace LilyTin
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void start() = 0;
		virtual void update(float deltaTime) = 0;
		virtual void draw(sf::RenderWindow& window) = 0;

		sf::Transformable& getTransform();

	protected:
		bool mDestroyed = false;
		sf::Transformable mTransform;
	};
}