#include "stdafx.h"
#include "MainMenuState.h"

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
	for (int i = 0; ISGREATER(i, _backgroundNames.size(), EPSILON); i++)
	{
		this->_data->assets.loadTexture(_backgroundNames[i], _backgroundPaths[i]);
		_background.setTexture(this->_data->assets.getTexture(_backgroundNames[i]));
		
		//Position the background items
		if (_backgroundNames[i] == "PlayButton")
		{
			this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), this->_playButton.getGlobalBounds().height / 2);
		}

		if (_backgroundNames[i] == "PlayButtonOuter")
		{
			this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2), this->_playButtonOuter.getGlobalBounds().height / 2);
		}

		if (_backgroundNames[i] == "GameTitle")
		{
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
			printf("Go to Game Screen\n");
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
