#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include "Definitions.h"


class AssetManager
{
public:
	AssetManager() {}
	~AssetManager() {}

	//TODO - Refactor by using template methods
	void loadTexture(const std::string name, const std::string fileName);
	sf::Texture &getTexture(const std::string name);
	void loadFont(const std::string name, const std::string fileName);
	sf::Font &getFont(const std::string name);

private:
	//TODO - Refactor so that _tex and _font are passed by reference
	sf::Texture _tex;
	sf::Font _font;
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
};

template<typename T>
class AssetManagerTemplate : public AssetManager
{
public:
	AssetManagerTemplate() {}
	~AssetManagerTemplate() {}

	void loadAsset(const std::string name, const std::string fileName)
	{
		if (_asset.loadFromFile(fileName))
		{
			this->_assets[name] = _asset;
		}
	}

	T &getAsset(const std::string name)
	{
		return this->_assets.at(name);
	}

private:
	T _asset;
	std::map<std::string, T> _assets;
};