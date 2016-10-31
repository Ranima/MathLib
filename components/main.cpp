#include "sfwdraw.h"
#include "vec2.h"
#include "Flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "SpaceshipLoco.h"
#include "spaceshipControler.h"
#include "SpaceshipRenderer.h"
#include "PlanetaryMotor.h"
#include "PlantearyRenderer.h"

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

	/*vec2 start = { 200,200 },
		end = { 600,600 },
		mid = { 200,600 };*/

	//vec2 waypoint[] = { {12, -8}, {15,18},{5,8},{-22,-5},{4,-2},{-6,9},{18,88},{-22,-90}};

	/*Transform ST1(0, -5);
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

	//player
	Transform playerTrans(400, 400, 1, 1, 0);
	Rigidbody playerRigid;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCon;
	SpaceshipRenderer playerRender;
	playerRigid.velocity = vec2{ 0,0 };

	//Sun
	Transform sunTrans;
	sunTrans.m_position = vec2{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	Rigidbody sunRbody;
	PlanetaryMotor sunMotor;
	sunMotor.m_rotationspeed = 5;
	PlanetaryRenderer sunRenderer(YELLOW, 100);

	//Planet
	Transform planet;
	planet.m_position = vec2{ 150, 0 };
	planet.m_parent = &sunTrans;
	Rigidbody plan1RB;
	PlanetaryMotor planetmotor;
	planetmotor.m_rotationspeed = 7;
	PlanetaryRenderer planetRenderer(GREEN, 20);

	//Moon
	Transform moon;
	moon.m_position = vec2{ 50,0 };
	moon.m_parent = &planet;
	Rigidbody moonRB;
	PlanetaryMotor moonMotor;
	moonMotor.m_rotationspeed = 12;
	PlanetaryRenderer moonRenderer(WHITE, 7);

	Transform cameraTransform;


	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		
		playerCon.update(playerLoco);
		playerLoco.update(playerRigid, playerTrans);

		sunMotor.update(sunRbody);
		planetmotor.update(plan1RB);
		moonMotor.update(moonRB);

		playerRigid.integrate(playerTrans, deltaTime);
		moonRB.integrate(moon, deltaTime);
		plan1RB.integrate(planet, deltaTime);
		sunRbody.integrate(sunTrans, deltaTime);

		cameraTransform.m_position = 
			lerp(cameraTransform.m_position,
			(playerTrans.getGlobalPosition()
				) / 1,
//				+ sunTrans.getGlobalPosition()) / 2,
				1);

		mat3 proj = translate(400, 400) * scale(1, 1);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;

		/*if (playerTrans.m_position.x > SCREEN_WIDTH)
			playerTrans.m_position.x = 0.0f;
		else if (playerTrans.m_position.x < 0.0f)
			playerTrans.m_position.x = SCREEN_WIDTH;

		if (playerTrans.m_position.y > SCREEN_WIDTH)
			playerTrans.m_position.y = 0.0f;
		else if (playerTrans.m_position.y < 0.0f)
			playerTrans.m_position.y = SCREEN_WIDTH;*/

		playerTrans.debugDraw(camera);
		sunTrans.debugDraw(camera);
		planet.debugDraw(camera);
		moon.debugDraw(camera);
		cameraTransform.debugDraw(camera);

		/*playerCon.update(playerLoco);
		playerLoco.update(playerRigid, playerTrans);
		playerRigid.integrate(playerTrans, deltaTime);*/

		playerRigid.debugDraw(camera, playerTrans);

		sunRenderer.draw(camera, sunTrans);
		planetRenderer.draw(camera, planet);
		moonRenderer.draw(camera, moon);

		playerRender.draw(camera, playerTrans);
	}

	sfw::termContext();
}
/*its broken, im crying... "wha"*/