#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "Game.h"

class GameOverState : public State
{
public:
	GameOverState(GameDataRef dataRef);

	virtual void initializeState() override;
	virtual void inputHandler() override;
	virtual void update(double deltaFrames) override;
	virtual void draw(double deltaFrames) override;

private:
	GameDataRef _data;
	sf::Sprite _homeButton;
	sf::Sprite _retryButton;

	std::vector<std::string> _textureNames = { "RetryButton", "HomeButton" };
	std::vector<std::string> _texturePaths = { RETRY_BUTTON, HOME_BUTTON };
};

