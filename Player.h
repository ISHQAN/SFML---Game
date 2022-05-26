#pragma once
#include "common.h"
#include <iostream>
#include <vector>
#include <ctime>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Game.h"

class Player {
private:
	sf::RectangleShape shape;

	void initPromenne();
	void initShape();

public:
	Player();
	virtual ~Player();

	void upate();
	void render(sf::RenderTarget* target);
};

