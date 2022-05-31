#include "Game.h"


Game::Game() {
	this->initPromenne();
	this->initWindow();
}

Game::~Game() {
	delete this->okno;
}

void Game::initPromenne(){
	this->endGame = 0;
	this->spawnTimerMax = 60;
	this->spawnTimer = spawnTimerMax;
	this->maxSwagBalls = 10;
}

void Game::initWindow() {
	this->videoMod = sf::VideoMode(1280*0.85, 1024*0.85);
	this->okno = new sf::RenderWindow(this->videoMod, "Moje hra 2", sf::Style::Close);
	this->okno->setFramerateLimit(60);
}



bool Game::bezi() {
	return this->okno->isOpen();
}

bool Game::getEndGame() {
	return this->endGame;
}

void Game::spawnSwagBalls() {
	if (this->spawnTimer < this->spawnTimerMax) {
		this->spawnTimer += 1.f;
	}
	else {
		if (this->koule.size()<this->maxSwagBalls) {
			this->spawnTimer = 0.f;
			this->koule.push_back(SwagBall(*this->okno));
		}
	}
}

void Game::pollEvents() {
	while (this->okno->pollEvent(this->udalost)) {
		switch (this->udalost.type) {
		case sf::Event::Closed:
			this->okno->close();
			break;
		case sf::Event::KeyPressed:
			if (this->udalost.key.code == sf::Keyboard::Escape) {
				this->okno->close();
			}
			break;
		}
	}
}

void Game::updateMouse() {
	this->mousePosWindow = sf::Mouse::getPosition(*this->okno);
	this->mousePosView = this->okno->mapPixelToCoords(this->mousePosWindow);
}

void Game::update() {
	this->pollEvents();
	this->updateMouse();
	this->spawnSwagBalls();
	this->player.upate(this->okno);
	this->ball.update();
}

void Game::render(){
	this->okno->clear(sf::Color(20, 20, 20));
	for (auto i : koule) {
		i.render(*this->okno);
	}
	
	this->player.render(this->okno);
	this->okno->display();
}
