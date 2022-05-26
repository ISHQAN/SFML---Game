#pragma once
#include "common.h"

#include <iostream>
#include <vector>
#include <ctime>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"

class Game {
private:
	//promenne
	sf::RenderWindow* okno;
	sf::Event udalost;
	sf::VideoMode videoMod;

	Player player;


	bool endGame;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;


	//inicializace
	void initPromenne();
	void initWindow();



	void pollEvents();
	void updateMouse();


public:
	//konstruktor a destruktor
	Game();
	virtual ~Game();

	const bool bezi() const;
	const bool getEndGame() const;


	void update();

	void render();
};

