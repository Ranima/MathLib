#pragma once

#include "vec2.h"
#include "matrix3.h"

class Transform
{
public:

	vec2 m_position;
	vec2 m_scale;
	float m_facing;

	Transform(float x = 0, float y = 0,
		float w = 1, float h = 1, float a = 0);

	//vec2 position;
	//vec2 scale;
	//float facing;

	vec2 getUp() const;
	vec2 getDirection() const;
	void setDirection(const vec2 &dir);


	mat3 getLocalTransform() const;

	void debugDraw(const mat3 &T = mat3identity()) const;
};