#include "stdafx.h"
#include "PauseState.h"

/**
* PauseState::PauseState
* Constructor
* @param GameDataRef dataRef
*/
PauseState::PauseState(GameDataRef dataRef)
	:_data(dataRef)
{
}

/**
* PauseState::initializeState
* Initializes the splash state with the texture
* #return void
*/
void PauseState::initializeState()
{
	for (int i = 0; ISGREATER(i, _backgroundNames.size(), EPSILON); i++)
	{
		this->_data->assets.loadTexture(_backgroundNames[i], _backgroundPaths[i]);
		_background.setTexture(this->_data->assets.getTexture(_backgroundNames[i]));

		//Position the buttons
		if (_backgroundNames[i] == "ResumeButton")
		{
			this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
		}

		if (_backgroundNames[i] == "HomeButton")
		{
			this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
		}
	}
}

/**
* PauseState::inputHandler
* Handles the input
* #return void
*/
void PauseState::inputHandler()
{
	sf::Event event;

	while (this->_data->window.pollEvent(event))
	{
		//Handle the "close" event
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		//Handle the "resume" event
		if (this->_data->input.isSpriteClicked(this->_resumeButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.removeState();
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
* PauseState::update
* Updates the splash when it's changed
* @param double deltaFrames
* #return void
*/
void PauseState::update(double deltaFrames)
{
}

/**
* PauseState::draw
* Handles the drawings of the objects
* @param double deltaFrames
* #return void
*/
void PauseState::draw(double deltaFrames)
{
	//Clear the screen
	this->_data->window.clear(sf::Color::Red);
	//Set the background and button
	this->_data->window.draw(this->_resumeButton);
	this->_data->window.draw(this->_homeButton);
	this->_data->window.draw(this->_background);
	//Display the changes
	this->_data->window.display();
}
