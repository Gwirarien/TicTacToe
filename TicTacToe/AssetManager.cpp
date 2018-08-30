#include "stdafx.h"
#include "AssetManager.h"


/**
* AssetManager::loadTexture
* Loads the texture
* @param std::string name
* @param std::string fileName
* @param sf::Texture *tex
* #return void
*/
void AssetManager::loadTexture(const std::string name, const std::string fileName)
{
	if (_tex.loadFromFile(fileName))
	{
		this->_textures[name] = _tex;
	}
}

/**
* AssetManager::loadTexture
* Returns the texture
* @param std::string name
* #return sf::Texture
*/
sf::Texture &AssetManager::getTexture(const std::string name)
{
	return this->_textures.at(name);
}

/**
* AssetManager::loadFont
* Loads the texture
* @param std::string name
* @param std::string fileName
* @param sf::Font *font
* #return void
*/
void AssetManager::loadFont(const std::string name, const std::string fileName)
{
	if (_font.loadFromFile(fileName))
	{
		this->_fonts[name] = _font;
	}
}

/**
* AssetManager::loadFont
* Returns the font
* @param std::string name
* #return sf::Font
*/
sf::Font &AssetManager::getFont(const std::string name)
{
	return this->_fonts.at(name);
}
