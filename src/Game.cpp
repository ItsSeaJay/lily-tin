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
}

void LilyTin::Game::update()
{
	// Update all the game objects
}

void LilyTin::Game::render()
{
	mWindow.clear(sf::Color::Black);
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
	std::cout << "Finished";
}

const sf::RenderWindow& LilyTin::Game::getWindow()
{
	return mWindow;
}
