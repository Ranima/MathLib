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
#include "shapeDraw.h"
#include "shapes.h"
#include "Hull.h"

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 800;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	//Transform trans;
	float steps = 100;

	//player
	Transform playerTrans(400, 400, 10, 10, 0);
	Rigidbody playerRigid;
	SpaceshipLocomotion playerLoco;
	SpaceshipController playerCon;
	SpaceshipRenderer playerRender;
	playerRigid.velocity = vec2{ 0,0 };

	/*//Sun
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
	PlanetaryRenderer moonRenderer(WHITE, 7);*/

	Transform cameraTransform;


	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		
		playerCon.update(playerLoco);
		playerLoco.update(playerRigid, playerTrans);

		/*sunMotor.update(sunRbody);
		planetmotor.update(plan1RB);
		moonMotor.update(moonRB);*/

		playerRigid.integrate(playerTrans, deltaTime);
		/*moonRB.integrate(moon, deltaTime);
		plan1RB.integrate(planet, deltaTime);
		sunRbody.integrate(sunTrans, deltaTime);*/

		/*cameraTransform.m_position = 
			lerp(cameraTransform.m_position,
			(playerTrans.getGlobalPosition()
				+ sunTrans.getGlobalPosition()) / 2,
				1);*/

		mat3 proj = translate(400, 400) * scale(1, 1);
		mat3 view = inverse(cameraTransform.getGlobalTransform());

		mat3 camera = proj * view;

		playerTrans.debugDraw(camera);
		/*sunTrans.debugDraw(camera);
		planet.debugDraw(camera);
		moon.debugDraw(camera);*/
		cameraTransform.debugDraw(camera);

		/*playerCon.update(playerLoco);
		playerLoco.update(playerRigid, playerTrans);
		playerRigid.integrate(playerTrans, deltaTime);*/

		playerRigid.debugDraw(camera, playerTrans);

		/*sunRenderer.draw(camera, sunTrans);
		planetRenderer.draw(camera, planet);
		moonRenderer.draw(camera, moon);*/

		playerRender.draw(camera, playerTrans);

		drawAABB(camera
			* playerTrans.getGlobalTransform()
			* AABB {0, 0, 1, 2}, RED);

		drawPlane(camera
			* playerTrans.getGlobalTransform()
			* Plane {0, 0, 0, 1}, WHITE);
	}
	sfw::termContext();
}
