#pragma once
#include <thread>
#include <chrono>
#include <bitset>
#include <iostream>

#include "Entity.h"
#include "Level.h"

#include "global_structs.h"

class Controller
{
private:
	Player& body;
	std::vector<Tile> tiles;
	bool& PAUSE;
	GAME_STATE& gState;

	bool bMove = false;
	//threads:
	std::thread movement;

public:
	Controller(Player& body, std::vector<Tile> tiles, bool& pause, GAME_STATE& state) : body(body), tiles(tiles), PAUSE(pause), gState(state) {};
	void move_tWorker();


	void start_movement();
	void stop_movement();

	float sweptAABB(Entity player, Tile tile, float& normalx, float& normaly);

};

