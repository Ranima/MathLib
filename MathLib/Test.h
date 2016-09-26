#pragma once

int donothin(int x);

float test_quad(float x);

struct quad_results
{
	float left_root, right_root;
	int roots;
};

quad_results quad(float a, float b, float c);

float lerp(float start, float end, float t);

struct point { float x, y; };
float distance(point P1, point P2);

struct point3D { float x, y, z; };
float inner(point3D P1, point3D P2);

struct Plane { float a, b, c, d; };
float pointDistance(Plane plane, point3D P);

float Bcurve(float t, float P0, float P1, float P2, float P3);