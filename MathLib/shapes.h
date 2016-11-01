#pragma once
#include "matrix3.h"

struct Circle
{
	vec2 pos;
	float rad;
};

Circle operator*(const mat3 &T, const Circle &C);
bool operator==(const Circle &A, const Circle &B);

struct AABB
{
	vec2 pos,
		he;

	vec2 min() const;
	vec2 max() const;
};

AABB operator*(const mat3 &T, const AABB &box);
bool operator==(const AABB &A, const AABB &B);

struct Plane
{
	vec2 pos, dir;
};

Plane operator*(const mat3 &T, const Plane &P);
bool operator==(const Plane &A, const Plane &B);

struct Ray  { };
struct Hull { };