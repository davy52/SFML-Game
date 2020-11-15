#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <string>


#include "Entity.h"
#include "Menu.h"

class Game
{
private:
	int MAX_FRAMERATE;
	sf::Texture tex_alf;
	sf::Sprite spr_alf;
	//Window
	sf::RenderWindow* window;
	sf::Vector2u window_size;
	sf::Event event;
	sf::VideoMode videomode;

	//Menu
	Menu* menu;
	bool bMenuActive = false;

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
	void initAlf();
	void initVariables();
	void initWindow();
	void initClock();
	void initPlayer();
	void initMenu();

	//PrivateFunctions
	void updateKeys();
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

	void renderAlf(sf::RenderTarget& target);

	void enter();

	


};

