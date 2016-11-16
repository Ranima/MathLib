#include "Hull.h"

void drawHull(const Hull & H, unsigned color)
{
	for (int i = 0; i <= H.size && i < 10; ++i)
	{
		sfw::drawLine(H.vertices[i].x, H.vertices[i].y,
			H.vertices[(i + 1) % H.size].x,
			H.vertices[(i + 1) % H.size].y, color);
	}
}
