#ifndef MATRIX4
#define MATRIX4
#include "Vector4.h"

class Matrix4
{
public:

	float ar[4][4];

	Matrix4();
	~Matrix4();
	Matrix4 operator+(const Matrix4& rhs) const;
	Matrix4 operator-(const Matrix4& rhs) const;
	Matrix4 operator*(const Matrix4& rhs) const;
	Vector4 operator*(const Vector4& rhs) const;

	Matrix4 operator+=(const Matrix4& rhs);
	Matrix4 operator-=(const Matrix4& rhs);
	Matrix4 operator*=(const Matrix4& rhs);

	Matrix4& Transpose();
	Matrix4& Normalise();
	
		  



};

#endif