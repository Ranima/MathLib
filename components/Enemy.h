#pragma once
#include "vec2.h"

class Enemy
{
private:
	vec2 pointA, pointB, pointC, pointD;
	vec2 midpoint;
public:

	void SquareInit();				//initializes the Square
	void StartPosition(vec2 pos);	//sets start position
	void update();					//updates the square
	void debugDraw();				//gives it visuals
	void testPhysics();				//adds forces
	void testController();			//allows player movement
};