#pragma once

struct vec2
{
	float x, y;
};

vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);

vec2 operator*(const vec2 &lhs, float rhs);
vec2 operator*(float rhs, const vec2 &lhs);

vec2 operator/(const vec2 &lhs, float rhs);

bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

float magnitude(const vec2 &v);

vec2 normal(const vec2 &v);

vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, const vec2 &rhs);

float dot(const vec2 &rhs, const vec2 &lhs);
float angleBetween(const vec2 &rhs, const vec2 &lhs);

//2d only
vec2 perp(const vec2 &v);

float angle(const vec2 &v);

vec2 fromAngle(float a);

vec2 Lerp(const vec2 &start, const vec2 & end, float alpha);
vec2 QuadBezier(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha);
vec2 HermiteSpline(const vec2 & start, const vec2 & s_tan,
	const vec2 & end, const vec2 & e_tan, float alpha);
vec2 CardinalSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float tightness, float alpha);
vec2 CatRomSpline(const vec2 & start, const vec2 & mid, const vec2 & end, float alpha);
vec2 CubicBezier(const vec2 & start, const vec2 & midA, const vec2 & midB, const vec2 & end, float alpha);