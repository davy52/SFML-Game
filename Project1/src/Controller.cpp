#include "Controller.h"

void Controller::move_tWorker()
{
	body.time1 = body.EntityClock->getElapsedTime();
	while (bMove) {
		float dt = body.EntityClock->getElapsedTime().asMilliseconds() - body.time1.asMilliseconds();
		dt /= 1000;
		body.time1 = body.EntityClock->getElapsedTime();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			body.vel.x += (-body.getMaxVel().x * body.get_acc().x * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			body.vel.x += (body.getMaxVel().x * body.get_acc().x * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			body.vel.y += (-body.getMaxVel().y * body.get_acc().y * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			body.vel.y += (body.getMaxVel().y * body.get_acc().y * dt);
		}


		//cap speed
		if (body.vel.x > body.getMaxVel().x) {
			body.vel.x = body.getMaxVel().x;
		}
		else if (body.vel.x < -body.getMaxVel().x) {
			body.vel.x = -body.getMaxVel().x;
		}

		if (body.vel.y > body.getMaxVel().y) {
			body.vel.y = body.getMaxVel().y;
		}
		else if (body.vel.y < -body.getMaxVel().y) {
			body.vel.y = -body.getMaxVel().y;
		}

		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void Controller::start_movement()
{
	this->bMove = true;
	this->movement = std::thread(&Controller::move_tWorker, this);
}

void Controller::stop_movement()
{
	this->bMove = false;
	this->movement.join();
}
