#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"

/**
* MainMenuState::MainMenuState
* Constructor
* @param GameDataRef dataRef
*/
MainMenuState::MainMenuState(GameDataRef dataRef)
	:_data(dataRef)
{
}

/**
* MainMenuState::initializeState
* Initializes the splash state with the texture
* #return void
*/
void MainMenuState::initializeState()
{
	for (int i = 0; ISGREATER(i, _textureNames.size(), EPSILON); i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "Background")
		{
			//Set the texture
			_background.setTexture(this->_data->assets.getTexture(_textureNames[i]));
		}

		if (_textureNames[i] == "PlayButton")
		{
			//Set the texture
			_playButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), this->_playButton.getGlobalBounds().height / 2);
		}

		if (_textureNames[i] == "PlayButtonOuter")
		{
			//Set the texture
			_playButtonOuter.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2), this->_playButtonOuter.getGlobalBounds().height / 2);
		}

		if (_textureNames[i] == "GameTitle")
		{
			//Set the texture
			_title.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height * 0.1);
		}
	}
}

/**
* MainMenuState::inputHandler
* Handles the input
* #return void
*/
void MainMenuState::inputHandler()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		//Handle the "close" event
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		//Handle the "play" event
		if (this->_data->input.isSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.addState(StateReference(new GameState(_data)), true);
		}
	}
}

/**
* MainMenuState::update
* Updates the splash when it's changed
* @param double deltaFrames
* #return void
*/
void MainMenuState::update(double deltaFrames)
{
}

/**
* MainMenuState::draw
* Handles the drawings of the objects
* @param double deltaFrames
* #return void
*/
void MainMenuState::draw(double deltaFrames)
{
	//Clear the screen
	this->_data->window.clear(sf::Color::Red);
	//Set the background, title and buttons
	this->_data->window.draw(this->_title);
	this->_data->window.draw(this->_playButton);
	this->_data->window.draw(this->_playButtonOuter);
	this->_data->window.draw(this->_background);
	//Display the changes
	this->_data->window.display();
}
