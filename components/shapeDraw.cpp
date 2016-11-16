#include "shapeDraw.h"
#include "sfwdraw.h"

void drawCircle(const Circle & c, unsigned color)
{
	sfw::drawCircle(c.pos.x, c.pos.y, c.rad, 12U, color);
}

void drawAABB(const AABB & B, unsigned color)
{
	vec2 A = vec2{ B.min().x, B.max().y };
	vec2 b = vec2{ B.max().x, B.max().y };
	vec2 C = vec2{ B.max().x, B.min().y };
	vec2 D = vec2{ B.min().x, B.min().y };

	sfw::drawLine(A.x, A.y, b.x, b.y, color);
	sfw::drawLine(b.x, b.y, C.x, C.y, color);
	sfw::drawLine(C.x, C.y, D.x, D.y, color);
	sfw::drawLine(D.x, D.y, A.x, A.y, color);
}

void drawPlane(const Plane &P, unsigned color)
{
	sfw::drawCircle(P.pos.y, 12, 12, color);

	sfw::drawLine(P.pos.x, P.pos.y,
		P.pos.x + P.dir.x * 10, P.pos.y + P.dir.y * 10, color);

	vec2 left = perp(P.dir);
	vec2 right = -perp(P.dir);

	sfw::drawLine(P.pos.x, P.pos.y,
		P.pos.x + right.x * 120, P.pos.y + right.y * 120, color);
}