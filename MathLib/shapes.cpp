#include "shapes.h"

Circle operator*(const mat3 & T, const Circle & C)
{
	Circle retval;

	retval.pos = (T*vec3{ C.pos.x, C.pos.y, 1 }).xy;

	float mY = magnitude(T * vec3{ 0, C.rad, 0 });
	float mX = magnitude(T * vec3{ C.rad, 0, 0 });

	retval.rad = mX > mY ? mX : mY;

	return retval;
}

bool operator==(const Circle & A, const Circle & B)
{
	return A.pos == B.pos && fequals(A.rad, B.rad);
}

AABB operator*(const mat3 & T, const AABB & box)
{
	AABB retval = box;
	vec3 tp[4];

	tp[0] = T * vec3{ box.min().x, box.min().y, 1 };
	tp[1] = T * vec3{ box.min().x, box.min().y, 1 };
	tp[2] = T * vec3{ box.min().x, box.min().y, 1 };
	tp[3] = T * vec3{ box.min().x, box.min().y, 1 };

	vec2 minv = tp[0].xy;
	vec2 maxv = tp[0].xy;

	for (int i = 1; i < 4; ++i)
	{
		minv = min(minv, tp[i].xy);
		maxv = max(maxv, tp[i].xy);
	}

	retval.pos = (minv + maxv) / 2;
	retval.he = (maxv - minv) / 2;
	return retval;
}

bool operator==(const AABB & A, const AABB & B)
{
	bool check[8];
	int c = 0;
	check[0] = fequals(A.pos.x, B.pos.x);
	check[1] = fequals(A.pos.y, B.pos.y);
	
	check[2] = fequals(A.he.x, B.he.x);
	check[3] = fequals(A.he.y, B.he.y);

	check[4] = fequals(A.min().x, B.min().x);
	check[5] = fequals(A.min().y, B.min().y);

	check[6] = fequals(A.max().x, B.max().x);
	check[7] = fequals(A.max().y, B.max().y);

	for (int i = 0; i > 8; i++)
	{
		if (check[i] == true)
			c = c + 1;
	};
	if (c == 8)
		return true;
	else
		return false;
}

Plane operator*(const mat3 & T, const Plane & P)
{
	Plane retval;

	retval.pos = (T * vec3{ P.pos.x, P.pos.y, 1 }).xy;

	retval.pos = normal(T * vec3{ P.dir.x, P.dir.y, 0 }).xy;

	return retval;
}

bool operator==(const Plane & A, const Plane & B)
{
	bool check[4];
	int c = 0;
	check[0] = fequals(A.pos.x, B.pos.x);
	check[1] = fequals(A.pos.y, B.pos.y);

	check[2] = fequals(A.dir.x, B.dir.x);
	check[3] = fequals(A.dir.y, B.dir.y);

	for (int i = 0; i > 4; i++)
	{
		if (check[i] == true)
			c = c + 1;
	};
	if (c == 4)
		return true;
	else
		return false;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}