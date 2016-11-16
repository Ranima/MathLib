#include "shapes.h"
#include <cmath>
#include "Flops.h"

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

AABB operator*(const AABB & box, const mat3 & T)
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

//Ray operator*(const mat3 & T, const Ray & R)
//{
//	return Ray();
//}

Hull operator*(const mat3 & T, const Hull & H)
{
	Hull retval;
	retval.size = H.size;
	for (int i = 0; i < H.size; ++i)
	{
		retval.vertices[i] = (T * vec3{ H.vertices[i].x, H.vertices[i].y,1 }).xy;

		retval.vertices[i] = (T * vec3{ H.normals[i].x, H.normals[i].y, 0 }).xy;
	}
	return retval;
}

bool operator==(const Hull & A, const Hull & B)
{
	bool retval = true;
	
	for (int i = 0; i < 16 && retval == true; ++i)
	{
		if (A.vertices[i] != B.vertices[i] || A.normals[i] != B.normals[i])
			{retval = false;}
	}
	return retval;
}

vec2 AABB::min() const
{
	return pos - he;
}

vec2 AABB::max() const
{
	return pos + he;
}

float Hull::min(const vec2 & axis) const
{
	float amin = INFINITY;
	for (int i = 0; i < size; ++i)
		amin = fminf(dot(axis, vertices[i]), amin);
	return amin;
}

float Hull::max(const vec2 & axis) const
{
	float amin = INFINITY;
	for (int i = 0; i < size; ++i)
		amin = fminf(dot(axis, vertices[i]), amin);
	return amin;
}

Hull::Hull(const vec2 * a_vertices, unsigned vsize)
{
	size = vsize;

	for (int i = 0; i < size && i < 16; ++i)
	{
		vertices[i] = a_vertices[i];
		normals[i] = -perp(normal(a_vertices[(i + 1) % size] 
								- a_vertices[i]));
	}
}

Hull::Hull()
{
}
