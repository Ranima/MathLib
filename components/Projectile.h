#pragma once
#include "Rigidbody.h"
#include "Transform.h"
#include "vec2.h"
#include "Player.h"

class Projectile
{
private:


public:
	Transform Trans;
	Rigidbody Rigid;
	float radius;

	bool isFired;

	void init(vec2 start);
	void update(float deltaTime, class GameState& gameState);
	void draw();
};