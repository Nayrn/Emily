#ifndef VECTOR3
#define VECTOR3

class Vector3
{
public: 
	Vector3();
	Vector3(float a_x, float a_y, float a_z);
	~Vector3();
	


	float x;
	float y;
	float z;

	Vector3 operator+(const Vector3 &rhs) const;
	Vector3& operator+=(const Vector3 &rhs);
	Vector3 operator-(const Vector3 &rhs) const;
	Vector3& operator -=(const Vector3 &rhs);
	Vector3 operator*(const Vector3 &rhs) const;
	Vector3& operator*=(const Vector3 &rhs);

	bool operator==(const Vector3 &rhs) const;
	bool operator!=(const Vector3 &rhs) const;

	float& operator[] (int index);
	void * operator new(size_t size);
	void operator delete(void * ptr);



};




#endif