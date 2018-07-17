#include "Ball.h"

LilyTin::Ball::Ball()
{
}

LilyTin::Ball::~Ball()
{
}

void LilyTin::Ball::start()
{
	mTexture.loadFromFile("res/png/ballGrey.png");
	mSprite.setTexture(mTexture);
	// Set the origin to the center of the sprite
	mSprite.setOrigin
	(
		mSprite.getLocalBounds().width / 2.0f, // X
		mSprite.getLocalBounds().height / 2.0f // Y
	);

	// Make the ball move upwards and to the right
	mVelocity = sf::Vector2f(64.0f, -64.0f);
}

void LilyTin::Ball::update(float deltaTime)
{
	// Apply gravity to the ball
	if (mVelocity.y < mTerminalVelocity)
	{
		mVelocity.y += mGravity;
	}

	// Bounce right if the ball hits the left side
	if (mTransform.getPosition().x < mSprite.getLocalBounds().width / 2)
	{
		mVelocity.x *= -1.0f;
	}

	// Bounce left if the ball hits the right side
	// TODO: Make this change depending on the width of the window
	if (mTransform.getPosition().x > 1024)
	{
		mVelocity.x *= -1.0f;
	}

	// Bounce if the ball hits the bottom of the window
	// TODO: Make this sensitive to the height of the window
	if (mTransform.getPosition().y > (576 - 16))
	{
		mVelocity.y *= -mRestitution.ground;
	}

	mTransform.move(mVelocity * deltaTime);
}

void LilyTin::Ball::collision()
{
	
}

void LilyTin::Ball::draw(sf::RenderWindow& window)
{
	window.draw(mSprite);
	mSprite.setPosition(mTransform.getPosition());
}
