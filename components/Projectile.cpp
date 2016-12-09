#include "Projectile.h"
#include "sfwdraw.h"

void Projectile::init(vec2 start)
{
	Trans.m_position = start;
	radius = 10;
	if (start.y < 250)
		{Trans.m_position.y = Trans.m_position.y + 35;
		 Trans.m_facing = 0;}
	if (start.y > 250)
		{Trans.m_position.y = Trans.m_position.y - 35;
		 Trans.m_facing = 1;}
}

void Projectile::update(float deltaTime, class GameState& gameState)
{
	//Rigid.addForce(Trans.m_position);
	Rigid.integrate(Trans, deltaTime);
}

void Projectile::draw()
{
	sfw::drawCircle(Trans.m_position.x, Trans.m_position.y, radius, 12U, RED);
}
