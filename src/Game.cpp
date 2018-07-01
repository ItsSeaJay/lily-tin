#pragma once

#include "Game.h"

LilyTin::Game::Game(const std::string& title) : mTitle(title)
{
}

LilyTin::Game::~Game()
{
}

void LilyTin::Game::start()
{
	mWindow.create(sf::VideoMode(800, 600), mTitle);

	Paddle* paddle = new Paddle();
	mObjects.push_back(new Paddle());

	for (GameObject* object : mObjects)
	{
		object->start();
	}

	mTexture.loadFromFile("../res/PNG/paddleRed.png");
	mSprite.setTexture(mTexture);
}

void LilyTin::Game::update()
{
#ifdef LILYTIN_DEBUG
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		mWindow.close();
	}
#endif

	for (GameObject* object : mObjects)
	{
		object->update();
	}
}

void LilyTin::Game::draw()
{
	mWindow.clear(sf::Color::Black);

	for (GameObject* object : mObjects)
	{
		object->draw();
	}

	mWindow.draw(mSprite);

	mWindow.display();
}

void LilyTin::Game::pollEvents()
{
	sf::Event event;

	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
}

void LilyTin::Game::finish()
{
	std::cout << "Game Over";

	// Free the memory of all allocated game objects
	for (GameObject* object : mObjects)
	{
		delete object;
		object = nullptr;
	}
}

const sf::RenderWindow& LilyTin::Game::getWindow()
{
	return mWindow;
}
