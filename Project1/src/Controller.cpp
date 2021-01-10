#include "Controller.h"
void Controller::move_tWorker()
{

	body.time1 = body.EntityClock->getElapsedTime();
	std::chrono::steady_clock::time_point start = std::chrono::high_resolution_clock::now();
	std::chrono::steady_clock::time_point stop;
	while (bMove) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));


		stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		std::cout << duration.count() << "us" << std::endl;
		start = std::chrono::high_resolution_clock::now();

		float dt = body.EntityClock->getElapsedTime().asMilliseconds() - body.time1.asMilliseconds();
		dt /= 1000;
		body.time1 = body.EntityClock->getElapsedTime();

		if (gState != GAME_STATE::PLAYING) continue;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			//body.vel.x += (-body.getMaxVel().x * body.get_acc().x * dt);
			body.vel.x += (-body.get_acc().x * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			//body.vel.x += (body.getMaxVel().x * body.get_acc().x * dt);
			body.vel.x += (body.get_acc().x * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			//body.vel.y += (-body.getMaxVel().y * body.get_acc().y * dt);
			body.vel.y += (-body.get_acc().y * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			body.vel.y += (body.get_acc().y * dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			this->gState = GAME_STATE::PAUSE;
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
			this->gState = GAME_STATE::F1;
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
		//std::cout << body.getPosition().x << "\t\t" << body.getPosition().y << "\t\tvel:" << body.vel.x << "\t\t" << body.vel.y << std::endl;

		//collision detection
		//std::vector<Tile> collisions;

		if ( body.vel.x != 0 || body.vel.y != 0 ) {
			sf::Vector2f bPos = body.getPosition();
			sf::Vector2f bSize = body.getSize();

			sf::Vector2f tPos = sf::Vector2f(0, 0);
			float tSize = 16 * tiles[0].getScale().x; //wszytkie kafelki planowo maja byc 16x16 to nie powinno sie zmienic (mam nadzieje)

			int collFlags[2] = { 0, 0 };	//left, right, up, down
			std::vector<Tile> CollTiles;	//possible collisions


			//odrzucenie tych plytek ktore na pewno nie beda kolidowaly z graczem
			//zakladam ze predkosc gracza nigdy nie bedzie tak duza aby mogl "przeskoczyc" plytke
			for (Tile tile : tiles) {
				if ( sqrt(pow(tile.getPosition().x - bPos.x, 2) + pow(tile.getPosition().y - bPos.y, 2)) < tSize * 3) {	//jezeli plytka jest dalej od punktu odniesienia gracza niz 2 szerokosci plytek kolizja nie moze nastapic
					CollTiles.push_back(tile);
				}
			}
			bool collided = true;
			while (collided) {
				collided = false;
				for (Tile tile : CollTiles) {
					collFlags[0] = 0;
					collFlags[1] = 0;
					bPos = body.getPosition();
					tPos = tile.getPosition();

					if (tPos.x >= bPos.x && tPos.x < bPos.x + bSize.x) {					//prawo
						//body.move(sf::Vector2f( tPos.x - (bPos.x + bSize.x) , 0.f));
						collFlags[0] = 1;	//prawo
					}
					else if (tPos.x <= bPos.x && tPos.x + tSize > bPos.x) {				//lewo
						//body.move(sf::Vector2f((bPos.x + bSize.x) - tPos.x, 0.f));
						collFlags[0] = -1;	//lewo
					}
					if (tPos.y <= bPos.y && tPos.y + tSize > bPos.y) {					//gora
						//body.move( sf::Vector2f( 0.f, tPos.y - (bPos.y + bSize.y)));
						collFlags[1] = 1;	//gora	
					}
					else if (bPos.y <= tPos.y && tPos.y < bPos.y + bSize.y) {			//dol
						//body.move(sf::Vector2f(0.f, (bPos.y + bSize.y) - tPos.y));
						collFlags[1] = -1;	//dol
					}

					if (collFlags[0] == 1 && collFlags[1] == 1) {			//kolizja prawo-gora
						collided = true;
						
						if ((bPos.x + bSize.x) - tPos.x < (tPos.y + tSize) - bPos.y) {
							body.move(sf::Vector2f(-((bPos.x + bSize.x) - tPos.x), 0));
							body.vel.x = 0;
						}
						else {
							body.move(sf::Vector2f(0, (tPos.y + tSize) - bPos.y));
							body.vel.y = 0;
						}
					}
					else if (collFlags[0] == 1 && collFlags[1] == -1) {		//kolizja prawo-dol
						collided = true;

						if ((bPos.x + bSize.x) - tPos.x < (bPos.y + bSize.y) - tPos.y) {
							body.move(sf::Vector2f(-((bPos.x + bSize.x) - tPos.x), 0));
							body.vel.x = 0;
						}
						else {
							body.move(sf::Vector2f(0, -((bPos.y + bSize.y) - tPos.y)));
							body.vel.y = 0;
						}
					}
					else if (collFlags[0] == -1 && collFlags[1] == 1) {		//kolizja lewo-gora
						collided = true;

						if ((tPos.x + tSize) - bPos.x < (tPos.y + tSize) - bPos.y) {
							body.move(sf::Vector2f((tPos.x + tSize) - bPos.x, 0));
							body.vel.x = 0;
						}
						else {
							body.move(sf::Vector2f(0, (tPos.y + tSize) - bPos.y));
							body.vel.y = 0;
						}
					}
					else if (collFlags[0] == -1 && collFlags[1] == -1) {	//kolizja lewo-dol
						collided = true;

						if ((tPos.x + tSize) - bPos.x < (bPos.y + bSize.y) - tPos.y) {
							body.move(sf::Vector2f((tPos.x + tSize) - bPos.x, 0));
							body.vel.x = 0;
						}
						else {
							body.move(sf::Vector2f(0, -((bPos.y + bSize.y) - tPos.y)));
							body.vel.y = 0;
						}
					}

				}
			}



		}

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


