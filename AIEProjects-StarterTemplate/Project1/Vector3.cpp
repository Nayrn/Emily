#include <iostream>
#include "Vector3.h"

Vector3::Vector3() : x(0.0f), y(0.0f), z(0.0f)
{

}

Vector3::Vector3(float a_x, float a_y, float a_z)
{
	x = a_x;
	y = a_y;
	z = a_z;


}

Vector3::~Vector3()
{
	//does nothing

}

Vector3 Vector3::operator+(const Vector3 &rhs) const
{
	Vector3 temp;
	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;
	temp.z = this->z + rhs.z;

}

Vector3& Vector3::operator+=(const Vector3 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;

	return *this;

}

Vector3 Vector3::operator-(const Vector3 &rhs) const
{
	Vector3 temp;
	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;
	temp.z = this->z - rhs.z;
	return temp;


}

Vector3& Vector3::operator-=(const Vector3 &rhs) 
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	return *this;

}

Vector3 Vector3::operator*(const float &rhs)const
{
	Vector3 temp(0.0f, 0.0f, 0.0f);
	temp.x = this->x*rhs;
	temp.y = this->y*rhs;
	temp.z = this->z*rhs;

	return temp;
}

Vector3 & Vector3::operator*=(const float &rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;

}

bool Vector3::operator==(const Vector3 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y && this->z == rhs.x)
	{

		return true;
	}
	else
		return false;

}

bool Vector3::operator!=(const Vector3 &rhs) const
{

	return!(*this == rhs);
}


float Vector3::Magnitude() const
{
	return sqrt(x*x + y*y + z*z);

}