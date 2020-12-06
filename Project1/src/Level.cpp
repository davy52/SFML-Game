#include "Level.h"

void Level::initVariables()
{
	this->tileSize = 16;
	this->tileScale = 4;
	Level::tileSet;
	Level::tileSet.loadFromFile("Resources/TileSets/tileset1.png");

	this->mapSize = sf::Vector2u(60, 10);


	//this->tiles = new std::vector<sf::Sprite>(0);




	int x = 0, y = 0;
	/*for (sf::Sprite& sprite : *this->tiles) {

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
		}
		else {
			x++;
		}
	}*/
	int tN = 0;
	for (int i = 0; i < this->mapSize.x * this->mapSize.y; i++) {
		if (this->tileMap[(y * this->mapSize.x) + x] != '.') {
			Tile temp(this->tileSet);
			this->tiles.push_back(temp);
			switch (this->tileMap[(y * this->mapSize.x) + x])
			{
			case 'G':
				this->tiles[tN].setTextureRect(sf::IntRect(0, 0, 16, 16));
				this->tiles[tN].setColl(CollisionType::Solid);
				break;
			case 'B':
				this->tiles[tN].setTextureRect(sf::IntRect(16, 0, 16, 16));
				this->tiles[tN].setColl(CollisionType::Solid);
				break;
			}
			this->tiles[tN].setScale(this->tileScale, this->tileScale);
			this->tiles[tN].setPosition(x * this->tileSize * this->tileScale, y * this->tileSize * this->tileScale);
			tN++;
		}

		if (x == this->mapSize.x - 1) {
			y++;
			x = 0;
		}
		else {
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
	//delete this->tiles;
	delete this->tileMap;
}

void Level::draw(sf::RenderTarget& target)
{
	for (sf::Sprite& sprite : this->tiles) {
		target.draw(sprite);
	}
}
