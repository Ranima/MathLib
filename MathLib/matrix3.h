#pragma once
#include "vec3.h"
#include "Flops.h"
#include "matrix2.h"

struct mat3
{
	float ma[9];
	float mama[3][3];
	vec3 ve[3];

	float  operator[](unsigned idx) const;
	float &operator[](unsigned idx);
};

bool operator==(const mat3 &A, const mat3 &B);
bool operator!=(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B);
mat3 operator*(const mat3 &A, const float &flo);
mat3 operator*(const float &flo , const mat3 &A);
mat3 operator*(const mat3 &A, const vec3 &vec);
mat3 operator+(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A, const mat3 &B);
mat3 operator-(const mat3 &A);

mat3 transpose(const mat3 &A);
float determinant(const mat3 &A);
mat3 inverse();

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