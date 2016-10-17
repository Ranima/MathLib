#pragma once
#include "vec3.h"
#include "Flops.h"
#include "matrix2.h"

union mat3
{
	float ma[9];
	float mama[3][3];
	vec3 ve[3];

	vec3  operator[](unsigned idx) const;
	vec3 &operator[](unsigned idx);
};

bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const float &flo);
mat3 operator*(const float &flo, const mat3 &A);
vec3 operator*(const mat3 &A, const vec3 &vec);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A);

mat3 mat3identity();
mat3 transpose(const mat3 &A);
float determinant(const mat3 &A);
mat3 inverse(const mat3 &A);

mat3 Scale(const vec2 &s);
mat3 translate(const vec2 &t);
mat3 translate(const float x, const float y);
mat3 rotation(float a);

//transpose(mat3)
//mat3 * mat3
//mat3 * vec3
//mat3 * float
//float * mat3
//mat3 + mat3
//mat3 - mat3
//-mat3
//determinant(mat3)
//inverse(mat3)