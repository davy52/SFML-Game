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

		body.move(body.vel);

		//collision detection
		sf::Vector2f bPos = body.getPosition();
		sf::Vector2f bSize = body.getSize();

		sf::Vector2f tPos = sf::Vector2f(0, 0);
		float tSize = 16 * tiles[0].getScale().x; //wszytkie kafelki planowo maja byc 16x16 to nie powinno sie zmienic (mam nadzieje)
		
		int collFlags[2] = { 0, 0 }; //left, right, up, down

		for (Tile tile : tiles) {
			collFlags[0] = 0;
			collFlags[1] = 0;
			tPos = tile.getPosition();
			if (tPos.x > bPos.x && tPos.x < bPos.x + bSize.x) {
				//body.move(sf::Vector2f( tPos.x - (bPos.x + bSize.x) , 0.f));
				collFlags[0] = 1; // (1 << 3);
			}
			else if (tPos.x < bPos.x && tPos.x + tSize > bPos.x) {
				//body.move(sf::Vector2f((bPos.x + bSize.x) - tPos.x, 0.f));
				collFlags[0] = -1; // (1 << 2);
			}
			if (tPos.y > bPos.y && tPos.y < bPos.y + bSize.y) {
				//body.move( sf::Vector2f( 0.f, tPos.y - (bPos.y + bSize.y)));
				collFlags[1] = 1; // (1 << 1);
			}
			else if (tPos.y < bPos.y && tPos.y + tSize > bPos.y) {
				//body.move(sf::Vector2f(0.f, (bPos.y + bSize.y) - tPos.y));
				collFlags[1] = -1; // (1 << 0);
			}


			if (collFlags[0] == 1 && collFlags[1] == 1) {
				if (tPos.x - (bPos.x + bSize.x) <= tPos.y - (bPos.y + bSize.y))
					body.move(sf::Vector2f(tPos.x - (bPos.x + bSize.x), 0.f));
				else
					body.move(sf::Vector2f(0.f, tPos.y - (bPos.y + bSize.y)));
			}
			else if (collFlags[0] == 1 && collFlags[1] == -1 ) {
				if (tPos.x - (bPos.x + bSize.x) <= (bPos.y + bSize.y) - tPos.y)
					body.move(sf::Vector2f(tPos.x - (bPos.x + bSize.x), 0.f));
				else
					body.move(sf::Vector2f(0.f, (bPos.y + bSize.y) - tPos.y));
			}
			else if (collFlags[0] == -1 && collFlags[1] == 1 ) {
				if ((bPos.x + bSize.x) - tPos.x <= tPos.y - (bPos.y + bSize.y))
					body.move(sf::Vector2f((bPos.x + bSize.x) - tPos.x, 0.f));
				else
					body.move(sf::Vector2f(0.f, tPos.y - (bPos.y + bSize.y)));
			}
			else if (collFlags[0] == -1 && collFlags[1] == -1) {
				if((bPos.x + bSize.x) - tPos.x <= (bPos.y + bSize.y) - tPos.y)
					body.move(sf::Vector2f((bPos.x + bSize.x) - tPos.x, 0.f ));
				else
					body.move(sf::Vector2f( 0.f, (bPos.y + bSize.y) - tPos.y));
			}

		}

		std::this_thread::sleep_for(std::chrono::milliseconds(1));	// watek nie musi bez przerwy pracowac, ma malo do zrobienia wiec nic nie szkodzi spowolnienie go pamietajac ze powinien wykonac co najmniej jedna petle co klatke
	}																// niestety zalezne jest to od mocy obliczeniowej procesora
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
