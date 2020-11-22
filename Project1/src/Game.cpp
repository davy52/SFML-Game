#include "Game.h"

//Inits

void Game::initVariables()
{
	this->MAX_FRAMERATE = 60;

	this->window = nullptr;
	this->videomode.width = 1600;
	this->videomode.height = 900;
	this->window_size = sf::Vector2u(800, 600);

}

void Game::initWindow()
{
	this->window = new sf::RenderWindow(this->videomode , "First Window", sf::Style::Titlebar | sf::Style::Close);
}

void Game::initClock()
{
	this->clock = new sf::Clock; //start timer
	this->engine_time1 = this->clock->getElapsedTime();
	this->fps_time1 = this->clock->getElapsedTime();
}

void Game::initLevel()
{
	this->level = new Level();
}

void Game::initPlayer()
{
	this->player = new Player(sf::Vector2f(100.f, 100.f));
	this->player->setPosition(sf::Vector2f(400.f, 300.f));
}

void Game::initMenu()
{
	this->menu = new Menu();
	//this->menu->setTextPosition(sf::Vector2f(400.f, 20.f));

}

//PrivateFunctions

//Constructor/Deconstructor
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initClock();
	this->initLevel();
	this->initPlayer();
	this->initPlayer();
	//this->initMenu();
}

Game::~Game()
{
	delete this->window;
	delete this->clock;
	//delete this->menu;
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
void Game::setMaxFramerate(uint16_t frames) 
{
	this->MAX_FRAMERATE = frames;
}

void Game::menuPause()
{
	this->initMenu();
	this->bMenuActive = true;
	while (bMenuActive) {
		if (this->getFpsTime() > 100.f / this->MAX_FRAMERATE) {
			this->window->clear(sf::Color::Green); //clear old frame with green (green background if nothing drawn)


			//draw game
			//this->renderAlf(*this->window);
			//this->renderPlayer(*this->window);
			this->renderMenu(*this->window);

			//display game
			this->window->display(); //render new frame

			this->updateFpsTime();
		}
		while (this->window->pollEvent(this->event)) {
			switch (this->event.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				/*               if(events.key.code == sf::Keyboard::Escape)
									game.menu()*/

				if (this->event.key.code == sf::Keyboard::Escape) {
					bMenuActive = false;
					break;
				}
				if (this->event.key.code == sf::Keyboard::S)
					this->menu->setSelection(false);
				if (this->event.key.code == sf::Keyboard::W)
					this->menu->setSelection(true);
				if (this->event.key.code == sf::Keyboard::Enter) {
					this->enter();
					break;
				}
			}
		}
	}
	delete this->menu;
}

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
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				this->menuPause();
				break;
			case sf::Keyboard::W:
				this->player->keys(sf::Keyboard::W);
				break;
			case sf::Keyboard::A:
				this->player->keys(sf::Keyboard::A);
				break;
			case sf::Keyboard::S:
				this->player->keys(sf::Keyboard::S);
				break;
			case sf::Keyboard::D:
				this->player->keys(sf::Keyboard::D);
				break;
			default:
				break;
			}
			break;
		case sf::Event::KeyReleased:
			break;
		}
	}
}

void Game::update()
{
	//sf::Mouse mouse;
	//std::cout << mouse.getPosition(*window).x << " " << mouse.getPosition(*window).y << std::endl;
	this->pollEvents();
	//print pos of mouse on monitor
	//std::cout << "Absolute mouse pos: " << sf::Mouse::getPosition().x << "\t" << sf::Mouse::getPosition().y;
	//
	////print pos of mouse on window
	//std::cout << "\trel to window: " << sf::Mouse::getPosition(*this->window).x << "\t" << sf::Mouse::getPosition(*this->window).y << std::endl;
	//this->engine_time2 = this->clock->getElapsedTime();
	//std::cout << this->engine_time2.asSeconds() << std::endl;
}

void Game::render()
{
	/*
		Renders game
	*/
	if (this->getFpsTime() > 100.f / this->MAX_FRAMERATE) {
		this->window->clear(sf::Color(0, 120, 80, 255)); //clear old frame with green (green background if nothing drawn)
		//draw game
		this->level->draw(*this->window);
		this->renderPlayer(*this->window);
		//this->renderMenu(*this->window);
		//display game
		this->window->display(); //render new frame

		this->updateFpsTime();
	}
}

void Game::renderPlayer(sf::RenderTarget& target)
{
	target.draw(*this->player);
}

void Game::renderMenu(sf::RenderTarget& target)
{
	target.draw(this->menu->getBody());
	for (auto &text : *this->menu->getMenuText()) {
		target.draw(text);
	}
}

void Game::enter()
{
	switch (this->menu->getSelection())
	{
	case 0: //RESUME
		this->bMenuActive = false;
		break;
	case 1: //SETTINGS - not implemented yet
		break;
	case 2:
		this->bMenuActive = false;
		this->window->close();
		break;
	}
}
