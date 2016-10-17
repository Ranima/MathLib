#include "Flops.h"
#include "vec2.h"
#include "vec3.h"
#include <cmath>

bool fequals(float lhs, float rhs)
{
	float holder = abs(lhs - rhs);

	if (holder < 0.0001f)
		return true;
	else
		return false;
}

float deg2rad(float deg)
{
	return 0.0174533 * deg;
}

float rad2deg(float rad)
{
	return 57.2958 * rad;
}

float linearHalf(float x)
{
	float retval = 0.5f*(x);
	return retval;
}

float speedInc(float x)
{
	return x*x*x*x;
}

float speedDec(float x)
{
	return 1 - speedInc(1 - x);
}

float hAngle(float x)
{
	return x < 0.5 ? 2 * x : -2 * (x - 1);
}

float bounce(float x)
{
	return abs(cos(x * 10)*(1 - x));
}

float bounceFlip(float x)
{
	return 1 - bounce(x);
}

float parabFlip(float x)
{
	/*float a = -3;
	float b = 100;
	float c = 500;
	return a*(x*x) + b*x + c;*/
	return 1 - (2 * x - 1)*(2 * x - 1);
}

float lerp(float start, float end, float alpha)
{
	return start + alpha * (end - start);
}

float quadBezier(float start, float mid, float end, float alpha)
{
	float mid1 = lerp(start, mid, alpha);
	float mid2 = lerp(mid, end, alpha);
	return lerp(mid1, mid2, alpha);
}

float hermiteSpline(float start, float s_tan, float end, float e_tan, float alpha)
{
	float tsq = alpha*alpha;
	float tcub = tsq*alpha;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + alpha;
	float h11 = tcub - tsq;

	return h00 * start + h10*s_tan + h01*end + h11*e_tan;
}

float cardinalSpline(float start, float mid, float end,float tightness, float alpha)
{
	float s_tan = (mid - start)*tightness,
		e_tan = (end - mid)*tightness;

	return hermiteSpline(start, s_tan, end, e_tan, alpha);
}

float catRomSpline(float start, float mid, float end, float alpha)
{
	return cardinalSpline(start,mid,end,0.5,alpha);
}

float cubicBezier(float start, float midA, float midB, float end, float alpha)
{
	float mid1 = lerp(start, midA, alpha);
	float mid2 = lerp(midA, midB, alpha);
	float mid3 = lerp(midB, end, alpha);

	float cuBez1 = lerp(mid1, mid2, alpha);
	float cuBez2 = lerp(mid2, mid3, alpha);
	
	return lerp(cuBez1, cuBez2, alpha);
}
