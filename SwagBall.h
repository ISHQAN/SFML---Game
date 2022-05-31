#pragma once

#include "common.h"

class SwagBall {
private:
	sf::CircleShape shape;

	void initShape(const sf::RenderWindow& window);
public:
	SwagBall(const sf::RenderWindow& window);
	virtual ~SwagBall();

	void update();
	void render(sf::RenderTarget& target);
};

