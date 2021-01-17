#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

#include "MainMenuSelectors.h"
#include "global_structs.h"

//#include <cstdarg>

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

typedef struct con
{
	char name[50];
	double highScore[5];
} player;

class MainMenu
{
private:
	GAME_STATE gameState;

	sf::Font font;

	sf::RectangleShape* body;
	sf::Vector2f body_size;
	sf::Vector2f body_pos;

	player* Playerbase;
	player* Player;

	sf::View& view;

	struct menuText : public sf::Text
	{
	public:
		void(MainMenu::*func)(void);
		menuText() : func(NULL) {}
		menuText(void(MainMenu::* f)(void)) : func(f) {}
		menuText(void(MainMenu::* f)(void), const sf::String& string, const sf::Font& font, unsigned int cSize) : func(f), Text(string, font, cSize) {}
		bool operator==(menuText other) { return this->getString() == other.getString(); }
	};

	MenuState menuState;
	std::vector<menuText>::iterator SelectorPos;
	std::vector<menuText> textMain;
	std::vector<menuText> textLevel;
	std::vector<menuText> textProfile;
	std::vector<menuText> textSettings;
	std::vector<menuText>* textActual;




	void initTexts();

public:
	//CONSTRUCTOR
	MainMenu(sf::View& view, GAME_STATE gState, MenuState menuState = MenuState::main);
	~MainMenu();

	void readPlayerbase();

	void draw(sf::RenderTarget& target);
	
	void SelectorMove(SelDir dir);
	void SelectorEnter();

	void textUpdate();

	void text_main();
	void text_level();
	void text_char();

	void GameSave();
	void gameClose();


};

