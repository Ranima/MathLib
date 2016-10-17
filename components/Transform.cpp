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

mat3 Transform::getLocalTransform() const
{
	mat3 S = Scale(m_scale);
	mat3 T = translate(m_position);
	mat3 R = rotation(m_facing);
	return T*S*R;
}

void Transform::debugDraw(const mat3 &T) const
{
	

	mat3 L = T * getLocalTransform();

	vec3 pos = L[2];



	vec3 right = L * vec3{ 10,0,0 };
	vec3 up    = L * vec3{ 0,10,0 };

	

	/*vec2 dirEnd = m_position + getDirection() * m_scale.x * 4;
	vec2 upEnd = m_position + getUp() * m_scale.y * 4;*/

	sfw::drawLine(pos.x, pos.y, right.x, right.y, RED);
	sfw::drawLine(pos.x, pos.y, up.x, up.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, 12, 12, 0x888888FF);
	//sfw::drawLine(m_position.x, m_position.y, dirEnd.x, dirEnd.y, RED);
	//sfw::drawLine(m_position.x, m_position.y, upEnd.x, upEnd.y, GREEN);



}
