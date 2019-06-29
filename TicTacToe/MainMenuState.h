#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
public:
	MainMenuState(GameDataRef dataRef);

	virtual void initializeState() override;
	virtual void inputHandler() override;
	virtual void update(double deltaFrames) override;
	virtual void draw(double deltaFrames) override;

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _playButton;
	sf::Sprite _playButtonOuter;
	sf::Sprite _title;

	std::vector<std::string> _textureNames{ "MainMenuBackground", "PlayButton", "PlayButtonOuter", "GameTitle" };
	std::vector<std::string> _texturePaths{ MAIN_MENU_BACKGROUND_FILEPATH, MAIN_MENU_PLAY_BUTTON, MAIN_MENU_PLAY_BUTTON_OUTER, MAIN_MENU_TITLE_PATH };
};