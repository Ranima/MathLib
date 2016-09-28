#include "vec3.h"
#include <math.h>

vec3 operator+(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z};
}

vec3 operator-(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z };
}

vec3 operator*(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x * rhs.x, lhs.y * rhs.y, lhs.z * rhs.z };
}

vec3 operator/(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{ lhs.x / rhs.x, lhs.y / rhs.y, lhs.z / rhs.z };
}

vec3 operator*(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator*(float rhs, const vec3 & lhs)
{
	return vec3{ lhs.x * rhs, lhs.y * rhs, lhs.z * rhs };
}

vec3 operator/(const vec3 & lhs, float rhs)
{
	return vec3{ lhs.x / rhs, lhs.y / rhs, lhs.z / rhs };
}

bool operator==(const vec3 & lhs, const vec3 & rhs)
{
	return bool{ lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z };
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return bool{ lhs.x != rhs.x || lhs.y != rhs.y || lhs.z != rhs.z };
}

float magnitude(const vec3 & v)
{
	return sqrt( v.x*v.x + v.y*v.y + v.z*v.z );
}

vec3 normal(const vec3 & v)
{
	vec3 retval = v / magnitude(v);
	return retval;
}

vec3 & operator+=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs + rhs;
}

vec3 & operator-=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs - rhs;
}

vec3 & operator*=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs * rhs;
}

vec3 & operator/=(vec3 & lhs, const vec3 & rhs)
{
	return lhs = lhs / rhs;
}

float dot(const vec3 & rhs, const vec3 & lhs)
{
	return rhs.x * lhs.x + rhs.y * lhs.y + rhs.z * lhs.z;
}

float angleBetween(const vec3 & rhs, const vec3 & lhs)
{
	return acos(dot(normal(rhs), normal(lhs)));
}
