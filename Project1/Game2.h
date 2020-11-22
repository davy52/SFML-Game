#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <string>
class Game2
{
private:
	sf::Event* event;
	sf::RenderWindow* window;
	
	//Inits
	void initVariables();
	void initWindow(int width, int height, std::string title,  int style);

public:
	//Constructor/Destructor
	Game2(int width = 1600, int height = 900, std::string title = "sfml test", int style = sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	~Game2();

	//Accessors
	bool isRunning() const;
	//Setters

	//Functions
	void handleEvents();
	void update();
	void render();
};

