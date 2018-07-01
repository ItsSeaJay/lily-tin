#include "Paddle.h"

LilyTin::Paddle::Paddle()
{
}

LilyTin::Paddle::~Paddle()
{
}

void LilyTin::Paddle::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		std::cout << "Left";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		std::cout << "Right";
	}
}

void LilyTin::Paddle::draw()
{

}

