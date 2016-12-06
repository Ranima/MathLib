#include "Projectile.h"

void Projectile::init(vec2 start)
{
	Trans.m_position = start;
	radius = 10;
	if (start.y < 250)
		{Trans.m_position.y = Trans.m_position.y + 35;}
	if (start.y > 250)
		{Trans.m_position.y = Trans.m_position.y - 35;}
}

void Projectile::update()
{

}
