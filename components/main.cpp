#include "sfwdraw.h"
#include "vec2.h"
#include "Flops.h"
#include "Transform.h"
#include "Rigidbody.h"
#include "Player.h"
#include "Projectile.h"

#include "shapeDraw.h"
#include "shapes.h"
#include "Hull.h"

#include "GameState.h"

void main()
{
	float SCREEN_WIDTH = 800, SCREEN_HEIGHT = 500;
	sfw::initContext(SCREEN_WIDTH, SCREEN_HEIGHT);
	sfw::setBackgroundColor(BLACK);

	GameState gameState;
	gameState.init();

	while (sfw::stepContext())
	{
		gameState.update(sfw::getDeltaTime());
		gameState.draw();
	}

	sfw::termContext();
}
