#include "matrix2.h"

bool operator==(const mat2 & A, const mat2 & B)
{
	return	fequals(A.m[0], B.m[0]) &&
			fequals(A.m[1], B.m[1]) &&
			fequals(A.m[2], B.m[2]) &&
			fequals(A.m[3], B.m[3]);
}

bool operator!=(const mat2 & A, const mat2 & B)
{
	return bool{ A.m[0] != B.m[0] &&
		A.m[1] != B.m[1] &&
		A.m[2] != B.m[2] &&
		A.m[3] != B.m[3] };
}

mat2 operator+(const mat2 &A, const mat2 &B)
{
	return mat2{A.m[0] + B.m[0], A.m[1] + B.m[1],
		A.m[2] + B.m[2], A.m[3] + B.m[3]};
}

mat2 operator-(const mat2 & A)
{
	return mat2{ A.m[0] - A.m[0]*2, A.m[1] - A.m[1]*2,
		A.m[2] - A.m[2]*2, A.m[3] - A.m[3]*2};
}

mat2 operator-(const mat2 &A, const mat2 &B)
{
	return mat2{ A.m[0] - B.m[0], A.m[1] - B.m[1],
		A.m[2] - B.m[2], A.m[3] - B.m[3] };
}

mat2 operator*(const mat2 & A, const mat2 & B)
{
	return mat2{ A.m[0] * B.m[0], A.m[1] * B.m[1],
		A.m[2] * B.m[2], A.m[3] * B.m[3] };
}

mat2 operator*(const mat2 & mat, const vec2 & vec)
{
	return mat2{ mat.m[0] * vec.x, mat.m[1] * vec.y,
		mat.m[2] * vec.x, mat.m[3] * vec.y };
}

mat2 operator*(const mat2 & mat, const float & flo)
{
	return mat2{ mat.m[0] * flo, mat.m[1] * flo,
		mat.m[2] * flo, mat.m[3] * flo };
}

mat2 operator*(const float & flo, const mat2 & mat)
{
	return mat2{ mat.m[0] * flo, mat.m[1] * flo,
		mat.m[2] * flo, mat.m[3] * flo };
}

mat2 transpose(const mat2 &A)
{
	mat2 B = A;
	B = {B.m[0], B.m[1] = A.m[2], B.m[2] = A.m[1],
		B.m[3]};
	return B;
}

float determinant(const mat2 & A)
{
	return (A.m[0] * A.m[3]) - (A.m[1] * A.m[2]);
}

float mat2::operator[](unsigned idx) const
{
	return m[idx];
}

float & mat2::operator[](unsigned idx)
{
	return m[idx];
}