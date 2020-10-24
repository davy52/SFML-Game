#include "Game.h"

//Inits
void Game::initVariables()
{
	this->window = nullptr;
	this->videomode.width = 800;
	this->videomode.height = 600;
	this->keys = { false, false, false, false };

}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->videomode, "First Window", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initClock()
{
	this->clock = new sf::Clock; //start timer
	this->engine_time1 = this->clock->getElapsedTime();
	this->fps_time1 = this->clock->getElapsedTime();
}

void Game::initPlayer()
{
	this->player = new Entity;
	this->player->setPos(sf::Vector2f(400.f, 300.f));
}

//PrivateFunctions
void Game::updateKeys()
{
	if (this->keys.A == true)
		this->player->updateVel(sf::Vector2f(-5.f, 0.f));
	else if (this->keys.D == true)
		this->player->updateVel(sf::Vector2f(5.f, 0.f));
	else
		this->player->updateVel(sf::Vector2f(0.f, 0.f));

	if (this->keys.W == true)
		this->player->updateVel(sf::Vector2f(0.f, -5.f));
	else if (this->keys.S == true)
		this->player->updateVel(sf::Vector2f(0.f, 5.f));
	else
		this->player->updateVel(sf::Vector2f(0.f, 0.f));

}

//Constructor/Deconstructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initClock();
	this->initPlayer();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->clock;
	delete this->player;
}
	
//Accessors
bool Game::isRunning() const
{
	return this->window->isOpen();
}
int Game::getFpsTime() 
{
	this->fps_time2 = this->clock->getElapsedTime();
	return this->fps_time2.asMilliseconds() - this->fps_time1.asMilliseconds();
}


//Methods
void Game::updateFpsTime()
{
	this->fps_time1 = this->fps_time2;
}


void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			/*               if(events.key.code == sf::Keyboard::Escape)
								game.menu()*/

			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->event.key.code == sf::Keyboard::A)
				this->keys.A = true;
			if (this->event.key.code == sf::Keyboard::S)
				this->keys.S = true;
			if (this->event.key.code == sf::Keyboard::D)
				this->keys.D = true;
			if (this->event.key.code == sf::Keyboard::W)
				this->keys.W = true;
			break;
		case sf::Event::KeyReleased:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			if (this->event.key.code == sf::Keyboard::A)
				this->keys.A = false;
			if (this->event.key.code == sf::Keyboard::S)
				this->keys.S = false;
			if (this->event.key.code == sf::Keyboard::D)
				this->keys.D = false;
			if (this->event.key.code == sf::Keyboard::W)
				this->keys.W = false;
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->updateKeys();
	this->player->updatePos();
	//print pos of mouse on monitor
	//std::cout << "Absolute mouse pos: " << sf::Mouse::getPosition().x << "\t" << sf::Mouse::getPosition().y;
	//
	////print pos of mouse on window
	//std::cout << "\trel to window: " << sf::Mouse::getPosition(*this->window).x << "\t" << sf::Mouse::getPosition(*this->window).y << std::endl;
	this->engine_time2 = this->clock->getElapsedTime();
	std::cout << this->engine_time2.asSeconds() << std::endl;
}

void Game::render()
{
	/*
		Renders game
	*/

	this->window->clear(sf::Color::Green); //clear old frame with green (green background if nothing drawn)
	//draw game
	this->window->draw(this->player->getBody());

	//display game
	this->window->display(); //render new frame
}

