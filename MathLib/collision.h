#pragma once
#include "vec2.h"

struct CollisionData1D
{
	bool result;
	float penetrationDepth;
	float collisionNormal;
	float MTV;
};

CollisionData1D collisionDetection1D(float Amin, float Amax,
	float Bmin, float Bmax);

struct sweptCollisionData1D
{
	float entryTime, exitTime;
	float collisionNormal;

	bool result() const;
};

sweptCollisionData1D sweptDetection1D(float Amin, float Amax, float Avel,
	float Bmin, float Bmax, float Bvel);

struct CollisionData
{
	float penetrationDepth;
	vec2 collisionNormal;

	bool result() const;
	vec2 MTV() const;
};

//CollisionData boxCollision(const AABB &A, const)