#include "stdafx.h"
#include "InputManager.h"

bool InputManager::isSpriteClicked(const sf::Sprite& object, const sf::Mouse::Button& button, const sf::RenderWindow& window) const
{
	if (sf::Mouse::isButtonPressed(button))
	{
		//Casting to int to avoid warning of data loss
		sf::IntRect tempRectPlayButton((int)object.getPosition().x, (int)object.getPosition().y, (int)object.getGlobalBounds().width, (int)object.getGlobalBounds().height);

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
