#pragma once
#include "vec2.h"

class Square
{
private:
	vec2 pointA, pointB, pointC, pointD;
	vec2 midpoint;
public:

	vec2 turret;					//lasers will shoot out of this

	void SquareInit();				//initializes the Square
	void StartPosition(vec2 pos);	//sets start position
	void update();					//updates the square
	void debugDraw();				//gives it visuals
	void testPhysics(bool bob);				//adds forces
	void testController();			//allows player movement
};

class line
{
public:
	vec2 endA, endB;
};