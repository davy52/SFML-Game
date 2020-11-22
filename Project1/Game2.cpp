#include "Game2.h"

//Inits

void Game2::initVariables()
{
	this->event = new sf::Event;
}

void Game2::initWindow(int width, int height, std::string title, int style)
{
	this->window = new sf::RenderWindow(sf::VideoMode(width, height), title, style);
}


//Constructor/Destructor

Game2::Game2(int width, int height, std::string title, int style)
{
	this->initVariables();
	this->initWindow(width, height, title, style);
}

Game2::~Game2()
{
	delete window;
}

bool Game2::isRunning() const
{
	return this->window->isOpen();
}


//Functions
void Game2::handleEvents()
{
	while (this->window->pollEvent(*this->event))
	{
		switch (this->event->type)
		{
		case (sf::Event::Closed):
			this->window->close();
			break;
		case (sf::Event::Resized):
			break;
		}
	}
}

void Game2::update()
{
	this->handleEvents();
}

void Game2::render()
{
	this->window->clear(sf::Color(0, 120, 80, 255));
	this->window->display();
}
