#include "stdafx.h"
#include "InputManager.h"

bool InputManager::isSpriteClicked(const sf::Sprite& object, const sf::Mouse::Button& button, const sf::RenderWindow& window) const
{
	if (sf::Mouse::isButtonPressed(button))
	{
		//Casting to int to avoid warning of data loss
		sf::IntRect tempRectPlayButton(static_cast<int>(object.getPosition().x), static_cast<int>(object.getPosition().y), static_cast<int>(object.getGlobalBounds().width), static_cast<int>(object.getGlobalBounds().height));

		if (tempRectPlayButton.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

sf::Vector2i InputManager::getMousePosition(const sf::RenderWindow& window) const
{
	return sf::Mouse::getPosition(window);
}
