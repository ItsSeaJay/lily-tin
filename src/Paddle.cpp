#include "Paddle.h"

LilyTin::Paddle::Paddle()
{
}

LilyTin::Paddle::~Paddle()
{
}

void LilyTin::Paddle::start()
{
	mTexture.loadFromFile("../res/png/paddleRed.png");
	mSprite.setTexture(mTexture);
	mSprite.setOrigin
	(
		mSprite.getLocalBounds().width / 2.0f, // X
		mSprite.getLocalBounds().height / 2.0f // Y
	);
}

void LilyTin::Paddle::update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mVelocity = sf::Vector2f(-1.0f, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mVelocity = sf::Vector2f(1.0f, 0.0f);
	}
	else
	{
		mVelocity = sf::Vector2f(0.0f, 0.0f);
	}

	mTransform.move(mVelocity * mSpeed * deltaTime);
}

void LilyTin::Paddle::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mSprite.setPosition(mTransform.getPosition());
}

