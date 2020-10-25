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
	void initBody(sf::Vector2f size, sf::Vector2f pos, sf::Color color = sf::Color::Blue, float outlineThickness = 2.f, sf::Color outlineColor = sf::Color::Black);
	void initFont();
	void initVariables();
public:
	//Constructor/Deconstructor
	Menu(sf::Vector2f size, sf::Vector2f pos, sf::Color color = sf::Color::Blue, float outlineThickness = 2.f, sf::Color outlineColor = sf::Color::Black);
	~Menu();

	//Accessors
	sf::RectangleShape* getBody() const;
	sf::Text* getMenuPause() const;
	//Methods
	void setTextPosition(sf::Vector2f pos);


};

