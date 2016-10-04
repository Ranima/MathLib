#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform()
{
	position.x = 0;
	position.y = 0;

	scale.x = 28;
	scale.y = 0;

	facing = 0;
}

Transform::Transform(float x, float y)
{
	position.x = x;
	position.y = y;
}

vec2 Transform::getDirection()
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw()
{
	sfw::drawCircle(position.x, position.y, 26);

	facing = facing + 1 * sfw::getDeltaTime();

	vec2 dirEnd = position + getDirection() * scale.x;
	vec2 upEnd = position - getDirection() * scale.y;

	

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);

	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);

	//sfw::drawLine(position.x, position.y, x, y, BLUE);
}
