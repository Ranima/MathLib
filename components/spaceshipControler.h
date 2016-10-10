#pragma once
#include "SpaceshipLoco.h"
#include "sfwdraw.h"

class SpaceshipController
{
public:
	unsigned CTR_LEFT, CTR_RIGHT, CTR_UP, CTR_DOWN, CTR_BREAK;

	SpaceshipController(unsigned a_CTR_LEFT, unsigned a_CTR_RIGHT
		, unsigned a_CTR_UP, unsigned a_CTR_DOWN, unsigned a_CTR_BREAK);

	void update(SpaceshipLocomotion & loco);
};