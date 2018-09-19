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

	_background.setTexture(this->_data->assets.getTexture("MainMenuBackground"));

	int nSize = _textureNames.size();
	for (int i = 0; i < nSize; i++)
	{
		this->_data->assets.loadTexture(_textureNames[i], _texturePaths[i]);

		if (_textureNames[i] == "PauseButton")
		{
			//Set the texture
			_pauseButton.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			_pauseButton.setPosition(this->_data->window.getSize().x - _pauseButton.getGlobalBounds().width,
				_pauseButton.getPosition().y);
			continue;
		}

		if (_textureNames[i] == "GridSprite")
		{
			//Set the texture
			_gridSprite.setTexture(this->_data->assets.getTexture(_textureNames[i]));
			//Position the button
			_gridSprite.setPosition((SCREEN_WIDTH / 2) - (_gridSprite.getGlobalBounds().width / 2),
				(SCREEN_HEIGHT / 2) - (_gridSprite.getGlobalBounds().height / 2));
			continue;
		}
	}
		initializeGridPieces();

	//Reset grid values
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			_gridArray[x][y] = EMPTY_PIECE;
		}
	}
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
			this->_data->machine.addState(StateReference(new PauseState(_data)), false);
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
* GameState::initializeGridPieces
* Initializes the pieces of the grid
* #return void
*/
void GameState::initializeGridPieces()
{
	sf::Vector2u tempSpriteSize = this->_data->assets.getTexture("XPiece").getSize();

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			_gridPieces[x][y].setTexture(this->_data->assets.getTexture("XPiece"));
			_gridPieces[x][y].setPosition(_gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7,
				_gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7);
			_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 255));
		}
	}
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
	this->_data->window.draw(this->_gridSprite);

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			this->_data->window.draw(this->_gridPieces[x][y]);
		}
	}

	//Display the changes
	this->_data->window.display();
}