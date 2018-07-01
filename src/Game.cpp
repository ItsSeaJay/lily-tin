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
	mObjects.push_back(paddle);

	for (GameObject* object : mObjects)
	{
		object->start();
	}
}

void LilyTin::Game::update(float deltaTime)
{
#ifdef LILYTIN_DEBUG
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		mWindow.close();
	}
#endif

	for (GameObject* object : mObjects)
	{
		object->update(deltaTime);
	}
}

void LilyTin::Game::draw()
{
	mWindow.clear(sf::Color::Black);

	for (GameObject* object : mObjects)
	{
		object->draw(mWindow);
	}

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
