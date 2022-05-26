#include "common.h"
#include <iostream>
#include <vector>
#include <ctime>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "Player.h"



int main() {
	srand(static_cast<unsigned>(time(0)));
	Game hra;


	while (hra.bezi()) {
		hra.update();
		hra.render();
	}

	return 0;
}