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

		//Handle the "clicked sprite" event
		else if (this->_data->input.isSpriteClicked(this->_gridSprite, sf::Mouse::Left, this->_data->window))
		{
			//The user can click the sprite only if the game is playing
			if (STATE_PLAYING == _gameState)
			{
				this->checkAndPlacePiece();
			}
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
			_gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
		}
	}
}

/**
* GameState::checkAndPlacePiece
* Checks and places the pieces on the grid
* #return void
*/
void GameState::checkAndPlacePiece()
{
	sf::Vector2i touchPoint = this->_data->input.getMousePosition(this->_data->window);
	sf::FloatRect gridSize = _gridSprite.getGlobalBounds();
	sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
	sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

	//Relative position
	sf::Vector2f gridLocalTouchPosition = sf::Vector2f(touchPoint.x - gapOutsideOfGrid.x, touchPoint.y - gapOutsideOfGrid.y);

	int column = 0;
	//If it's within the first column
	if (gridLocalTouchPosition.x < gridSectionSize.x) 
	{
		column = 1;
	}
	//If it's less than 2/3 => it's within the second column
	else if (gridLocalTouchPosition.x < gridSectionSize.x * 2)
	{
		column = 2;
	} 	
	else if (gridLocalTouchPosition.x < gridSize.width * 2)
	{
		column = 3;
	}

	int row = 0;
	//If it's within the first column
	if (gridLocalTouchPosition.y < gridSectionSize.y)
	{
		row = 1;
	}
	//If it's less than 2/3 => it's within the second column
	else if (gridLocalTouchPosition.y < gridSectionSize.y * 2)
	{
		row = 2;
	}
	else if (gridLocalTouchPosition.y < gridSize.height * 2)
	{
		row = 3;
	}

	//Check if it's an empty space
	if (_gridArray[column - 1][row - 1] == EMPTY_PIECE)
	{
		_gridArray[column - 1][row - 1] = _turn;
		//If it's the player's turn, load the X's texture
		if (PLAYER_PIECE == _turn)
		{
			_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.getTexture("XPiece"));
			//Check if the player has won
			this->checkPlayerHasWon(_turn);
			_turn = AI_PIECE;
		}
		//If it's the AI's turn, load the O's texture
		else if (AI_PIECE == _turn)
		{
			_gridPieces[column - 1][row - 1].setTexture(this->_data->assets.getTexture("OPiece"));
			//Check if the player has won
			this->checkPlayerHasWon(_turn);
			_turn = PLAYER_PIECE;
		}
		//Show/Make it visible again
		_gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
	}
}

/**
* GameState::checkPlayerHasWon
* Checks if the player has won
* @param int player
* #return void
*/
void GameState::checkPlayerHasWon(int turn)
{
	checkThreePiecesForMatch(0, 0, 1, 0, 2, 0, turn);
	checkThreePiecesForMatch(0, 1, 1, 1, 2, 1, turn);
	checkThreePiecesForMatch(0, 2, 1, 2, 2, 2, turn);
	checkThreePiecesForMatch(0, 0, 0, 1, 0, 2, turn);
	checkThreePiecesForMatch(1, 0, 1, 1, 1, 2, turn);
	checkThreePiecesForMatch(2, 0, 2, 1, 2, 2, turn);
	checkThreePiecesForMatch(0, 0, 1, 1, 2, 2, turn);
	checkThreePiecesForMatch(0, 2, 1, 1, 2, 0, turn);

	int emptyNum = 9;

	//Track empty spaces
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (EMPTY_PIECE != _gridArray[x][y])
			{
				emptyNum--;
			}
		}
	}

	//Check if the game is a draw
	if ((emptyNum == 0) && (STATE_WON != _gameState) && (STATE_LOSE != _gameState))
	{
		_gameState = STATE_DRAW;
	}

	//Check if the game is over
	if ((STATE_DRAW == _gameState) || (STATE_LOSE == _gameState) || (STATE_WON == _gameState))
	{
		//Show game over state
	}

	printf("%d\n",_gameState);
}

/**
* GameState::checkThreePiecesForMatch
* Checks if three pieces are matched horizontally, vertically or diagonally
* @param int x1
* @param int y1
* @param int x2
* @param int y2
* @param int x3
* @param int y3
* @param int pieceToCheck
* #return void
*/
void GameState::checkThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck)
{
	if ((pieceToCheck == _gridArray[x1][y1]) && (pieceToCheck == _gridArray[x2][y2]) && (pieceToCheck == _gridArray[x3][y3]))
	{
		std::string winningPieceStr;
		if (O_PIECE == pieceToCheck)
		{
			winningPieceStr = "OWinningPiece";
		}
		else
		{
			winningPieceStr = "XWinningPiece";
		}

		_gridPieces[x1][y1].setTexture(this->_data->assets.getTexture(winningPieceStr));
		_gridPieces[x2][y2].setTexture(this->_data->assets.getTexture(winningPieceStr));
		_gridPieces[x3][y3].setTexture(this->_data->assets.getTexture(winningPieceStr));

		if (PLAYER_PIECE == pieceToCheck)
		{
			_gameState = STATE_WON;
		}
		else
		{
			_gameState = STATE_LOSE;
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