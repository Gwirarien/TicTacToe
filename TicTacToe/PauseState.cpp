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
	int nSize = _textureNames.size();
	for (int i = 0; i < nSize; i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "PauseBackground")
		{
			//Set the texture
			_background.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			continue;
		}

		//Position the buttons
		if (_textureNames[i] == "ResumeButton")
		{
			//Set the texture
			_resumeButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
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
	//Set the background and buttons
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_resumeButton);
	this->_data->window.draw(this->_homeButton);
	//Display the changes
	this->_data->window.display();
}
