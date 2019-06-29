#include "stdafx.h"
#include "AssetManager.h"

void AssetManager::loadTexture(const std::string name, const std::string fileName)
{
	if (_tex.loadFromFile(fileName))
	{
		this->_textures[name] = _tex;
	}
}

sf::Texture& AssetManager::getTexture(const std::string& name)
{
	return this->_textures.at(name);
}

void AssetManager::loadFont(const std::string name, const std::string fileName)
{
	if (_font.loadFromFile(fileName))
	{
		this->_fonts[name] = _font;
	}
}

sf::Font& AssetManager::getFont(const std::string& name)
{
	return this->_fonts.at(name);
}
