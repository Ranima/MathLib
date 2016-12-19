#pragma once
#include "Rigidbody.h"
#include "Transform.h"
#include "vec2.h"
#include "Player.h"

class Projectile
{
private:
	vec2 move;

public:
	Transform Trans;
	Rigidbody Rigid;
	float radius;

	bool isFired;

	void init(vec2 start);
	bool ballCollide(Projectile ball);
	void update(float deltaTime, class GameState& gameState, Projectile ball);
	void draw();
};