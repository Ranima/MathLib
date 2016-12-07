#pragma once

bool fequals(float lhs, float rhs);
bool Fequals(float lhs, float rhs);

float deg2rad(float deg);
float rad2deg(float rad);
float linearHalf(float x);
float speedInc(float x);
float speedDec(float x);
float Hangle(float x); //need to add
float bounce(float x);
float bounceFlip(float x);
float parabFlip(float x);

float lerp(float start, float end, float alpha);
float quadBezier(float start, float mid, float end, float alpha);
float hermiteSpline(float start, float s_tan,
	float end, float e_tan, float alpha);
float cardinalSpline(float start, float mid, float end,float tightness, float alpha);
float catRomSpline(float start, float mid, float end, float alpha);
float cubicBezier(float start, float mid1, float mid2, float end, float alpha);