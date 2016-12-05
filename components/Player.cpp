#include "Player.h"
#include "sfwdraw.h"
#include "Flops.h"

void Square::SquareInit()
{
	pointA = midpoint + vec2{ -20, -20 };
	pointB = midpoint + vec2{ -20, 20 };
	pointC = midpoint + vec2{ 20, 20 };
	pointD = midpoint + vec2{ 20, -20 };
	/*if (midpoint.y < 250)
		turret = midpoint + vec2{ 0, 30 };
	if (midpoint.y > 250)
		turret = midpoint - vec2{ 0, 30 };*/
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
	/*if (midpoint.y < 250)
		turret = midpoint + vec2{ 0, 30 };
	if (midpoint.y > 250)
		turret = midpoint - vec2{ 0, 30 };*/
}

void Square::debugDraw()
{
	sfw::drawLine(pointA.x, pointA.y, pointB.x, pointB.y, WHITE );
	sfw::drawLine(pointB.x, pointB.y, pointC.x, pointC.y, WHITE);
	sfw::drawLine(pointC.x, pointC.y, pointD.x, pointD.y, WHITE);
	sfw::drawLine(pointD.x, pointD.y, pointA.x, pointA.y, WHITE);
	
	/*if (midpoint.y < 250)
		{sfw::drawLine(pointB.x, pointB.y, turret.x, turret.y, WHITE);
		sfw::drawLine(pointC.x, pointC.y, turret.x, turret.y, WHITE);}
	if (midpoint.y < 250)
		{sfw::drawLine(pointA.x, pointA.y, turret.x, turret.y, WHITE);
		sfw::drawLine(pointD.x, pointD.y, turret.x, turret.y, WHITE);}*/
}

void Square::testPhysics(int YStart)
{
	float deltaTime = sfw::getDeltaTime();
	int DeltaTime = sfw::getDeltaTime();
	midpoint.y = YStart;
	if (midpoint.x > 0)
		{midpoint.x = midpoint.x - (midpoint.x * deltaTime) + 6.6;}
	if (midpoint.x < 0)
		{midpoint.x = midpoint.x + (midpoint.x * deltaTime) + 6.6;}
}

void Square::testController()
{
	if (midpoint.y < 250)
	{
		if (sfw::getKey('D') == true)
			{midpoint.x = midpoint.x + 320.f * sfw::getDeltaTime();}
		if (sfw::getKey('A') == true)
			{midpoint.x = midpoint.x - 320.f * sfw::getDeltaTime();}
		if (sfw::getKey('W') == true)
			{}
		if (sfw::getKey('S') == true)
			{}
	}

	if (midpoint.y > 250)
	{
		if (sfw::getKey(KEY_RIGHT) == true)
			{midpoint.x = midpoint.x + 320.f * sfw::getDeltaTime();}
		if (sfw::getKey(KEY_LEFT) == true)
			{midpoint.x = midpoint.x - 320.f * sfw::getDeltaTime();}
		if (sfw::getKey(KEY_UP) == true)
			{}
		if (sfw::getKey(KEY_DOWN) == true)
			{}
	}
}
