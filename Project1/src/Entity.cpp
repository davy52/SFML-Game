#include "Entity.h"


//=================================================Entity 

//Inits
void Entity::initBody()
{
	this->MAX_VEL = 50.f;

	this->setPosition(sf::Vector2f(0.f, 0.f));
	this->setSize(sf::Vector2f(100.f, 100.f));
	this->setScale(sf::Vector2f(0.5f, 0.5f));
	this->setFillColor(sf::Color::Cyan);
	this->setOutlineColor(sf::Color::Black);
	this->setOutlineThickness(2.f);

	this->vel = sf::Vector2f(0.f, 0.f);
}


void Entity::initClock()
{
	this->EntityClock = new sf::Clock;
	this->time1 = this->EntityClock->getElapsedTime();
}

//Constructor/Deconstructor
Entity::Entity(sf::Vector2f size) : RectangleShape(size)
{

	this->initBody();
	this->initClock();
}

Entity::~Entity()
{
	//RectangleShape::~RectangleShape();
	delete this->EntityClock;
}

float Entity::getMaxVel()
{
	return this->MAX_VEL;
}

//Accessors
sf::Vector2f Entity::getPos() const
{
	return this->getPosition();
}

sf::Vector2f Entity::getVel() const
{
	return this->vel;
}



//Methods


//=================================================Player

//Constructor/Deconstructor

Player::Player(sf::Vector2f size) : Entity(size)
{

}

Player::~Player()
{

}

void Player::keys(sf::Keyboard::Key key)
{
	float speed = 10.f;
	switch (key)
	{
	case sf::Keyboard::Unknown:
		break;
	case sf::Keyboard::A:
		this->move(-speed, 0.f);
		break;
	case sf::Keyboard::Left:
		this->move(-speed, 0.f);
		break;
	case sf::Keyboard::D:
		this->move(speed, 0.f);
		break;
	case sf::Keyboard::Right:
		this->move(speed, 0.f);
		break;
	case sf::Keyboard::S:
		this->move(0.f, speed);
		break;
	case sf::Keyboard::Down:
		this->move(0.f, speed);
		break;
	case sf::Keyboard::W:
		this->move(0.f, -speed);
		break;
	case sf::Keyboard::Up:
		this->move(0.f, -speed);
		break;
	case sf::Keyboard::Space:
		break;
	}
}
