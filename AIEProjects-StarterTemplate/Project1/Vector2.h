#ifndef VECTOR2
#define VECTOR2
#include <iostream>

class Vector2
{
public: 
	Vector2();
	Vector2(float a_x, float a_y);
	~Vector2();


	float x;
	float y;


	Vector2 operator+(const Vector2 &rhs) const;
	Vector2&  operator+=(const Vector2 &rhs);
	Vector2 operator-(const Vector2 &rhs) const;
	Vector2& operator-=(const Vector2 &rhs);
	Vector2 operator*(const Vector2 &rhs) const;
	Vector2& operator*=(const Vector2 &rhs);

	float Magnitude() const;

	bool operator==(const Vector2 &rhs) const;
	bool operator!=(const Vector2 &rhs) const;

	float& operator[] (int index);
	void * operator new(size_t size);
	void operator delete(void * ptr);

	friend std::ostream& operator<<(std::ostream &os, const Vector2 &rhs);
	friend std::istream& operator>>(std::istream &is, const Vector2 &rhs);
	friend Vector2 operator*(const float lhs, const Vector2& rhs);

};






#endif