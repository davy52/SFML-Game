#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <iostream>
#include <vector>

class Menu
{
private:
	sf::RectangleShape* body;

	sf::Text* menuPause;
	enum choicePause
	{
		RESUME, SETTINGS, EXIT
	};

	//Recources
	sf::Font* font1;

	//inits
	void initBody();
	void initFont();
	void initVariables();
public:
	//Constructor/Deconstructor
	Menu();
	~Menu();

	//Accessors
	sf::RectangleShape getBody() const;
	sf::Text* getMenuPause() const;
	//Methods
	void setTextPosition(sf::Vector2f pos);


};

