#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>

#include "Entity.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videomode;

	//Entities
	Entity* player;

	typedef struct {
		bool W;
		bool A;
		bool S;
		bool D;
	} Keys;

	Keys keys;

	//Clock
	sf::Clock* clock;
	sf::Time fps_time1, fps_time2; // do ograniczania predkosci wyswietlania klatek
	sf::Time engine_time1, engine_time2; // do ograniczania predkosci wykonywania obliczen np. jak czesto sprawdzac 

	//Inits
	void initVariables();
	void initWindow();
	void initClock();
	void initPlayer();

	//PrivateFunctions
	void updateKeys();
public:
	//Constructor/Deconstructor
	Game();
	~Game();

	//Accessors
	bool isRunning() const;
	int getFpsTime();

	//Methods
	void updateFpsTime();
	void pollEvents();
	void update();
	void render();


};

