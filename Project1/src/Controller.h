#pragma once
#include <thread>
#include <chrono>

#include "Entity.h"



class Controller
{
private:
	Player& body;

	bool bMove = false;
	//threads:
	std::thread movement;

public:
	Controller(Player& body) : body(body) {};
	void move_tWorker();


	void start_movement();
	void stop_movement();


};

