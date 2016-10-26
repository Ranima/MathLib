#include "collision.h"

CollisionData1D collisionDetection1D(float Amin, float Amax, float Bmin, float Bmax)
{
	CollisionData1D retval;
	if (Bmax > Amin && Bmax < Amax)

		retval.penetrationDepth = ;
	retval.collisionNormal = ;

	retval.result = retval.penetrationDepth > 0;
	retval.MTV = retval.penetrationDepth
		* retval.collisionNormal;
	return retval;
}
