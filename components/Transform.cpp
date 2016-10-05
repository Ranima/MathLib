#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y, float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
}

vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 & dir)
{
	facing = angle(dir);
}

void Transform::debugDraw() const
{
	sfw::drawCircle(position.x, position.y, 12,12,0x888888FF);

	vec2 dirEnd = position + getDirection() * scale.x;
	vec2 upEnd = position - getDirection() * scale.y;

	sfw::drawLine(position.x, position.y, dirEnd.x, dirEnd.y, RED);

	sfw::drawLine(position.x, position.y, upEnd.x, upEnd.y, GREEN);

	//sfw::drawLine(position.x, position.y, x, y, BLUE);
}
