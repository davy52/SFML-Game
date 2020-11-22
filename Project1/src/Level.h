#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <vector>

class Level
{
private:
	sf::Texture tileSet;
	int tileSize;
	float tileScale;
	sf::Vector2u mapSize;
	char tileMap[151]= "...............BBBBB........................B.....B.......................B.....B.........GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG..............................";
	std::vector<sf::Sprite>* tiles;


	void initVariables();

public:
	Level();
	~Level();

	void draw(sf::RenderTarget& target);
};

