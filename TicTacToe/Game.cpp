#include "stdafx.h"
#include "Game.h"
#include "SplashState.h"

/**
* Game::Game
* Constructor
* @param int screenWidth
* @param int screenHeight
* @param std::string title
*/
Game::Game(int screenWidth, int screenHeight, const std::string title)
{
	//Creating the render window; sf::Style::Close, sf::Style::Titlebar means that 
	//the window will contain a close button and a title bar
	_data->window.create(sf::VideoMode(screenWidth, screenHeight), title, sf::Style::Close | sf::Style::Titlebar);
	//Load the initial state 
	_data->machine.addState(StateReference(new SplashState(this->_data)));

	this->run();
}

/**
* Game::run
* Called when the game is running
* #return void
*/
void Game::run()
{
	double newTime;
	double frameTime;
	double interpolation;
	//The amount of time that has elapsed since the clock started
	double currentTime = this->_clock.getElapsedTime().asSeconds();
	double accumulator = 0;

	while (this->_data->window.isOpen())
	{
		this->_data->machine.processStateChanges();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		//Restricting the framerate
		if (frameTime > 0.25)
		{
			frameTime = 0.25;
		}

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= deltaTime)
		{
			this->_data->machine.getActiveState()->inputHandler();
			this->_data->machine.getActiveState()->update(deltaTime);

			accumulator -= deltaTime;
		}

		//Finding intermediary values
		interpolation = accumulator / deltaTime;
		this->_data->machine.getActiveState()->draw(interpolation);
	}
}
