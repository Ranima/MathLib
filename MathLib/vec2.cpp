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

vec2 operator-(const vec2 & vec)
{
	float x = vec.x - (vec.x * 2);
	float y = vec.y - (vec.y * 2);
	vec2 retval{ x,y };
	return retval;
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
	return vec2{ v.y, -v.x };
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

vec2 lerp(const vec2 & start, const vec2 & end, float alpha)
{
	return start + alpha * (end - start);
}

vec2 QuadBezier(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	vec2 mid1 = lerp(start, mid, alpha);
	vec2 mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}

vec2 HermiteSpline(const vec2 & start, const vec2 & s_tan, const vec2 & end, const vec2 & e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10*s_tan + h01*end + h11*e_tan;
}

vec2 CardinalSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float tightness, float alpha)
{
	vec2 s_tan = (mid - start)*tightness,
		e_tan = (end - mid)*tightness;

	return HermiteSpline(start, s_tan, end, e_tan, alpha);
}

vec2 CatRomSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	return CardinalSpline(start, mid, end, 0.5, alpha);
}

vec2 CubicBezier(const vec2 & start, const vec2 & midA, const vec2 & midB, const vec2 & end, float alpha)
{
	vec2 mid1 = lerp(start, midA, alpha);
	vec2 mid2 = lerp(midA, midB, alpha);
	vec2 mid3 = lerp(midB, end, alpha);

	vec2 cuBez1 = lerp(mid1, mid2, alpha);
	vec2 cuBez2 = lerp(mid2, mid3, alpha);

	return lerp(cuBez1, cuBez2, alpha);
}

float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

float & vec2::operator[](unsigned idx)
{
	return v[idx];
}
