#include "Menu.h"

//Inits
void Menu::initBody()
{
	this->body = new sf::RectangleShape();
	this->body->setSize(sf::Vector2f(400.f, 100.f));
	this->body->setPosition(200.f, 250.f);
	this->body->setFillColor(sf::Color::Blue);
	this->body->setOutlineThickness(2.f);
	this->body->setOutlineColor(sf::Color::Black);
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
	//this->menuPause = new sf::Text;
	//this->menuPause->setFont(*this->font1);
	//this->menuPause->setCharacterSize(30);
	//this->menuPause->setString("Test");
	//this->menuPause->setFillColor(sf::Color::Black);
	//this->menuPause->setPosition(400.f, 300.f);
	this->menuPause = new sf::Text[3];
	//this->menuPause = new std::vector<sf::Text>;
	std::string arr[3] = { "Resume", "Settings", "Exit" };
	for (int i = 0; i < 3; i++) {
		//sf::Text temp;
		//temp.setFont(*this->font1);
		//temp.setCharacterSize(30);
		//temp.setOrigin(temp.getLocalBounds().width / 2.f, temp.getLocalBounds().height / 2.f); //zmina punktu okreslajacego polozenie obiektu (tekstu) na jego srodek
		//temp.setFillColor(sf::Color::Black);
		//temp.setString(arr[i]);
		//temp.setPosition(400.f, 300.f + 50 * i);
		//this->menuPause->push_back(temp);
		this->menuPause[i].setFont(*this->font1);
		this->menuPause[i].setCharacterSize(30);
		this->menuPause[i].setOrigin(this->menuPause->getLocalBounds().width / 2.f, this->menuPause->getLocalBounds().height / 2.f); //zmina punktu okreslajacego polozenie obiektu (tekstu) na jego srodek
		this->menuPause[i].setFillColor(sf::Color::Black);
		this->menuPause[i].setString(arr[i]);
		this->menuPause[i].setPosition(400.f, 300.f + 50 * i);
	}
}

//Constructor/Deconstructor
Menu::Menu()
{
	this->initBody();
	this->initFont();
	this->initVariables();
}

Menu::~Menu()
{
	delete this->body;
	delete this->font1;
	delete this->menuPause;
}

sf::RectangleShape Menu::getBody() const
{
	return *this->body;
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
