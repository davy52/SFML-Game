#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <iostream>
#include <vector>

#include "MainMenuSelectors.h"

enum class SelDir {
	UP,
	DOWN,
};

enum class MenuState {
	main,
	level,
	character,
	profile,
	skin,
	settings
};

class MainMenu
{
private:
	sf::Font font;

	sf::RectangleShape* body;
	sf::Vector2f body_size;
	sf::Vector2f body_pos;

	MenuState menuState;
	SelPos SelectorPos;
	std::vector<sf::Text*> text;

	//sf::RenderWindow& window;

public:
	//CONSTRUCTOR
	MainMenu(sf::View& view, MenuState menuState = MenuState::main);
	~MainMenu();

	void draw(sf::RenderTarget& target);
	
	void SelectorMove(SelDir dir);
	void SelectorEnter();

	void textUpdate();

	void text_main();
	void text_level();
	void text_char();
	void text_settings();



};

