#pragma once

#include "Rigidbody.h"

class SpaceshipLocomotion
{
	float vertThrust;
	float horzthrust;
	float stopAction;

	float breakPower;
	float maxspeed;
	float turnSpeed;
	float speed;

public:
	SpaceshipLocomotion();

	void doThrust(float x);
	void doTurn(float x);

	void doStop(float value);

	void update(Rigidbody &rigidbody, Transform &trans);
};