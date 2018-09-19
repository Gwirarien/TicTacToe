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

	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _pauseButton;
	sf::Sprite _gridSprite;
	sf::Sprite _gridPieces[3][3];
	int _gridArray[3][3];
	int _turn;
	int _gameState;

	std::vector<std::string> _textureNames = {"PauseButton", "XPiece", "OPiece", "GridSprite"};
	std::vector<std::string> _texturePaths = {GAME_PAUSE_BUTTON, X_PIECE_FILEPATH, O_PIECE_FILEPATH, GRID_SPRITE_FILEPATH};
};