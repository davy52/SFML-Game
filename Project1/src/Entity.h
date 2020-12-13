#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

 
class Entity : public sf::RectangleShape 
{
protected:
	sf::Vector2f MAX_VEL = sf::Vector2f(4.f, 5.f); //horizontal and upwards maximum velocity, falling wont be capped
	sf::Vector2f acceleration = sf::Vector2f(1.f, 1.f); // running and jump accel
	float g = 10.f;

	

	//Inits
	void initBody();
	void initClock();
public:
	//Constructor/Deconstructor
	Entity(sf::Vector2f size);
	~Entity();

	//clock
	sf::Clock* EntityClock;
	sf::Time time1, time2;

	//velocity
	sf::Vector2f vel;


	//Accessors
	sf::Vector2f getMaxVel();
	sf::Vector2f getPos() const;
	sf::Vector2f getVel() const;
	sf::Vector2f get_acc();


	//Methods
	void move_vel();


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
	//void keys(sf::Keyboard::Key key, int time_mils);
};

