#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>


#include "Entity.h"
#include "Menu.h"
#include "Level.h"

class Game
{
private:
	int MAX_FRAMERATE;
	//Window
	sf::RenderWindow* window;
	sf::Vector2u window_size;
	sf::Event event;
	sf::VideoMode videomode;

	//View
	sf::View view1;
	sf::View minimap;

	//Menu
	Menu* menu;
	bool bMenuActive = false;

	//Level
	Level* level;
	//Entities
	Player* player;

	//Clock
	sf::Clock* clock;
	sf::Time fps_time1, fps_time2; // do ograniczania predkosci wyswietlania klatek
	sf::Time engine_time1, engine_time2; // do ograniczania predkosci wykonywania obliczen np. jak czesto sprawdzac 

	//Inits
	void initVariables();
	void initWindow();
	void initClock();
	void initLevel();
	void initPlayer();
	void initMenu();
	void initView();

	//PrivateFunctions
	int getFpsTime();
	void updateFpsTime();


public:
	//Constructor/Deconstructor
	Game();
	~Game();

	//Accessors
	bool isRunning() const;

	//Methods
	void setMaxFramerate(uint16_t frames);

	void menuPause();

	void pollEvents();
	void update();
	void render();

	void renderPlayer(sf::RenderTarget& target);
	void renderMenu(sf::RenderTarget& target);


	void enter();

	


};

