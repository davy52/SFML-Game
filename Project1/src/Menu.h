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

	std::vector<sf::Text>* menuText;
	enum options
	{
		RESUME = 0, SETTINGS = 1, EXIT = 2
	};
	options selected;

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
	std::vector<sf::Text>* getMenuText() const;
	int getSelection() const;
	//Methods
	void setBodyPos(sf::Vector2f pos);
	void MoveText(sf::Vector2f dxy);
	void setTextPosition(sf::Vector2f pos);
	void setSelection(bool up);



};

