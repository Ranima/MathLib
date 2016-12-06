#pragma once
#include "Rigidbody.h"
#include "Transform.h"
#include "vec2.h"

class Projectile
{
private:
	Transform Trans;
	Rigidbody Rigid;
	float radius;

public:
	void init(vec2 start);
	void update();
	void draw();
};