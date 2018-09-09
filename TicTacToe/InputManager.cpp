#include "stdafx.h"
#include "InputManager.h"

/**
* InputManager::isSpriteClicked
* Check if a sprite is clicked
* @param sf::Sprite object
* @param sf::Mouse::Button button
* @param sf::RenderWindow & window
* #return bool
*/
bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
	if(sf::Mouse::isButtonPressed(button))
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

/**
* InputManager::getMousePosition
* Gets the mouse position
* @param sf::RenderWindow & window
* #return sf::Vector2i
*/
sf::Vector2i InputManager::getMousePosition(sf::RenderWindow &window)
{
	return sf::Mouse::getPosition(window);
}
