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

	//players stuff
	Square player1;
	vec2 startPos1 = {40, 180};
	player1.StartPosition(startPos1);
	player1.SquareInit();

	Square player2;
	vec2 startPos2 = { 40, 180 };
	player2.StartPosition(startPos2);
	player2.SquareInit();
	
	Transform cameraTransform;

	while (sfw::stepContext())
	{
		float deltaTime = sfw::getDeltaTime();


		
		player1.testPhysics(30);
		player2.testPhysics(470);
		player1.testController();
		player2.testController();
		player1.update();
		player2.update();
		player1.debugDraw();
		player2.debugDraw();
	}
	sfw::termContext();
}
