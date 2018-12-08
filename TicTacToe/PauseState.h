#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "Game.h"

class PauseState : public State
{
public:
	PauseState(GameDataRef dataRef);

	virtual void initializeState() override;
	virtual void inputHandler() override;
	virtual void update(double deltaFrames) override;
	virtual void draw(double deltaFrames) override;

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _resumeButton;
	sf::Sprite _homeButton;

	std::vector<std::string> _textureNames = { "PauseBackground", "ResumeButton", "HomeButton" };
	std::vector<std::string> _texturePaths = { PAUSE_BACKGROUND_FILEPATH, RESUME_BUTTON, HOME_BUTTON };
};
