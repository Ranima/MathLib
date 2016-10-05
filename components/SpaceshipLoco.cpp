#include "SpaceshipLoco.h"
#include "sfwdraw.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	thrust = 0.0f;
	maxthrust = 100.0f;

	turn = 0.0f;
	maxTurn = 100.0f;
	turnSpeed = 1.0f;

	speed = 10.0f;
}

void SpaceshipLocomotion::doThrust()
{
	if (sfw::getKey('W')) thrust = 1;
}

void SpaceshipLocomotion::doTurn()
{
	if (sfw::getKey('Q')) turn += 1;
	if (sfw::getKey('W')) turn -= 1;
}

void SpaceshipLocomotion::update(Rigidbody & rigidbody, float deltaTime)
{
	doThrust();
	doTurn();

	rigidbody.acceleration.x = 

	thrust = 0.0f;
	turn = 0.0f;
}
