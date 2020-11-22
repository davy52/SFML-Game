#include "Level.h"

void Level::initVariables()
{
	this->tileSize = 16;
	this->tileScale = 3;
	Level::tileSet;
	Level::tileSet.loadFromFile("Resources/TileSets/tileset1.png");

	this->mapSize = sf::Vector2u(30, 5);


	this->tiles = new std::vector<sf::Sprite>(this->mapSize.x * this->mapSize.y);




	int x = 0, y = 0;
	for (sf::Sprite& sprite : *this->tiles) {

		if (this->tileMap[y * this->mapSize.x + x] == 'G') {
			sprite.setTexture(this->tileSet);
			sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
		}
		else if (this->tileMap[(y * (this->mapSize.x)) + x] == 'B') {
			sprite.setTexture(this->tileSet);
			sprite.setTextureRect(sf::IntRect(16, 0, 16, 16));
		}
		sprite.setScale(this->tileScale, this->tileScale);

		sprite.setPosition(x * this->tileSize * this->tileScale, y * this->tileSize * this->tileScale);

		if (x == this->mapSize.x - 1) {
			y++;
			x = 0;
		}else {
			x++;
		}
	}

}


Level::Level()
{
	initVariables();
}

Level::~Level()
{
	delete this->tiles;
	delete this->tileMap;
}

void Level::draw(sf::RenderTarget& target)
{
	for (sf::Sprite& sprite : *this->tiles) {
		target.draw(sprite);
	}
}
