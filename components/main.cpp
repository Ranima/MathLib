#include "sfwdraw.h"
#include "vec2.h"
#include "Flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLoco.h"
#include "spaceshipControler.h"
#include <cstdio>

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 800;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	//Transform trans;
	float steps = 100;
	//Useing A to hide junk for the moment
	bool A = false;

	/*vec2 s{ 2,1 };
	vec2 t{4,3};
*/
	/*mat3 S = Scale(s);
	mat3 T = translate(t);
	mat3 R = rotation(deg2rad(90));*/

	//mat3 RES = { 0,-1,0, 2,0,0, 4,3,1 };

	vec2 start = { 200,200 },
		end = { 600,600 },
		mid = { 200,600 };

	Transform playerTrans(0, 0, 10, 10, 0);
	Rigidbody playerRigid;
	SpaceshipLocomotion loco;
	SpaceshipController spaceshipcon;
	playerRigid.velocity = vec2{ 0,0 };

	//Junk stuff
	while (A == true)
	{
		vec2 player = { 400, 400 };
		vec2 velocity = { 0,0 };
	}
	while (A == true)
	{
		//int j = int(4);
		//int k(4);
		//int l = { 4 };
		//int n{ 4 };

		//Transform tl = Transform(400, 300);
		//Transform tn = { 400, 300 };
		//Transform tm( 400, 300 );
		//Transform tq{ 400, 300 };

		////trans.position = vec2{ 400, 300 };
		//trans.facing = deg2rad(45);
		//trans.scale = vec2{ 24,8 };

		//vec2 basis		= { 40,0 };
		//float ang_vec	= 0;
	}

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		
		/*if (sfw::getKey('W')) playerRigid.acceleration.y += 10.0f;
		if (sfw::getKey('S')) playerRigid.acceleration.y -= 10.0f;
		if (sfw::getKey('A')) playerRigid.acceleration.x -= 10.0f;
		if (sfw::getKey('D')) playerRigid.acceleration.x += 10.0f;

		if (sfw::getKey('Q')) playerRigid.angularAcceleration += 1.0f;
		if (sfw::getKey('E')) playerRigid.angularAcceleration -= 1.0f;*/

		if (playerTrans.m_position.x > SCREEN_WIDTH)
			playerTrans.m_position.x = 0.0f;
		else if (playerTrans.m_position.x < 0.0f)
			playerTrans.m_position.x = SCREEN_WIDTH;

		if (playerTrans.m_position.y > SCREEN_WIDTH)
			playerTrans.m_position.y = 0.0f;
		else if (playerTrans.m_position.y < 0.0f)
			playerTrans.m_position.y = SCREEN_WIDTH;

		spaceshipcon.update(loco);
		loco.update(playerRigid, playerTrans);
		playerRigid.integrate(playerTrans, deltaTime);

		playerTrans.debugDraw();
		playerRigid.debugDraw(playerTrans);
		//Junk stuff
		while (A == true) {
			/*sfw::drawCircle(player.x, player.y, 15, 12, BLUE);

			if (sfw::getKey('W')) velocity.y += 11.0f;
			if (sfw::getKey('S')) velocity.y -= 11.0f;
			if (sfw::getKey('D')) velocity.x += 11.0f;
			if (sfw::getKey('A')) velocity.x -= 11.0f;

			if (sfw::getKey('W') == false &&
				sfw::getKey('S') == false)
				velocity.y -= (velocity.y)* sfw::getDeltaTime();
			if (sfw::getKey('D') == false &&
				sfw::getKey('A') == false)
				velocity.x -= (velocity.x)* sfw::getDeltaTime();

			player += velocity * sfw::getDeltaTime();

			if (velocity.x < 10.f && velocity.x > -10.f) velocity.x = 0.f;
			if (velocity.y < 10.f && velocity.y > -10.f) velocity.y = 0.f;
			if (velocity.x > 100.f) velocity.x = 100.f;
			if (velocity.x < -100.f) velocity.x = -100.f;
			if (velocity.y > 100.f) velocity.y = 100.f;
			if (velocity.y < -100.f) velocity.y = -100.f;

			if (player.x < 0) player.x = 800;
			if (player.x > 800) player.x = 0;
			if (player.y < 0) player.y = 800;
			if (player.y > 800) player.y = 0;*/

			//Junk stuff
			while (A == true)
			{
				//for (int i = 0; i < 100; ++i)
				//{
				//	/*float x1 = i / 100.f;
				//	float y1 = linearHalf(x1);

				//	float x2 = (i + 1) / 100.f;
				//	float y2 = linearHalf(x2);

				//	x1 *= 800;
				//	x2 *= 800;
				//	y1 *= 800;
				//	y2 *= 800;

				//	sfw::drawLine(x1, y1, x2, y2, BLUE);

				//	float a1 = i / 100.f;
				//	float b1 = speedInc(a1);

				//	float a2 = (i + 1) / 100.f;
				//	float b2 = speedInc(a2);

				//	a1 *= 800;
				//	a2 *= 800;
				//	b1 *= 800;
				//	b2 *= 800;

				//	sfw::drawLine(a1 - 10, b1, a2 - 10, b2, MAGENTA);

				//	float w1 = i / 100.f;
				//	float z1 = speedDec(w1);

				//	float w2 = (i + 1) / 100.f;
				//	float z2 = speedDec(w2);

				//	w1 *= 800;
				//	w2 *= 800;
				//	z1 *= 800;
				//	z2 *= 800;

				//	sfw::drawLine(w1, z1, w2, z2, YELLOW);

				//	float s1 = i / 100.f;
				//	float d1 = Hangle(s1);

				//	float s2 = (i + 1) / 100.f;
				//	float d2 = Hangle(s2);

				//	s1 *= 800;
				//	s2 *= 800;
				//	d1 *= 800;
				//	d2 *= 800;

				//	sfw::drawLine(s1, d1, s2, d2, GREEN);

				//	float q1 = i / 100.f;
				//	float e1 = bounce(q1);

				//	float q2 = (i + 1) / 100.f;
				//	float e2 = bounce(q2);

				//	q1 *= 800;
				//	q2 *= 800;
				//	e1 *= 800;
				//	e2 *= 800;

				//	sfw::drawLine(q1, e1, q2, e2, CYAN);

				//	float j1 = i / 100.f;
				//	float k1 = bounceFlip(j1);

				//	float j2 = (i + 1) / 100.f;
				//	float k2 = bounceFlip(j2);

				//	j1 *= 800;
				//	j2 *= 800;
				//	k1 *= 800;
				//	k2 *= 800;

				//	sfw::drawLine(j1, k1, j2, k2, WHITE);

				//	float o1 = i / 100.f;
				//	float p1 = parabFlip(o1);

				//	float o2 = (i + 1) / 100.f;
				//	float p2 = parabFlip(o2);

				//	o1 *= 800;
				//	o2 *= 800;
				//	p1 *= 800;
				//	p2 *= 800;

				//	sfw::drawLine(o1, p1, o2, p2, BLACK);*/
				//}
				//ang_vec += sfw::getDeltaTime();
				//vec2 incident = fromAngle(ang_vec) * 40;
				//float proj = dot(basis, normal(incident));

				//sfw::drawLine(400, 300, 400 + basis.x, 300 + basis.y, RED);
				//sfw::drawLine(400, 300, 400 + incident.x, 300 + incident.y, CYAN);
				//sfw::drawLine(400, 300, 400 + proj, 300, GREEN);
				////trans.debugDraw();
			}
		}
	}

	sfw::termContext();
}