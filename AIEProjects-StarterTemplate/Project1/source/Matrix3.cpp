#include "Matrix3.h"
#include <iostream>


Matrix3::Matrix3() 
{
	ar[1][1] = 1;
	ar[1][2] = 0;
	ar[1][3] = 0;

	ar[2][1] = 0;
	ar[2][2] = 1;
	ar[2][3] = 0;


	ar[3][1] = 0;
	ar[3][2] = 0;
	ar[3][3] = 1;
}

Matrix3::~Matrix3()
{


}

Matrix3& Matrix3::Transpose()
{
	// changes matrix from row to column major

}

Matrix3 Matrix3::operator+(const Matrix3& rhs)const
{


}

Matrix3 Matrix3::operator-(const Matrix3& rhs)const
{


}

Matrix3 Matrix3::operator*(const Matrix3& rhs)const
{


}

Matrix3 Matrix3::operator+=(const Matrix3& rhs)
{


}

Matrix3 Matrix3::operator-=(const Matrix3& rhs)
{


}

Matrix3 Matrix3::operator*=(const Matrix3& rhs)
{


}

Vector3 Matrix3::operator*(const Vector3& rhs)const
{


}

Matrix3& Matrix3::Normalise()
{


}


//todo initialise matrix3 and matrix multiplication