#include "Game.h"




Game::Game() {
	this->initPromenne();
	this->initWindow();
}

Game::~Game() {
	delete this->okno;
}

void Game::initPromenne(){
	this->okno = nullptr;
	this->endGame = 0;
}

void Game::initWindow() {
	this->videoMod = sf::VideoMode(1280, 720);
	this->okno = new sf::RenderWindow(this->videoMod, "Moje hra 2", sf::Style::Close);
	this->okno->setFramerateLimit(60);
}



const bool Game::bezi() const {
	return this->okno->isOpen();
}

const bool Game::getEndGame() const
{
	if (this->endGame) {
		return true;
	}
	else {
		return false;
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
}

void Game::render(){
	this->okno->clear(sf::Color(20, 20, 20));
	
	this->player.render(this->okno);
	
	this->okno->display();
}
