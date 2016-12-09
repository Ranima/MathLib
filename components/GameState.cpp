#include "GameState.h"


void GameState::init()
{
	player1.StartPosition({ 250, 30 });
	player1.SquareInit();
	player1.id = 0;

	player2.StartPosition({ 250, 470 });
	player2.SquareInit();
	player2.id = 1;

	player1proj.init({ 250, 50 });
	player2proj.init({ 250, 420 });
}

void GameState::update(float deltaTime)
{
	player1.testPhysics(30);
	player2.testPhysics(470);

	player1.testController();
	player2.testController();

	player1.update(deltaTime, *this);
	player2.update(deltaTime, *this);

	player1proj.update(deltaTime, *this);
	player2proj.update(deltaTime, *this);
}

void GameState::draw()
{
	player1.debugDraw();
	player2.debugDraw();

	player1proj.draw();
	player2proj.draw();
}

void GameState::exit()
{

}