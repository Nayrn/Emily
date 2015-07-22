#ifndef MATRIX2
#define MATRIX2
#include "Vector2.h"

class Matrix2
{
public:

	float ar[2][2];

	Matrix2();
	~Matrix2();
	Matrix2 operator+(const Matrix2& rhs) const;
	Matrix2 operator-(const Matrix2& rhs) const;
	Matrix2 operator*(const Matrix2& rhs) const;
	Vector2 operator*(const Vector2& rhs) const;

	Matrix2 operator+=(const Matrix2& rhs);
	Matrix2 operator-=(const Matrix2& rhs);
	Matrix2 operator*=(const Matrix2& rhs);

	Matrix2& Transpose();
	Matrix2& Normalise();


};

#endif