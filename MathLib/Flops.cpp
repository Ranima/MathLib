#include "Flops.h"
#include "vec2.h"
#include "vec3.h"

bool fequals(float lhs, float rhs)
{
	float holder;
	if (lhs > rhs)
		holder = lhs - rhs;
	if (lhs < rhs)
		holder = rhs - lhs;
	if (holder < 0.0000001f)
		return true;
	else
		return false;
}

float deg2rad(float deg)
{
	return 0.0174533 * deg;
}

float rad2deg(float rad)
{
	return 57.2958 * rad;
}


