#include "stdafx.h"
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"

/**
* GameState::GameState
* Constructor
* @param GameDataRef dataRef
*/
GameState::GameState(GameDataRef dataRef)
	:_data(dataRef)
{
}

/**
* GameState::initializeState
* Initializes the splash state with the texture
* #return void
*/
void GameState::initializeState()
{
	_gameState = STATE_PLAYING;
	_turn = PLAYER_PIECE;

	this->_data->assets.loadTexture("PauseButton", GAME_PAUSE_BUTTON);
	_background.setTexture(this->_data->assets.getTexture("MainMenuBackground"));
	_pauseButton.setTexture(this->_data->assets.getTexture("PauseButton"));

	//Position the pause button
	_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getLocalBounds().width, _pauseButton.getPosition().y);
}

/**
* GameState::inputHandler
* Handles the input
* #return void
*/
void GameState::inputHandler()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		//Handle the "close" event
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		//Handle the "pause" event
		if (this->_data->input.isSpriteClicked(this->_pauseButton, sf::Mouse::Left, this->_data->window))
		{
			//this->_data->machine.addState(StateReference(new PauseState(_data)), false);
			this->_data->machine.addState(StateReference(new GameOverState(_data)), true);
		}
	}
}

/**
* GameState::update
* Updates the splash when it's changed
* @param double deltaFrames
* #return void
*/
void GameState::update(double deltaFrames)
{
}

/**
* GameState::draw
* Handles the drawings of the objects
* @param double deltaFrames
* #return void
*/
void GameState::draw(double deltaFrames)
{
	//Clear the screen
	this->_data->window.clear(sf::Color::Red);
	//Set the background and button
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_pauseButton);
	//Display the changes
	this->_data->window.display();
}
