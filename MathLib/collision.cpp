#include "collision.h"
#include <cmath>

#include <cassert>

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

bool CollisionData1D::result() const
		{return penetrationDepth >= 0;}

float CollisionData1D::MTV() const
		{return penetrationDepth * collisionNormal;}

bool sweptCollisionData1D::result() const
		{return entryTime >= 0 && entryTime <= 1;}

CollisionData boxCollision(const AABB & A, const vec2 & dA, const AABB & B)
{
	CollisionData retval;

	CollisionData1D XCD =
		collisionDetection1D(A.min().x, A.max().x,
			B.min().x, B.max().x);

	CollisionData1D YCD =
		collisionDetection1D(A.min().y, A.max().y,
			B.min().y, B.max().y);

	if (XCD.penetrationDepth < YCD.penetrationDepth)
	{
		retval.penetrationDepth = XCD.penetrationDepth;
		retval.collisionNormal =
			vec2{ 0,1 } * XCD.collisionNormal;
	}
	else
	{
		retval.penetrationDepth = YCD.penetrationDepth;
		retval.collisionNormal =
			vec2{ 0,1 } * YCD.collisionNormal;
	}
	return retval;
}

CollisionDataSwept boxCollisionSwept(const AABB & A, const vec2 & dA, const AABB & B, const vec2 & dB)
{
	CollisionDataSwept retval;

	CollisionData1D Xdis = collisionDetection1D(A.min().x, A.max().x, B.min().x, B.max().x);
	CollisionData1D Ydis = collisionDetection1D(A.min().y, A.max().y, B.min().y, B.max().y);

	sweptCollisionData1D Xres = sweptDetection1D(A.min().x, A.max().x, dA.x,
		B.min().x, B.max().x, dB.x);

	sweptCollisionData1D Yres = sweptDetection1D(A.min().y, A.max().y, dA.y,
		B.min().y, B.max().y, dB.y);

	bool xSwept = (dA.x - dB.x != 0);
	bool ySwept = (dA.y - dB.y != 0);

	if (Yres.entryTime < Xres.entryTime || xSwept && !ySwept)
	{
		retval.collisionNormal = vec2{ 1,0 } *Xres.collisionNormal;
		retval.entryTime = Xres.entryTime;
	}

	assert(false && "TODO: this function.");
	return retval;
}

bool CollisionData::result() const
{
	return penetrationDepth >= 0;
}

vec2 CollisionData::MTV() const
{
	return collisionNormal * penetrationDepth;
}

bool CollisionDataSwept::result() const
{
	return entryTime >= 0 && entryTime <= 1 && collides;
}
