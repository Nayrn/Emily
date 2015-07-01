#include "Vector4.h"
#include <iostream>


Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), t(0.0f)
{
	

}

Vector4::~Vector4()
{


}

Vector4::Vector4(float a_x, float a_y, float a_z, float a_t)
{
	x = a_x;
	y = a_y;
	z = a_z;
	t = a_t;

}

Vector4 Vector4::operator+(const Vector4 &rhs) const
{
	Vector4 temp;
	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;
	temp.z = this->z + rhs.z;
	temp.t = this->t + rhs.t;
	return temp;
}

Vector4& Vector4::operator+=(const Vector4 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->t += rhs.t;
	return *this;

}

Vector4 Vector4::operator-(const Vector4 &rhs) const
{
	Vector4 temp;
	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;
	temp.z = this->z - rhs.z;
	temp.t = this->t - rhs.t;
	return temp;

}

Vector4& Vector4::operator-=(const Vector4 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->t -= rhs.t;
	return *this;

}

Vector4 Vector4::operator*(const float &rhs)const
{
	Vector4 temp(0.0f, 0.0f, 0.0f, 0.0f);
	temp.x = this->x*rhs;
	temp.y = this->y*rhs;
	temp.z = this->z*rhs;
	temp.t = this->t*rhs;

	return temp;

}

Vector4& Vector4::operator*=(const float &rhs)
{

	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->t *= rhs;
	return *this;

}

bool Vector4::operator==(const Vector4 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.x && this->t == rhs.t)
	{

		return true;
	}
	else
		return false;

}

bool Vector4::operator!=(const Vector4 &rhs) const
{
	return!(*this == rhs);

}

float& Vector4::operator[] (int index)
{
	float *ptr = (float*)this;
	ptr += index;
	return *ptr;

}

void * Vector4::operator new(size_t size)
{
	void * ptr = ::new Vector4;
	return ptr;

}

//std::ostream& operator <<(std::ostream & os, const Vector4 &rhs)
//{
//
//	os << "(" << rhs.x << "," << rhs.y << "," << rhs.z << "," << rhs.t << ")";
//	return os;
//
//}
//
//std::istream& operator>>(std::istream &is, Vector4 &rhs)
//{
//	is >> rhs.x;
//	is >> rhs.y;
//	is >> rhs.z;
//	is >> rhs.t;
//	return is;
//
//}


float Vector4::Magnitude() const
{
	return sqrt(x*x + y*y + z*z + t*t);

}