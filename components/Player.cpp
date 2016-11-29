#include "Player.h"
#include "sfwdraw.h"

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

}