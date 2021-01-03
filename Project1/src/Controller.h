#pragma once
#include <thread>
#include <chrono>
#include <bitset>
#include <iostream>

#include "Entity.h"
#include "Level.h"



class Controller
{
private:
	Player& body;
	std::vector<Tile> tiles;
	bool& PAUSE;

	bool bMove = false;
	//threads:
	std::thread movement;

public:
	Controller(Player& body, std::vector<Tile> tiles, bool& pause) : body(body), tiles(tiles), PAUSE(pause) {};
	void move_tWorker();


	void start_movement();
	void stop_movement();

	float sweptAABB(Entity player, Tile tile, float& normalx, float& normaly);

};

