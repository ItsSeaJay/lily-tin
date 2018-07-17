#include "Paddle.h"

LilyTin::Paddle::Paddle()
{
}

LilyTin::Paddle::~Paddle()
{
}

void LilyTin::Paddle::start()
{
	mTexture.loadFromFile("res/png/paddleRed.png");
	mSprite.setTexture(mTexture);
}

void LilyTin::Paddle::update(float deltaTime)
{
	bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::D);

	if (left)
	{
		mVelocity = sf::Vector2f(-1.0f, 0.0f);
	}
	else if (right)
	{
		mVelocity = sf::Vector2f(1.0f, 0.0f);
	}
	else
	{
		mVelocity = sf::Vector2f(0.0f, 0.0f);
	}

	mTransform.move(mVelocity * mSpeed * deltaTime);
}

void LilyTin::Paddle::collision()
{

}

void LilyTin::Paddle::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mSprite.setPosition(mTransform.getPosition());
}

