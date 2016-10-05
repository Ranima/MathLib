#pragma once

#include "vec2.h"

class Transform
{
public:
	Transform(float x = 0, float y = 0,
		float w = 1, float h = 1, float a = 0);

	vec2 position;
	vec2 scale;
	float facing;

	vec2 getDirection() const;
	void setDirection(const vec2 &dir);

	void debugDraw() const;
};