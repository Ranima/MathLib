#include "Player.h"
#include "sfwdraw.h"
#include "Flops.h"

void Square::SquareInit()
{
	pointA = midpoint + vec2{ -20, -20 };
	pointB = midpoint + vec2{ -20, 20 };
	pointC = midpoint + vec2{ 20, 20 };
	pointD = midpoint + vec2{ 20, -20 };
}

void Square::StartPosition(vec2 pos)
{
	midpoint = pos;
}

void Square::update()
{
	pointA = midpoint + vec2{ -20, -20 };
	pointB = midpoint + vec2{ -20, 20 };
	pointC = midpoint + vec2{ 20, 20 };
	pointD = midpoint + vec2{ 20, -20 };
}

void Square::debugDraw()
{
	sfw::drawLine(pointA.x, pointA.y, pointB.x, pointB.y, WHITE );
	sfw::drawLine(pointB.x, pointB.y, pointC.x, pointC.y, WHITE);
	sfw::drawLine(pointC.x, pointC.y, pointD.x, pointD.y, WHITE);
	sfw::drawLine(pointD.x, pointD.y, pointA.x, pointA.y, WHITE);
}

void Square::testPhysics()
{
	bool bob = false;
	float deltaTime = sfw::getDeltaTime();
	int DeltaTime = sfw::getDeltaTime();
	midpoint.y = midpoint.y - (midpoint.y * deltaTime)+.5;
	/*if (fequals(DeltaTime % 2, 1))
		{bob = !bob;}
	if (bob == true)
		{midpoint.y = midpoint.y + 80.f * deltaTime;}
	else if (bob == false)
		{}*/
}

void Square::testController()
{
	if (sfw::getKey('D') == true)
		{midpoint.x = midpoint.x + 80.f * sfw::getDeltaTime();}
	if (sfw::getKey('A') == true)
		{midpoint.x = midpoint.x - 80.f * sfw::getDeltaTime();}
	if (sfw::getKey('W') == true)
		{midpoint.y = midpoint.y + 80.f * sfw::getDeltaTime();}
	if (sfw::getKey('S') == true)
		{midpoint.y = midpoint.y - 10.f * sfw::getDeltaTime();}
}
