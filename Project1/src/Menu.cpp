#include "Menu.h"

//Inits
void Menu::initBody()
{
	this->body = new sf::RectangleShape();
	this->body->setSize(sf::Vector2f(400.f, 150.f));
	this->body->setPosition(200.f, 250.f);
	this->body->setFillColor(sf::Color::Blue);
	this->body->setOutlineThickness(4.f);
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
	this->selected = RESUME;
	std::string arr[3] = { "Resume", "Exit" };

	menuText = new std::vector<sf::Text>(2);
	int i = 0;
	for (auto & text : *menuText) {
		text.setFont(*this->font1);
		text.setCharacterSize(30);
		if (i == 0) {
			text.setCharacterSize(40);
			text.setStyle(1);
		}
	
		text.setString(arr[i]);
		text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
		text.setPosition(400.f, 270.f + 50 * i);
		text.setFillColor(sf::Color::Black);
		i++;
	}

	////this->menuPause = new sf::Text;
	////this->menuPause->setFont(*this->font1);
	////this->menuPause->setCharacterSize(30);
	////this->menuPause->setString("Test");
	////this->menuPause->setFillColor(sf::Color::Black);
	////this->menuPause->setPosition(400.f, 300.f);
	//this->menuPause = new sf::Text[3];
	////this->menuPause = new std::vector<sf::Text>;
	//std::string arr[3] = { "Resume", "Settings", "Exit" };
	//for (int i = 0; i < 3; i++) {
	//	//sf::Text temp;
	//	//temp.setFont(*this->font1);
	//	//temp.setCharacterSize(30);
	//	//temp.setOrigin(temp.getLocalBounds().width / 2.f, temp.getLocalBounds().height / 2.f); //zmina punktu okreslajacego polozenie obiektu (tekstu) na jego srodek
	//	//temp.setFillColor(sf::Color::Black);
	//	//temp.setString(arr[i]);
	//	//temp.setPosition(400.f, 300.f + 50 * i);
	//	//this->menuPause->push_back(temp);
	//	this->menuPause[i].setFont(*this->font1);
	//	this->menuPause[i].setCharacterSize(30);
	//	this->menuPause[i].setOrigin(this->menuPause->getLocalBounds().width / 2.f, this->menuPause->getLocalBounds().height / 2.f); //zmina punktu okreslajacego polozenie obiektu (tekstu) na jego srodek
	//	this->menuPause[i].setFillColor(sf::Color::Black);
	//	this->menuPause[i].setString(arr[i]);
	//	this->menuPause[i].setPosition(400.f, 300.f + 50 * i);
	
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
	delete this->menuText;
}

sf::RectangleShape Menu::getBody() const
{
	return *this->body;
}

std::vector<sf::Text>* Menu::getMenuText() const
{
	return this->menuText;
}

int Menu::getSelection() const
{
	switch (selected)
	{
	case Menu::RESUME:
		return 0;
	case Menu::SETTINGS:
		return 1;
	case Menu::EXIT:
		return 2;
	}
}

//Methods

void Menu::setBodyPos(sf::Vector2f pos)
{
	sf::Vector2f dxy = pos - this->body->getPosition() - sf::Vector2f(this->body->getSize().x/2, this->body->getSize().y/2);

	this->body->move(dxy);

	for (auto& text : *this->menuText) {
		text.move(dxy);
	}
}

void Menu::MoveText(sf::Vector2f dxy)
{
	for (auto& text : *this->menuText) {
		text.move(dxy);
	}
}

void Menu::setTextPosition(sf::Vector2f pos)
{
	int i = 0;
	for (auto &text : *this->menuText) {
		text.setPosition(sf::Vector2f(pos.x, pos.y + i * 30));
		i++;
	}
}

void Menu::setSelection(bool up)
{
	if (up) {
		switch (this->selected) {
		case SETTINGS:
			this->selected = RESUME;
			break;
		case EXIT:
			this->selected = RESUME;
			break;
		}
	}
	else if (!up) {
		switch (this->selected)
		{
		case RESUME:
			this->selected = EXIT;
			break;
		case SETTINGS:
			this->selected = EXIT;
			break;
		}
	}
	int i = 0;
	for (auto& text : *menuText) {
		text.setCharacterSize(i == selected ? 40 : 30);
		text.setStyle(i == selected ? 1 : 0);
		i++;
	}
}


