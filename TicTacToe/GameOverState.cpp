#include "stdafx.h"
#include "GameOverState.h"
#include "GameState.h"

/**
* GameOverState::GameOverState
* Constructor
* @param GameDataRef dataRef
*/
GameOverState::GameOverState(GameDataRef dataRef)
	:_data(dataRef)
{
}

/**
* GameOverState::initializeState
* Initializes the splash state with the texture
* #return void
*/
void GameOverState::initializeState()
{
	for (int i = 0; i < _textureNames.size(); i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "RetryButton")
		{
			//Set the texture
			_retryButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_retryButton.setPosition((this->_data->window.getSize().x / 2) - (this->_retryButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3) - (this->_retryButton.getLocalBounds().height / 2));
			continue;
		}

		if (_textureNames[i] == "HomeButton")
		{
			//Set the texture
			_homeButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
			continue;
		}
	}
}

/**
* GameOverState::inputHandler
* Handles the input
* #return void
*/
void GameOverState::inputHandler()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		//Handle the "close" event
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		//Handle the "retry" event
		if (this->_data->input.isSpriteClicked(this->_retryButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.addState(StateReference(new GameState(_data)), true);
		}

		//Handle the "home" event
		if (this->_data->input.isSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.removeState();
			this->_data->machine.addState(StateReference(new MainMenuState(_data)), true);
		}
	}
}

/**
* GameOverState::update
* Updates the splash when it's changed
* @param double deltaFrames
* #return void
*/
void GameOverState::update(double deltaFrames)
{
}

/**
* GameOverState::draw
* Handles the drawings of the objects
* @param double deltaFrames
* #return void
*/
void GameOverState::draw(double deltaFrames)
{
	//Clear the screen
	this->_data->window.clear(sf::Color::Blue);
	//Set the buttons
	this->_data->window.draw(this->_retryButton);
	this->_data->window.draw(this->_homeButton);
	//Display the changes
	this->_data->window.display();
}
