#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class GameState : public State
{
public:
	GameState(GameDataRef dataRef);

	virtual void initializeState() override;
	virtual void inputHandler() override;
	virtual void update(double deltaFrames) override;
	virtual void draw(double deltaFrames) override;

private:
	void initializeGridPieces();
	void checkAndPlacePiece();
	void checkPlayerHasWon(int turn);
	void checkThreePiecesForMatch(int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _pauseButton;
	sf::Sprite _gridSprite;
	sf::Sprite _gridPieces[3][3];
	int _gridArray[3][3];
	int _turn;
	int _gameState;

	std::vector<std::string> _textureNames{ "PauseButton", "XPiece", "OPiece", "XWinningPiece", "OWinningPiece", "GridSprite" };
	std::vector<std::string> _texturePaths{ GAME_PAUSE_BUTTON, X_PIECE_FILEPATH, O_PIECE_FILEPATH, X_PIECE_WINNING_FILEPATH, O_PIECE_WINNING_FILEPATH, GRID_SPRITE_FILEPATH };
};