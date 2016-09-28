#include "vec2.h"
#include <math.h>
#include "Flops.h"

vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x + rhs.x, lhs.y + rhs.y};
}

vec2 operator*(const vec2 & lhs, float rhs)
{
	return vec2{lhs.x * rhs, lhs.y * rhs};
}

vec2 operator*(float rhs, const vec2 & lhs)
{
	return vec2{ rhs * lhs.x, rhs * lhs.y };
}

vec2 operator/(const vec2 & lhs, float rhs)
{
	return vec2{lhs.x / rhs, lhs.y / rhs};
}

vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	return vec2{ lhs.x - rhs.x, lhs.y - rhs.y };
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{ lhs.x * rhs.x, lhs.y * rhs.y};
}

vec2 operator/(const vec2 & lhs, const vec2 & rhs)
{
	return vec2{lhs.x / rhs.x, lhs.y / rhs.y};
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs + rhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs - rhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs * rhs;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	return lhs = lhs / rhs;
}

float dot(const vec2 & rhs, const vec2 & lhs)
{
	return rhs.x * lhs.x + rhs.y * lhs.y;
}

vec2 normal(const vec2 & v)
{
	vec2 retval = v / magnitude(v);
	return retval;
}

float angleBetween(const vec2 & rhs, const vec2 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}

vec2 perp(const vec2 & v)
{
	return vec2{ -v.x,v.y };
}

float angle(const vec2 & v)
{
	return atan2f(v.x,v.y);
}

vec2 fromAngle(float a)
{
	return vec2{cosf(a),sinf(a)};
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	return fequals(lhs.x,rhs.x) && fequals(lhs.y,rhs.y);
}

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	return bool{lhs.x != rhs.x || lhs.y != rhs.y};
}

float magnitude(const vec2 &v)
{
	return sqrt(v.x*v.x + v.y*v.y);
}

