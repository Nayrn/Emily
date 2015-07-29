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


	//TODO understand this shit
	//template <class T>
	//void transpose(std::vector< std::vector<T> > a,
	//	std::vector< std::vector<T> > b,
	//	int width, int height)
	//{
	//	for (int i = 0; i < width; i++)
	//	{
	//		for (int j = 0; j < height; j++)
	//		{
	//			b[j][i] = a[i][j];
	//		}
	//	}
	//}
}

Matrix3 Matrix3::operator+(const Matrix3& rhs)const
{
	Matrix3 temp;

	ar[1][1] + ar[1][3];
	ar[1][2] + ar[2][3];
	ar[1][3] + ar[3][3];
	return temp;


}

Matrix3 Matrix3::operator-(const Matrix3& rhs)const
{
	Matrix3 temp;
	ar[1][1] - ar[1][3];
	ar[1][2] - ar[2][3];
	ar[1][3] - ar[3][3];
	return temp;

}

Matrix3 Matrix3::operator*(const Matrix3& rhs)const
{
	Matrix3 temp;
	ar[1][1] * ar[1][3];
	ar[1][2] * ar[2][3];
	ar[1][3] * ar[3][3];
	return temp;


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
	Vector3 tem(0.0f, 0.0f, 0.0f);
	ar[1][1] * rhs.x;
	ar[1][2] * rhs.y;
	ar[1][3] * rhs.z;
	return tem;
	


}

Matrix3& Matrix3::Normalise()
{


}


//todo initialise matrix3 and matrix multiplication