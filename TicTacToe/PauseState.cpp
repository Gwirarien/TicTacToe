#include "stdafx.h"
#include "PauseState.h"

PauseState::PauseState(GameDataRef dataRef)
	:_data(dataRef)
{}

void PauseState::initializeState()
{
	int nSize = _textureNames.size();
	for (int i = 0; i < nSize; i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "PauseBackground")
		{
			_background.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			continue;
		}

		if (_textureNames[i] == "ResumeButton")
		{
			_resumeButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			this->_resumeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_resumeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3) - (this->_resumeButton.getLocalBounds().height / 2));
			continue;
		}

		if (_textureNames[i] == "HomeButton")
		{
			_homeButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			this->_homeButton.setPosition((this->_data->window.getSize().x / 2) - (this->_homeButton.getLocalBounds().width / 2),
				(this->_data->window.getSize().y / 3 * 2) - (this->_homeButton.getLocalBounds().height / 2));
			continue;
		}
	}
}

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
			//Resume the game by popping the current state
			this->_data->machine.removeState();
		}

		//Handle the "home" event
		if (this->_data->input.isSpriteClicked(this->_homeButton, sf::Mouse::Left, this->_data->window))
		{
			this->_data->machine.removeState();
			//Switch to game state
			this->_data->machine.addState(StateReference(new MainMenuState(_data)), true);
		}
	}
}

void PauseState::update(double deltaFrames)
{}

void PauseState::draw(double deltaFrames)
{
	this->_data->window.clear(sf::Color::Red);
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_resumeButton);
	this->_data->window.draw(this->_homeButton);
	this->_data->window.display();
}
