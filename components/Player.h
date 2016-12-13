#pragma once
#include "vec2.h"
#include "Projectile.h"

class Square
{
private:
	vec2 pointA, pointB, pointC, pointD;
	int x;
public:
	//vec2 turret;					//lasers will shoot out of this
	vec2 midpoint;
	float force;

	void SquareInit();				//initializes the Square
	void StartPosition(vec2 pos);	//sets start position
	void update(float deltaTime, class GameState& gameState);					//updates the square
	void debugDraw();				//gives it visuals
	void testPhysics(int YStart);				//adds forces
	void testController();			//allows player movement

	int id;	// 0 is player 1, 1 is player 2

	bool isFiring;
};

class line
{
public:
	vec2 endA, endB;
};