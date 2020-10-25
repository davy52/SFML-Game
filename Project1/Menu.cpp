#include "Menu.h"

//Inits
void Menu::initBody(sf::Vector2f size, sf::Vector2f pos, sf::Color color, float outlineThickness, sf::Color outlineColor)
{
	this->body = new sf::RectangleShape();
	this->body->setSize(size);
	this->body->setPosition(pos);
	this->body->setFillColor(color);
	this->body->setOutlineThickness(outlineThickness);
	this->body->setOutlineColor(outlineColor);
}

void Menu::initFont()
{
	this->font1 = new sf::Font;
	if (!this->font1->loadFromFile("Resources/Fonts/SyneMono-Regular.ttf")) {
		std::cout << "[ERROR]: Could not load font1 (Resources/Fonts/SyneMono-Regular.ttf)\n";
	}
}

void Menu::initVariables()
{
	this->menuPause = new sf::Text[3];
	this->menuPause->setString("Resume");
	this->menuPause->setString("Settings");
	this->menuPause->setString("Exit");
}

//Constructor/Deconstructor
Menu::Menu(sf::Vector2f size, sf::Vector2f pos, sf::Color color, float outlineThickness, sf::Color outlineColor)
{
	this->initBody(size, pos, color, outlineThickness, outlineColor);
	this->initFont();
	this->initVariables();
}

Menu::~Menu()
{
	delete this->body;
	delete this->font1;
	delete this->menuPause;
}
