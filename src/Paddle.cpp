#include "Paddle.h"

LilyTin::Paddle::Paddle()
{
}

LilyTin::Paddle::~Paddle()
{
}

void LilyTin::Paddle::start()
{
	sf::Texture texture;
	
	texture.loadFromFile("paddleRed.png");
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

