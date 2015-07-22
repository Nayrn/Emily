#include "Matrix4.h"
#include <iostream>

Matrix4::Matrix4()
{

	ar[1][1] = 1;
	ar[1][2] = 0;
	ar[1][3] = 0;
	ar[1][4] = 0;
	

	ar[2][1] = 0;
	ar[2][2] = 1;
	ar[2][3] = 0;
	ar[2][4] = 0;



	ar[3][1] = 0;
	ar[3][2] = 0;
	ar[3][3] = 1;
	ar[3][4] = 0;

	ar[4][1] = 0; 
	ar[4][2] = 0;
	ar[4][3] = 0;
	ar[4][4] = 1;


}	



Matrix4::~Matrix4()
{


}


Matrix4& Matrix4::Transpose()
{


}

Matrix4 Matrix4::operator+(const Matrix4& rhs)const
{


}

Matrix4 Matrix4::operator-(const Matrix4& rhs)const
{


}

Matrix4 Matrix4::operator*(const Matrix4& rhs)const
{


}

Matrix4 Matrix4::operator+=(const Matrix4& rhs)
{


}

Matrix4 Matrix4::operator-=(const Matrix4& rhs)
{


}

Matrix4 Matrix4::operator*=(const Matrix4& rhs)
{


}

Vector4 Matrix4::operator*(const Vector4& rhs)const
{


}

Matrix4& Matrix4::Normalise()
{


}
