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

	vec2 waypoint[] = { {12, -8}, {15,18},{5,8},{-22,-5},{4,-2},{-6,9},{18,88},{-22,-90}};

	/*Transform playerTrans(400, 400, 10, 10, 0);
	Transform ST1(0, -5);
	Transform ST2(0, -5);
	Transform ST3(0, -5);
	Transform ST4(0, -5);
	Transform ST5(0, -5);*/

	/*SpaceshipController ST1con{'Q','E'};
	SpaceshipController ST2con{'Z','C'};
	SpaceshipLocomotion ST1loc;
	SpaceshipLocomotion ST2loc;*/

	/*ST1.m_parent = &playerTrans;
	ST2.m_parent = &ST1;
	ST3.m_parent = &ST2;
	ST4.m_parent = &ST3;
	ST5.m_parent = &ST4;
*/
	Rigidbody playerRigid;
	SpaceshipLocomotion loco;
	SpaceshipController spaceshipcon;
	playerRigid.velocity = vec2{ 0,0 };

	
	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		for (int i = 0; i <= 7; i++)
		{

		}
	}

	sfw::termContext();
}