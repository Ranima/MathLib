#include "SpaceshipLoco.h"
#include "sfwdraw.h"

SpaceshipLocomotion::SpaceshipLocomotion()
{
	vertThrust = 0.0f;
	horzthrust = 0.0f;
	stopAction = 0.0f;
	breakPower = 0.0f;

	maxspeed = 1000.0f;	
	turnSpeed = 4.0f;
	speed = 900.0f;
}

void SpaceshipLocomotion::doThrust(float x)
{
	vertThrust += x;
}

void SpaceshipLocomotion::doTurn(float x)
{
	horzthrust += x;
}

void SpaceshipLocomotion::doStop(float value)
{
	stopAction += value;
}

void SpaceshipLocomotion::update(Rigidbody & rigidbody, Transform &trans)
{
	rigidbody.addForce(trans.getUp() * speed * vertThrust);
	rigidbody.addTorque(turnSpeed * horzthrust);

	rigidbody.addForce(-rigidbody.velocity * breakPower * stopAction);
	rigidbody.addTorque(-rigidbody.angularVelocity * breakPower * stopAction);

	horzthrust = vertThrust = stopAction = 0;
}
