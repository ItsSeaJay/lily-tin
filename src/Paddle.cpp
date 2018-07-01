#include "Paddle.h"

LilyTin::Paddle::Paddle()
{
}

LilyTin::Paddle::~Paddle()
{
}

void LilyTin::Paddle::start()
{
	mTexture.loadFromFile("../res/PNG/paddleRed.png");
	mSprite.setTexture(mTexture);
	mTransform.setPosition(300, 300);
}

void LilyTin::Paddle::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mTransform.move(-128.0f * deltaTime, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mTransform.move(128.0f * deltaTime, 0.0f);
	}
}

void LilyTin::Paddle::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mSprite.setPosition(mTransform.getPosition());
}

