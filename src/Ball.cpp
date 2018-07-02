#include "Ball.h"

LilyTin::Ball::Ball()
{
}

LilyTin::Ball::~Ball()
{
}

void LilyTin::Ball::start()
{
	mTexture.loadFromFile("../res/png/ballGrey.png");
	mSprite.setTexture(mTexture);
	// Set the origin to the center of the sprite
	mSprite.setOrigin
	(
		mSprite.getLocalBounds().width / 2.0f, // X
		mSprite.getLocalBounds().height / 2.0f // Y
	);

	// Make the ball move upwards
	mVelocity = sf::Vector2f(0.0f, 1.0f);
}

void LilyTin::Ball::update(float deltaTime)
{
	mTransform.move(mVelocity * mSpeed * deltaTime);
}

void LilyTin::Ball::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mSprite.setPosition(mTransform.getPosition());
}
