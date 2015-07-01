#ifndef VECTOR4
#define VECTOR4

class Vector4
{
public:
	Vector4();
	Vector4(float a_x, float a_y, float a_z, float a_t);
	~Vector4();


	float x;
	float y;
	float z;
	float t;

	Vector4 operator+(const Vector4 &rhs) const;
	Vector4& operator+=(const Vector4 &rhs);
	Vector4 operator-(const Vector4 &rhs) const;
	Vector4& operator-=(const Vector4 &rhs);
	Vector4 operator*(const float &rhs) const;
	Vector4& operator*=(const float &rhs);

	bool operator==(const Vector4 &rhs) const;
	bool operator!=(const Vector4 &rhs) const;

	float Magnitude() const;

	float& operator[] (int index);
	void * operator new(size_t size);
	void operator delete(void * ptr);

	/*friend std::ostream& operator<<(std::ostream &os, const Vector4 &rhs);
	friend std::istream& operator>>(std::istream &is, const Vector4 &rhs);
	friend Vector4 operator*(const float lhs, const Vector4& rhs);
*/
};





#endif