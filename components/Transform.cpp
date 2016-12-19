#include "Transform.h"
#include "sfwdraw.h"


Transform::Transform(float xPos, float yPos, float xScale, float yScale,
	float facing)
{
	m_position.x = xPos;
	m_position.y = yPos;

	m_scale.x = xScale;
	m_scale.y = yScale;

	m_facing = facing;
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

vec2 Transform::getDirection() const
{
	return fromAngle(m_facing);
}

void Transform::setDirection(const vec2 & dir)
{
	m_facing = angle(dir);
}

vec2 Transform::getGlobalPosition() const
{
	return getGlobalTransform()[2].xy;
}

vec2 Transform::getGlobalright() const
{
	return getGlobalTransform()[0].xy;
}

vec2 Transform::getGlobalUp() const
{
	return getGlobalTransform()[1].xy;
}

float Transform::getGlobalAngle() const
{
	return angle(getGlobalright());
}

mat3 Transform::getGlobalTransform() const
{
	if (m_parent == nullptr)
		return getLocalTransform();
	else
		return m_parent->getGlobalTransform() * getLocalTransform();
}

mat3 Transform::getLocalTransform() const
{
	mat3 S = scale(m_scale);
	mat3 T = translate(m_position);
	mat3 R = rotation(m_facing);
	return T*S*R;
}

void Transform::debugDraw(const mat3 &T) const
{
	

	mat3 L = T * getGlobalTransform();

	vec3 pos = L[2];
	vec3 sgp = m_parent ? m_parent->getGlobalTransform()[2] : pos;

	vec3 right = L * vec3{ 10,0,1 };
	vec3 up    = L * vec3{ 0,10,1 };

	/*mat3 test = L;

	test = rotation(deg2rad(-90)) * translate(10, 0);

	sfw::drawLine(pos.x, pos.y, test.mama[2][0],
								test.mama[2][1], WHITE);

	test = rotation(deg2rad(45)) * translate(4, 0);

	sfw::drawLine(pos.x, pos.y, test.mama[2][0],
				test.mama[2][1], WHITE);*/

	/*vec2 dirEnd = m_position + getDirection() * m_scale.x * 4;
	vec2 upEnd = m_position + getUp() * m_scale.y * 4;*/

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);
	sfw::drawLine(sgp.x, sgp.y, pos.x, pos.y, BLUE);

	sfw::drawCircle(pos.x, pos.y, 12, 12U, 0x888888FF);
	//sfw::drawCircle(up.x, up.y, 12, 12, 0x888888FF);

	//sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, RED);
	//sfw::drawLine(m_position.x, m_position.y, upEnd.x, upEnd.y, GREEN);



}