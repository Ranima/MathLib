#include "vec3.h"
#include <math.h>

#include "Flops.h"

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
	return  fequals(lhs.x, rhs.x) &&
			fequals(lhs.y, rhs.y) &&
			fequals(lhs.z, rhs.z);
}

bool operator!=(const vec3 & lhs, const vec3 & rhs)
{
	return !(lhs == rhs);
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

vec3 cross(const vec3 & lhs, const vec3 & rhs)
{
	return vec3{lhs.y*rhs.z - lhs.z*rhs.y,
				lhs.z*rhs.x - lhs.x*rhs.z,
				lhs.x*rhs.y - lhs.y*rhs.x};
}

float vec3::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec3::operator[](unsigned idx)
{
	return v[idx];
}
