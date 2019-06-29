#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "AssetManager.h"
#include "InputManager.h"
#include "StateManager.h"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManagerTemplate<AssetManager> assets;
	InputManager input;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
public:
	Game(int screenWidth, int screenHeight, const std::string title);

private:
	const double deltaTime = 1.0 / 60.0; //60 fps
	sf::Clock _clock;  //framerate handler
	GameDataRef _data = std::make_shared<GameData>();

	void run();
};
