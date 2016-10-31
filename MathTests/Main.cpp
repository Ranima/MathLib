#include <cassert>
#include <cstdio>
#include <cmath>

#include "Test.h"
#include "vec2.h"
#include "vec3.h"

#include "matrix3.h"

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

	/*assert(lerp(0,  1,   0) ==  0);
	assert(lerp(0,  1,   1) ==  1);
	assert(lerp(0,  1,  -1) == -1);
	assert(lerp(1, -1, .5f) ==  0);*/

	assert(distance({ 0,0 }, { 0,0 }) == 0);
	assert(distance({ 0,0 }, { 5,0 }) == 5);
	assert(distance({ 0,-5 }, { 0,0 }) == 5);
	assert(distance({ 3,0 }, { 0,4 }) == 5);

	assert(inner({ 1,1,0 }, { -1,1,0 }) == 0);
	assert(inner({ 1,1,1 }, { 1,1,1 }) == 3);

	assert(pointDistance({ 0,0,1,0 }, { 0,0,0 }) == 0);
	assert(pointDistance({ 0,0,1,0 }, { 0,0,0 }) == 0);

	// vec2
	assert((vec2{ 0,0 } == vec2{ 0,0 }));
	assert((vec2{ 1,0 } == vec2{ 1,0 }));

	assert((vec2{ 1,1 } + vec2{ -1,0 } == vec2{ 0,1 }));
	assert((vec2{ 1,1 } - vec2{  1,0 } == vec2{ 0,1 }));

	vec2 var = { 4,0 };
	assert(((var += vec2{ -3,1 }) == vec2{1,1}));
	var = { 4,0 };
	assert(((var -= vec2{ 3,-1 }) == vec2{ 1,1 }));
	var = { 4,0 };
	assert(((var *= vec2{ 3,-1 }) == vec2{ 12,0 }));
	var = { 4,2 };
	assert(((var /= vec2{ 2,-2 }) == vec2{ 2,-1 }));

	assert((dot(vec2{ 3,4 }, vec2{ 5,6 }) == 39.f));
	assert((fequals(angleBetween(vec2{ 0,1 }, vec2{ 1,0 }), deg2rad(90))));
	assert((fromAngle(0) == vec2{ 1,0 }));


	// vec3


	// mat2
	// mat3
	// flops
	assert(fequals(deg2rad(90), 1.57079f));

	// turn right 90 degrees and walk 10 units forward. <0,-10> ?

	// translate(6, 4); 6 units due east, 4 units due north
	vec3 test = rotation(deg2rad(-90)) * translate(10, 0) *
				rotation(deg2rad(45))  * translate(4, 0)  *
				rotation(deg2rad(45))  * translate(-6, 0) *
				translate(6, 4)        * vec3 {0, 0, 1};

	assert((test == vec3{ 2 * sqrtf(2), -6- 2*sqrtf(2), 1}));

	// 2.82, 
	// -8.82
	// 1

	mat3 tank;
	mat3 turret;

	tank = translate(vec2{18,88});

	assert(fequals(determinant(mat2{ 1,1,20,15 }), -5.f));
	assert(fequals(determinant(mat3{ 1,0,0, 0,1,0, 400,400,1 }), 1.f));

	getchar();
	return 0;
};