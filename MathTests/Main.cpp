#include <cassert>
#include <cstdio>

#include "Test.h"


int main()
{
	//#wasworkingasecondago#isntnow#gonnacry#wtf

	//#hashtag
	assert(donothin( 0) == 5);
	assert(donothin(-1) == 4);
	assert(donothin( 1) == 8);

	assert(test_quad( 0) == -7);
	assert(test_quad(-1) == -8);
	assert(test_quad( 1) == -4);

	assert(quad(1,  0, 0).roots == 1);
	assert(quad(1, -2, 0).roots == 2);
	assert(quad(1,  0, 4).roots == 0);

	assert(quad(1, -2, 0).left_root	 == 0);
	assert(quad(1, -2, 0).right_root == 2);
	assert(quad(1, 0, 0).left_root == quad(1, 0, 0).right_root);

	assert(lerp(0,  1,   0) ==  0);
	assert(lerp(0,  1,   1) ==  1);
	assert(lerp(0,  1,  -1) == -1);
	assert(lerp(1, -1, .5f) ==  0);

	assert(distance({ 0,0 }, { 0,0 }) == 0);
	assert(distance({ 0,0 }, { 5,0 }) == 5);
	assert(distance({ 0,-5 }, { 0,0 }) == 5);
	assert(distance({ 3,0 }, { 0,4 }) == 5);

	assert(inner({ 1,1,0 }, { -1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);

	assert(pointDistance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(pointDistance({ 0,0,1,0 }, { 0,0,0 }) == 0);

	getchar();
	return 0;
}