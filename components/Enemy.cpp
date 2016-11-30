#include "Enemy.h"
#include "sfwdraw.h"
#include "Flops.h"

void Enemy::SquareInit()
{
	pointA = midpoint + vec2{ -10, -10 };
	pointB = midpoint + vec2{ -10, 10 };
	pointC = midpoint + vec2{ 10, 10 };
	pointD = midpoint + vec2{ 10, -10 };
}

void Enemy::StartPosition(vec2 pos)
{
	midpoint = pos;
}

void Enemy::update()
{
	pointA = midpoint + vec2{ -10, -10 };
	pointB = midpoint + vec2{ -10, 10 };
	pointC = midpoint + vec2{ 10, 10 };
	pointD = midpoint + vec2{ 10, -10 };
}

void Enemy::debugDraw()
{
	sfw::drawLine(pointA.x, pointA.y, pointB.x, pointB.y, RED);
	sfw::drawLine(pointB.x, pointB.y, pointC.x, pointC.y, RED);
	sfw::drawLine(pointC.x, pointC.y, pointD.x, pointD.y, RED);
	sfw::drawLine(pointD.x, pointD.y, pointA.x, pointA.y, RED);
}

void Enemy::testPhysics()
{
	bool bob = false;
	float deltaTime = sfw::getDeltaTime();
	int DeltaTime = sfw::getDeltaTime();
	midpoint.y = midpoint.y + (midpoint.y * deltaTime) + .5;
	/*if (fequals(DeltaTime % 2, 1))
	{bob = !bob;}
	if (bob == true)
	{midpoint.y = midpoint.y + 80.f * deltaTime;}
	else if (bob == false)
			{}*/
}

void Enemy::testController()
{

}
