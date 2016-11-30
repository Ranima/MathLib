#include "Player.h"
#include "sfwdraw.h"
#include "Flops.h"

void Square::SquareInit()
{
	pointA = midpoint + vec2{ -20, -20 };
	pointB = midpoint + vec2{ -20, 20 };
	pointC = midpoint + vec2{ 20, 20 };
	pointD = midpoint + vec2{ 20, -20 };
	turret = midpoint + vec2{ 0, 30 };
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
	turret = midpoint + vec2{ 0, 30 };
}

void Square::debugDraw()
{
	sfw::drawLine(pointA.x, pointA.y, pointB.x, pointB.y, WHITE );
	sfw::drawLine(pointB.x, pointB.y, pointC.x, pointC.y, WHITE);
	sfw::drawLine(pointC.x, pointC.y, pointD.x, pointD.y, WHITE);
	sfw::drawLine(pointD.x, pointD.y, pointA.x, pointA.y, WHITE);
	
	sfw::drawLine(pointB.x, pointB.y, turret.x, turret.y, WHITE);
	sfw::drawLine(pointC.x, pointC.y, turret.x, turret.y, WHITE);
}

void Square::testPhysics(bool bob)
{
	float deltaTime = sfw::getDeltaTime();
	int DeltaTime = sfw::getDeltaTime();
	midpoint.y = midpoint.y - (midpoint.y * deltaTime)+.5;
	if (Fequals(DeltaTime % 1, 0))
		{bob = !bob;}
	if (bob == true)
		{midpoint.y = midpoint.y + 40.f * deltaTime;}
	else if (bob == false)
		{midpoint.y = midpoint.y - 20.f * deltaTime;}
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
