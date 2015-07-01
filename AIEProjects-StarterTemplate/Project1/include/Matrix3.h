#ifndef MATRIX3
#define MATRIX3
#include "Vector3.h"

class Matrix3
{
public:

	float ar[3][3];
		

	Matrix3();
	~Matrix3();
	Matrix3 operator+(const Matrix3& rhs) const;
	Matrix3 operator-(const Matrix3& rhs) const;
	Matrix3 operator*(const Matrix3& rhs) const;
	Vector3 operator*(const Vector3& rhs) const;
	
	Matrix3 operator+=(const Matrix3& rhs);
	Matrix3 operator-=(const Matrix3& rhs);
	Matrix3 operator*=(const Matrix3& rhs);

	Matrix3& Transpose();



};

#endif