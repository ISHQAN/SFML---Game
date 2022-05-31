#include "common.h"
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