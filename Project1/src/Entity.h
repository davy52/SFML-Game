#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Entity
{
private:
	float MAX_VEL;

	sf::RectangleShape* body;

	sf::Vector2f pos;
	sf::Vector2f vel;
	sf::Clock* EntityClock;
	sf::Time time1, time2;

	//Inits
	void initBody();
	void initClock();
public:
	//Constructor/Deconstructor
	Entity();
	~Entity();

	//Accessors
	float getMaxVel();
	sf::Vector2f getPos() const;
	sf::Vector2f getVel() const;
	sf::Vector2f getSize() const;

	sf::RectangleShape getBody() const;

	//Methods
	void setPos(sf::Vector2f p);
	void setVel(sf::Vector2f v); 
	void updatePos();
	void updateVel(sf::Vector2f a);



};

