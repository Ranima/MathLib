#include "Projectile.h"
#include "sfwdraw.h"
#include "vec2.h"

void Projectile::init(vec2 start)
{
	move = { 20, 0 };
	Trans.m_position = start;
	radius = 10;
	if (start.y < 250)
		{Trans.m_position.y = Trans.m_position.y + 35;
		 Trans.m_facing = 0;}
	if (start.y > 250)
		{Trans.m_position.y = Trans.m_position.y - 35;
		 Trans.m_facing = 1;}
}

bool Projectile::ballCollide(Projectile ball)
{
	return (4 > distance(Trans.m_position, ball.Trans.m_position));
}

void Projectile::update(float deltaTime, class GameState& gameState, Projectile ball)
{
	Rigid.addForce(move);
	Rigid.integrate(Trans, deltaTime);
	if (ballCollide(ball) == true)
		{Trans.m_facing = dot(Trans.m_position, ball.Trans.m_position);
		Rigid.addTorque(Trans.m_facing);}
}

void Projectile::draw()
{
	sfw::drawCircle(Trans.m_position.x, Trans.m_position.y, radius, 12U, RED);
}
