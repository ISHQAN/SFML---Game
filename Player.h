#pragma once
#include "common.h"

//#include "Game.h"		// -> zp�sobuje, �e se vkl�d�n� cykl� + to nem� v�znam

class Player {
private:
	sf::RectangleShape shape;

	float movementSpeed;

	void initPromenne();
	void initShape();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void updateWindowBoundsCollisions(const sf::RenderTarget* target);
	void upate(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};