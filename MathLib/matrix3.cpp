#include "matrix3.h"

float mat3::operator[](unsigned idx) const
{
	return ma[idx];
}

float & mat3::operator[](unsigned idx)
{
	return ma[idx];
}

bool operator==(const mat3 & A, const mat3 & B)
{
	fequals(A.ma[0], B.ma[0]) &&
		fequals(A.ma[1], B.ma[1]) &&
		fequals(A.ma[2], B.ma[2]) &&
		fequals(A.ma[3], B.ma[3]) &&
		fequals(A.ma[4], B.ma[4]) &&
		fequals(A.ma[5], B.ma[5]) &&
		fequals(A.ma[6], B.ma[6]) &&
		fequals(A.ma[7], B.ma[7]) &&
		fequals(A.ma[8], B.ma[8]);
}

bool operator!=(const mat3 & A, const mat3 & B)
{
	return bool{ A.ma[0] != B.ma[0] &&
		A.ma[1] != B.ma[1] &&
		A.ma[2] != B.ma[2] &&
		A.ma[3] != B.ma[3] &&
		A.ma[4] != B.ma[4] && 
		A.ma[5] != B.ma[5] && 
		A.ma[6] != B.ma[6] && 
		A.ma[7] != B.ma[7] && 
		A.ma[8] != B.ma[8] };
}

mat3 operator*(const mat3 & A, const mat3 & B)
{
	return mat3{ A.ma[0] * B.ma[0], A.ma[1] * B.ma[1],
		A.ma[2] * B.ma[2], A.ma[3] * B.ma[3],
		A.ma[4] * B.ma[4], A.ma[5] * B.ma[5],
		A.ma[6] * B.ma[6], A.ma[7] * B.ma[7],
		A.ma[8] * B.ma[8]};
}

mat3 operator*(const mat3 & A, const float & flo)
{
	return mat3{ A.ma[0] * flo, A.ma[1] * flo,
		A.ma[2] * flo, A.ma[3] * flo,
		A.ma[4] * flo, A.ma[5] * flo,
		A.ma[6] * flo, A.ma[7] * flo, 
		A.ma[8] * flo};
}

mat3 operator*(const float & flo, const mat3 & A)
{
	return mat3{ A.ma[0] * flo, A.ma[1] * flo,
		A.ma[2] * flo, A.ma[3] * flo,
		A.ma[4] * flo, A.ma[5] * flo,
		A.ma[6] * flo, A.ma[7] * flo,
		A.ma[8] * flo };
}

mat3 operator*(const mat3 & A, const vec3 & vec)
{
	return mat3{ A.ma[0] * vec.x, A.ma[1] * vec.y,
		A.ma[2] * vec.z, A.ma[3] * vec.x,
		A.ma[4] * vec.y, A.ma[5] * vec.z,
		A.ma[6] * vec.y, A.ma[7] * vec.z,
		A.ma[8] * vec.y};
}

mat3 operator+(const mat3 & A, const mat3 & B)
{
	return mat3{ A.ma[0] + B.ma[0],
		A.ma[1] + B.ma[1],
		A.ma[2] + B.ma[2],
		A.ma[3] + B.ma[3],
		A.ma[4] + B.ma[4],
		A.ma[5] + B.ma[5],
		A.ma[6] + B.ma[6],
		A.ma[7] + B.ma[7],
		A.ma[8] + B.ma[8]};
}

mat3 operator-(const mat3 & A, const mat3 & B)
{
	return mat3{ A.ma[0] - B.ma[0],
		A.ma[1] - B.ma[1],
		A.ma[2] - B.ma[2],
		A.ma[3] - B.ma[3],
		A.ma[4] - B.ma[4],
		A.ma[5] - B.ma[5],
		A.ma[6] - B.ma[6], 
		A.ma[7] - B.ma[7], 
		A.ma[8] - B.ma[8]};
}

mat3 operator-(const mat3 & A)
{
	return mat3{ A.ma[0] - A.ma[0]*2,
		A.ma[1] - A.ma[1]*2,
		A.ma[2] - A.ma[2]*2,
		A.ma[3] - A.ma[3]*2,
		A.ma[4] - A.ma[4]*2,
		A.ma[5] - A.ma[5]*2,
		A.ma[6] - A.ma[6]*2, 
		A.ma[7] - A.ma[7]*2, 
		A.ma[8] - A.ma[8]*2};
}

mat3 mat3identity()
{
	return mat3{1,0,0, 0,1,0, 0,0,1};
}

mat3 transpose(const mat3 & A)
{
	mat3 B = A;
	B = { B.ma[0], B.ma[1] = A.ma[3], B.ma[2] = A.ma[6],
		B.ma[3] = A.ma[1], B.ma[4], B.ma[5] = A.ma[7],
		B.ma[6] = A.ma[2], B.ma[7] = A.ma[5], B.ma[8]};
	return B;
}

float determinant(const mat3 & A)
{
	mat2 a;
	mat2 b;
	mat2 c;
	a.m[0] = A.ma[4], a.m[1] = A.ma[7],
		a.m[3] = A.ma[5], a.m[4] = A.ma[8];
	b.m[0] = A.ma[1], b.m[1] = A.ma[7],
		b.m[3] = A.ma[2], b.m[4] = A.ma[8];
	c.m[0] = A.ma[1], c.m[1] = A.ma[4],
		c.m[3] = A.ma[2], c.m[4] = A.ma[5];
	return (A.ma[0] * determinant(a) -
		A.ma[3] * determinant(b) +
		A.ma[6] * determinant(c));
}

mat3 inverse(const mat3 &A)
{
	mat3 retval;

	retval[0] = cross(A[1], A[2]);
	retval[1] = cross(A[2], A[0]);
	retval[2] = cross(A[0], A[1]);

	return 1 / determinant(A) *
		transpose(retval);
}

mat3 scale(const vec2 & s)
{
	mat3 retval = mat3identity();
	retval[0][0] = w;
	retval[1][1] = h;
	return retval;
}

mat3 translate(const vec2 & t)
{
	mat3 retval = mat3identity();
	retval[2][0] = x;
	retval[2][1] = y;
	return retval;
}

mat3 rotation(float a)
{
	vec2 d = fromAngle(a);
	mat3 retval = mat3identity();
	retval[0].xy = d;
	retval[1].xy = -perp(d);
	return retval;
}
