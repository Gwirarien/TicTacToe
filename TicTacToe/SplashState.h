#pragma once

#include <SFML/Graphics.hpp>
#include "MainMenuState.h"
#include "Game.h"

class SplashState : public State
{
public:
	SplashState(GameDataRef dataRef);

	virtual void initializeState() override;
	virtual void inputHandler() override;
	virtual void update(double deltaFrames) override;
	virtual void draw(double deltaFrames) override;

private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;
};