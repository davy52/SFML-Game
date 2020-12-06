#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <vector>

enum class CollisionType
{
	Transparent, Solid, Semi
};

class Tile : public sf::Sprite
{
public:
	CollisionType CollType;
	Tile(const sf::Texture& texture, CollisionType ctype = CollisionType::Transparent) : Sprite(texture) { this->CollType = ctype; }
	~Tile() {};
	void setColl(CollisionType ctype) { this->CollType = ctype; }
	CollisionType getColl() { return this->CollType; }
};


class Level
{
private:
	sf::Texture tileSet;
	int tileSize;
	float tileScale;
	sf::Vector2u mapSize;
	//char tileMap[151]= "...............BBBBB........................B.....B.......................B.....B.........GGGGGGGGGGGGGGGGGGGGGGGGGGGGGG..............................";
	char tileMap[601] = ".........................................................................B....B....BBBBBBBB.....B....B.....B..................................B.......B.......................................B...........B.....B.B...................................................BB....B.B...............................................B...B.....B.B.....GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG..........B...B....BB.B....GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG...BBBBBB.B...B.....B.B...GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG..........B.........B....GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
	std::vector<Tile> tiles;


	void initVariables();

public:
	Level();
	~Level();

	void draw(sf::RenderTarget& target);
};

