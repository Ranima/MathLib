#pragma once

#include "Player.h"

class GameState
{
public:
	Square player1;
	Square player2;

	Projectile player1proj;
	Projectile player2proj;

	void init();
	void update(float deltaTime);
	void draw();
	void exit();
};
