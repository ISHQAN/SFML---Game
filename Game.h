#pragma once
#include "SwagBall.h"
#include "common.h"
#include "Player.h"

class Game {
private:
	//promenne
	sf::RenderWindow* okno;
	sf::Event udalost;
	sf::VideoMode videoMod;

	Player player;

	SwagBall ball;
	std::vector <SwagBall> koule;


	bool endGame;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;


	//inicializace
	void initPromenne();
	void initWindow();



	void pollEvents();
	void updateMouse();


public:
	//konstruktor a destruktor
	Game();
	virtual ~Game();

	bool bezi();
	bool getEndGame();

	void spawnSwagBalls();


	void update();

	void render();
};