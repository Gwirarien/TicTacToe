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

	std::vector<std::string> _backgroundNames = {"ResumeButton", "HomeButton", "PauseBackground"};
	std::vector<std::string> _backgroundPaths = {RESUME_BUTTON, HOME_BUTTON, PAUSE_BACKGROUND_FILEPATH};
};
