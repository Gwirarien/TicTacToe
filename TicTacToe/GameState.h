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
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _pauseButton;
	int _turn;
	int _gameState;
};