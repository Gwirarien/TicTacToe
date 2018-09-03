#include "stdafx.h"
#include "SplashState.h"

/**
* SplashState::SplashState
* Constructor
* @param GameDataRef dataRef
*/
SplashState::SplashState(GameDataRef dataRef)
	:_data(dataRef)
{
}

/**
* SplashState::initializeState
* Initializes the splash state with the texture
* #return void
*/
void SplashState::initializeState()
{
	this->_data->assets.loadTexture("Backround", SPLASH_SCREEN_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.getTexture("Backround"));
}

/**
* SplashState::inputHandler
* Handles the input
* #return void
*/
void SplashState::inputHandler()
{
	sf::Event event;
	
	//Handle the "close" event
	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
	}
}

/**
* SplashState::update
* Updates the splash when it's changed
* #return void
*/
void SplashState::update(double deltaFrames)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		printf("Go to main menu\n");
	}
}

/**
* SplashState::draw
* Handles the drawings of the objects
* #return void
*/
void SplashState::draw(double deltaFrames)
{
	//Clear the screen
	this->_data->window.clear(sf::Color::Red);
	//Set the background
	this->_data->window.draw(this->_background);
	//Display the changes
	this->_data->window.display();
}