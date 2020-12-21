#pragma once
#include <thread>
#include <chrono>
#include <bitset>

#include "Entity.h"
#include "Level.h"



class Controller
{
private:
	Player& body;
	std::vector<Tile> tiles;

	bool bMove = false;
	//threads:
	std::thread movement;

public:
	Controller(Player& body, std::vector<Tile> tiles) : body(body), tiles(tiles) {};
	void move_tWorker();


	void start_movement();
	void stop_movement();

	//float swptAABB(Entity b1, Tile b2, float& normalx, float& normaly);

};

