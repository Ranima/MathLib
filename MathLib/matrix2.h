#pragma once
#include "vec2.h"
#include "Flops.h"

struct mat2
{
	float m[4];
	float mm[2][2];
	vec2 c[2];

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

bool operator==(const mat2 &A, const mat2 &B);
bool operator!=(const mat2 &A, const mat2 &B);
mat2 operator+(const mat2 &A, const mat2 &B);
mat2 operator-(const mat2 &A);
mat2 operator-(const mat2 &A, const mat2 &B);
mat2 operator*(const mat2 &A, const mat2 &B);
mat2 operator*(const mat2 &mat, const vec2 &vec);
mat2 operator*(const mat2 &mat, const float &flo);
mat2 operator*(const float &flo, const mat2 &mat);

mat2 transpose(const mat2 &A);
float determinant(const mat2 &A);
mat2 inverse(const mat2 &A);

//transpose(mat2)
//mat2 * mat2
//mat2 * vec2
//mat2 * float
//float * mat2
//mat2 + mat2
//mat2 - mat2
//-mat2
//determinant(mat2)
//inverse(mat2)