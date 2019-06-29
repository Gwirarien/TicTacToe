#pragma once

#include <SFML/Graphics.hpp>
#include "Definitions.h"

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool isSpriteClicked(const sf::Sprite& object, const sf::Mouse::Button& button, const sf::RenderWindow& window) const;
	sf::Vector2i getMousePosition(const sf::RenderWindow& window) const;
};