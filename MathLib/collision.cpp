#include "collision.h"
#include <cmath>

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;

	float pDr = Bmax - Amin;
	float pDl = Amax - Bmin;

	retval.penetrationDepth = fmin(pDr, pDl);

	retval.collisionNormal = fmin(pDr, pDl);

	return retval;
}

sweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
	float Bmin, float Bmax, float Bvel)
{
	sweptCollisionData1D retval;

	float t1 = (Amin - Bmax) / (Bvel - Avel);
	float tr = (Bmin - Amax) / (Avel - Bvel);

	retval.collisionNormal = copysignf(1, t1 - tr);

	return retval;
}
