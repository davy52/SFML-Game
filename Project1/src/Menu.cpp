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
	std::string arr[3] = { "Resume", "Settings", "Exit" };
	for (int i = 0; i < 3; i++) {
		this->menuPause[i].setFont(*this->font1);
		this->menuPause[i].setCharacterSize(30);
		this->menuPause[i].setOrigin(this->menuPause->getLocalBounds().width / 2.f, this->menuPause->getLocalBounds().height / 2.f); //zmina punktu okreslajacego polozenie obiektu (tekstu) na jego srodek
		this->menuPause[i].setFillColor(sf::Color::Black);
		this->menuPause[i].setString(arr[i]);
	}
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

sf::RectangleShape* Menu::getBody() const
{
	return this->body;
}

sf::Text* Menu::getMenuPause() const
{
	return this->menuPause;
}

//Methods
void Menu::setTextPosition(sf::Vector2f pos)
{
	for (int i = 0; i < 3; i++) {
		this->menuPause[i].setPosition(sf::Vector2f(pos.x, pos.y + i * 30));
	}
}
