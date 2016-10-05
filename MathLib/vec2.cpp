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

vec2 Lerp(const vec2 & start, const vec2 & end, float alpha)
{
	return start + alpha * (end - start);
}

vec2 QuadBezier(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha)
{
	vec2 mid1 = Lerp(start, mid, alpha);
	vec2 mid2 = Lerp(mid, end, alpha);
	return Lerp(mid1, mid2, alpha);
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
	vec2 mid1 = Lerp(start, midA, alpha);
	vec2 mid2 = Lerp(midA, midB, alpha);
	vec2 mid3 = Lerp(midB, end, alpha);

	vec2 cuBez1 = Lerp(mid1, mid2, alpha);
	vec2 cuBez2 = Lerp(mid2, mid3, alpha);

	return Lerp(cuBez1, cuBez2, alpha);
}
