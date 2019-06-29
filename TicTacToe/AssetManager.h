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
	sf::Texture& getTexture(const std::string& name) const;
	void loadFont(const std::string name, const std::string fileName);
	sf::Font& getFont(const std::string& name) const;

private:
	sf::Texture _tex;
	sf::Font _font;
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
};