#include "Entity.h"

//Inits
void Entity::initBody()
{
	this->MAX_VEL = 50.f;

	this->body = new sf::RectangleShape();
	this->body->setPosition(sf::Vector2f(0.f, 0.f));
	this->body->setSize(sf::Vector2f(100.f, 100.f));
	this->body->setScale(sf::Vector2f(0.5f, 0.5f));
	this->body->setFillColor(sf::Color::Cyan);
	this->body->setOutlineColor(sf::Color::Black);
	this->body->setOutlineThickness(2.f);

	this->vel = sf::Vector2f(0.f, 0.f);
}

void Entity::initClock()
{
	this->EntityClock = new sf::Clock;
	this->time1 = this->EntityClock->getElapsedTime();
}

//Constructor/Deconstructor
Entity::Entity()
{
	this->initBody();
	this->initClock();
}

Entity::~Entity()
{
	delete this->body;
	delete this->EntityClock;
}

float Entity::getMaxVel()
{
	return this->MAX_VEL;
}

//Accessors
sf::Vector2f Entity::getPos() const
{
	return this->body->getPosition();
}

sf::Vector2f Entity::getVel() const
{
	return this->vel;
}

sf::Vector2f Entity::getSize() const
{
	return this->body->getSize();
}

sf::RectangleShape Entity::getBody() const
{
	return *this->body;
}

//Methods
void Entity::setPos(sf::Vector2f p)
{
	this->body->setPosition(p);
}

void Entity::setVel(sf::Vector2f v)
{
	this->vel = v;
}

void Entity::updatePos()
{
	this->time2 = this->EntityClock->getElapsedTime();
	float deltaT = this->time2.asSeconds() - this->time1.asSeconds();
	this->body->setPosition(this->body->getPosition() + (this->vel * deltaT));
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


