#pragma once

#include "Game.h"

LilyTin::Game::Game(const std::string& title) : mTitle(title)
{
	// Create a new window
	mWindow.create(sf::VideoMode(1024, 576), mTitle, sf::Style::Default);

	// Add a paddle to the game
	Paddle* paddle = new Paddle();
	paddle->getTransform().setPosition(mWindow.getSize().x / 2.0f, mWindow.getSize().y - 32.0f);
	mObjects.push_back(paddle);

	// Add a ball to the game
	Ball* ball = new Ball();
	mObjects.push_back(ball);
	ball->getTransform().setPosition(mWindow.getSize().x / 2.0f, mWindow.getSize().y / 2.0f);
}

LilyTin::Game::~Game()
{
}

void LilyTin::Game::start()
{
	for (GameObject* object : mObjects)
	{
		object->start();
	}
}

void LilyTin::Game::update(float deltaTime)
{
	for (GameObject* object : mObjects)
	{
		object->update(deltaTime);
	}
}

void LilyTin::Game::detectCollisions()
{
	for (int first = 0; first < mObjects.size(); ++first)
	{
		for (int second = first + 1; second < mObjects.size(); ++second)
		{
			// If the first object is colliding with the second object but not
			// colliding with itself
			if (mObjects[first]->getBoundingBox().intersects(mObjects[second]->getBoundingBox()))
			{
				mObjects.[first]->collision();
				mObjects.[second]->collision();
			}
		}
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
		case sf::Event::Resized:
			// Update the view to the new size of the window
			sf::FloatRect visibleArea(0, 0, float(event.size.width), float(event.size.height));
			mWindow.setView(sf::View(visibleArea));
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
