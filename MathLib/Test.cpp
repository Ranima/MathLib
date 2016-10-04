#include "Test.h"
#include <math.h>

	int donothin(int x)
	{
		return x*x + 2 * x + 5;
	}

	float test_quad(float x)
	{
		return x*x + 2 * x - 7;
	}

	quad_results quad(float a, float b, float c)
	{
		quad_results retval;
		float d = b*b - 4 * a*c;
		/*(-b + sqrt(b * 2 - 4 * a * c)) / 2 * a;
		(-b - sqrt(b * 2 - 4 * a * c)) / 2 * a;*/
		if		(d < 0)  retval.roots = 0;
		else if (d > 0)  retval.roots = 2;
		else if (d == 0) retval.roots = 1;

		retval.left_root	= (-b - sqrt(d)) / (2 * a);
		retval.right_root	= (-b + sqrt(d)) / (2 * a);

		return retval;
	}

	/*float lerp(float start, float end, float t)
	{
		return start + t * (end - start);
	}*/

	float distance(point P1, point P2)
	{
		return sqrt((P1.x - P2.x) * (P1.x - P2.x) + (P1.y - P2.y) * (P1.y - P2.y));
	}

	float inner(point3D P1, point3D P2)
	{
		return (P1.x * P2.x) + (P1.y * P2.y) + (P1.z * P2.z);
	}

	float pointDistance(Plane plane, point3D P)
	{
		return ((plane.a * P.x) + (plane.b * P.y) + (plane.c * P.z) + plane.d);
	}

	float Bcurve(float t, float P0, float P1, float P2, float P3)
	{
		return ((1 - t)*(1 - t)*(1 - t))* P0 + 3 * ((1 - t)*(1 - t)) * t * P1 + 3 * (1 - t) * (t * t) * P2 + (t * t * t) * P3;
	}