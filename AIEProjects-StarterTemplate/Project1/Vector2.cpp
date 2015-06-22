#include "Vector2.h"
#include <iostream>

Vector2::Vector2() : x(0.0f), y(0.0f)
{

}

Vector2::Vector2(float a_x, float a_y)
{
	x = a_x;
	y = a_y;
}

Vector2::~Vector2()
{

	//no memory allocated, does nothing.
}

Vector2 Vector2::operator+(const Vector2 &rhs) const
{


}

Vector2& Vector2::operator+=(const Vector2 &rhs)
{


}

Vector2 Vector2::operator-(const Vector2 &rhs) const
{


}

Vector2& Vector2::operator-=(const Vector2 &rhs)
{


}

Vector2 Vector2::operator*(const Vector2 &rhs) const
{


}

Vector2& Vector2::operator*=(const Vector2 &rhs)
{


}

bool Vector2::operator==(const Vector2 &rhs) const
{


}

bool Vector2::operator!=(const Vector2 &rhs) const
{


}


float& Vector2::operator[] (int index)
{


}

void * Vector2::operator new(size_t size)
{


}

void Vector2::operator delete(void * ptr)
{


}

std::ostream& operator<<(std::ostream & os, const Vector2 &rhs)
{
	//overload of cout

}

std::istream& operator>>(std::istream &is, Vector2 &rhs)
{

	//overload of cin
}

Vector2 operator*(const float lhs, const Vector2& rhs)
{


}

float Vector2::Magnitude() const
{

	return sqrt( x*x + y*y );


}