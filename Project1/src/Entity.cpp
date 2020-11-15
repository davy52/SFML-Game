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


void Entity::setVel(sf::Vector2f v)
{
	this->vel = v;
}

void Entity::updatePos()
{
	this->time2 = this->EntityClock->getElapsedTime();
	float deltaT = this->time2.asSeconds() - this->time1.asSeconds();
	this->setPosition(this->getPosition() + (this->vel * deltaT));
	this->time1 = this->time2;
}

void Entity::updateVel(sf::Vector2f a)
{
	this->vel += a;
	if (this->vel.x > this->getMaxVel())
		this->vel.x = this->getMaxVel();
	else if (this->vel.x < -this->getMaxVel())
		this->vel.x = -this->getMaxVel();
	if (this->vel.y > this->getMaxVel())
		this->vel.y = this->getMaxVel();
	else if (this->vel.y < -this->getMaxVel())
		this->vel.y = -this->getMaxVel();
}

//=================================================Player

//Constructor/Deconstructor

Player::Player(sf::Vector2f size) : Entity(size)
{

}

Player::~Player()
{

}
