#include "stdafx.h"
#include "SplashState.h"

SplashState::SplashState(GameDataRef dataRef)
	:_data(dataRef)
{}

void SplashState::initializeState()
{
	this->_data->assets.loadTexture("SplashBackground", SPLASH_SCREEN_BACKGROUND_FILEPATH);
	_background.setTexture(this->_data->assets.getTexture("SplashBackground"));
}

void SplashState::inputHandler()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		//Handle the "close" event
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
	}
}

void SplashState::update(double deltaFrames)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		//Main switch
		this->_data->machine.addState(StateReference(new MainMenuState(_data)), true);
	}
}

void SplashState::draw(double deltaFrames)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}
