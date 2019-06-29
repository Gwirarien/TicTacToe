#include "stdafx.h"
#include "MainMenuState.h"
#include "GameState.h"

MainMenuState::MainMenuState(GameDataRef dataRef)
	:_data(dataRef)
{}

void MainMenuState::initializeState()
{
	int nSize = _textureNames.size();
	for (int i = 0; i < nSize; i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "MainMenuBackground")
		{
			_background.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			continue;
		}

		if (_textureNames[i] == "PlayButton")
		{
			_playButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - this->_playButton.getGlobalBounds().height / 2);
			continue;
		}

		if (_textureNames[i] == "PlayButtonOuter")
		{
			_playButtonOuter.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			this->_playButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_playButtonOuter.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - this->_playButtonOuter.getGlobalBounds().height / 3);
			continue;
		}

		if (_textureNames[i] == "GameTitle")
		{
			_title.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2),
				this->_title.getGlobalBounds().height * 0.1f);
			continue;
		}
	}
}

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

void MainMenuState::update(double deltaFrames)
{}

void MainMenuState::draw(double deltaFrames)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);
	this->_data->window.draw(this->_playButtonOuter);
	this->_data->window.draw(this->_title);
	this->_data->window.display();
}
