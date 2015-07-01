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
	Vector2 temp;
	temp.x = this->x + rhs.x;
	temp.y = this->y + rhs.y;

	return temp;

}

Vector2& Vector2::operator+=(const Vector2 &rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	
	return *this;

}

Vector2 Vector2::operator-(const Vector2 &rhs) const
{
	Vector2 temp;
	temp.x = this->x - rhs.x;
	temp.y = this->y - rhs.y;

	return temp;

}

Vector2& Vector2::operator-=(const Vector2 &rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	
	return *this;

}

Vector2 Vector2::operator*(const float &rhs) const
{
	Vector2 temp(0.0f, 0.0f);
	temp.x = this->x*rhs;
	temp.y = this->y*rhs;

	return temp;

}

Vector2& Vector2::operator*=(const float &rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;
	

}

bool Vector2::operator==(const Vector2 &rhs) const
{
	if (this->x == rhs.x && this->y == rhs.y)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Vector2::operator!=(const Vector2 &rhs) const
{
	return !(*this == rhs); 

}


float& Vector2::operator[] (int index)
{
	float *ptr = (float*)this; // creates a float ptr to the start of x
	ptr += index;		// adds index to pointer.
	return *ptr;		// returns value at ptr.

}

void * Vector2::operator new(size_t size)
{
	void * ptr = ::new Vector2;
	// allocates memory at address
	return ptr;
}

void Vector2::operator delete(void * ptr)
{

	//Deallocates memory at address.
	::delete ptr;

}

std::ostream& operator<<(std::ostream & os, const Vector2 &rhs)
{
	// prints out x & y.
	//overload of cout
	os << "(" << rhs.x << "," << rhs.y << ")";
	return os;

}

std::istream& operator>>(std::istream &is, Vector2 &rhs)
{
	is >> rhs.x;
	is >> rhs.y;
	return is;
	//overload of cin
}


float Vector2::Magnitude() const
{

	return sqrt( x*x + y*y);


}