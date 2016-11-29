#pragma once
#include "vec2.h"

class Square
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
};

class line
{
public:
	vec2 endA, endB;
};