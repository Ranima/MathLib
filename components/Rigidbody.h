#pragma once

#include "vec2.h"

#include "Transform.h"

class Rigidbody
{
public:
	Rigidbody();

	float mass, drag, angularDrag;

	vec2 impulse;
	vec2 force;
	vec2 velocity;
	vec2 acceleration;

	float angularVelocity;
	float angularAcceleration;
	float torque;

	void addForce(const vec2 &a_force);
	void addImpulse(const vec2 &a_impulse);
	void addTorque(float a_torque);

	void integrate(Transform &trans, float deltaTime);

	void debugDraw(const mat3& T, const Transform &trans);
};