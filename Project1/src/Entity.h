#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

 
class Entity : public sf::RectangleShape 
{
protected:
	sf::Clock* EntityClock;
	float MAX_VEL;
	sf::Vector2f vel;
	sf::Time time1, time2;

	//Inits
	void initBody();
	void initClock();
public:
	//Constructor/Deconstructor
	Entity(sf::Vector2f size);
	~Entity();

	//Accessors
	float getMaxVel();
	sf::Vector2f getPos() const;
	sf::Vector2f getVel() const;


	//Methods



};

class Player : public Entity
{
protected:

public:
	//Constructor/Deconstructor
	Player(sf::Vector2f size);
	~Player();

	//Accessors

	//Methods
	void keys(sf::Keyboard::Key key, int time_mils);
};

