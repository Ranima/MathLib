#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotion
{
	float vertThrust;
	float horzthrust;

	SpaceshipLocomotion();

	float thrust;
	float maxthrust;

	float turn;
	float maxTurn;
	float turnSpeed;

	float speed;

public:
	void doThrust(float x);
	void doTurn(float x);

	void update(Rigidbody &rigidbody, float deltaTime);
};