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
void AssetManager::loadTexture(std::string name, std::string fileName, sf::Texture *tex)
{
	if (tex->loadFromFile(fileName))
	{
		this->_textures[name] = *tex;
	}
}

/**
* AssetManager::loadTexture
* Returns the texture
* @param std::string name
* #return sf::Texture
*/
sf::Texture &AssetManager::getTexture(std::string name)
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
void AssetManager::loadFont(std::string name, std::string fileName, sf::Font *font)
{
	if (font->loadFromFile(fileName))
	{
		this->_fonts[name] = *font;
	}
}

/**
* AssetManager::loadFont
* Returns the font
* @param std::string name
* #return sf::Font
*/
sf::Font &AssetManager::getFont(std::string name)
{
	return this->_fonts.at(name);
}