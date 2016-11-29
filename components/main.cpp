#include "sfwdraw.h"
#include "vec2.h"
#include "Flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Player.h"

#include "shapeDraw.h"
#include "shapes.h"
#include "Hull.h"

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 500;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);
	//Transform trans;

	Square player;
	vec2 startPos = {40, 90};
	player.StartPosition(startPos);
	player.SquareInit();

	Plane ground;
	ground.pos = { 0, 5 };
	ground.dir = { 1, 0 };
	
	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();
		
		player.testPhysics();
		player.update();
		player.debugDraw();
	}
	sfw::termContext();
}
