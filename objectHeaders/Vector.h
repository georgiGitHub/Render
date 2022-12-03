#pragma once
#include <math.h>
#include <assert.h>
static const float EPSILON = 1e-7f;

class Vector {
public:
	
	Vector() : x(1.0), y(1.0), z(1.0) {};
	Vector(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	void print() {
		std::cout << x << " " << y << " " << z << std::endl;
	}
	// Calculate and return the length of the vector
	float length() const;
	Vector operator+(const Vector&) const;
	Vector operator-(const Vector&) const;
	Vector operator*(float) const;
	
	//vector -> perpendicular to A and B (right hand rule)
	Vector cross(const Vector& v) const;
	//dot product multiplication of two vectors
	//float dot(const Vector&, const Vector&) const;
	void normalize();
	float x;
	float y;
	float z;
};
float Vector::length()const {
		return sqrtf(x * x + y * y + z * z);
}
Vector Vector::operator+(const Vector& v)const {
	return Vector(x + v.x, y + v.y, z + v.z);
}
Vector Vector::operator-(const Vector& v)const {
	return Vector( x - v.x, y - v.y, z - v.z );
}
Vector Vector::operator*(float t)const {
	return Vector(x * t,y * t, z * t);
}

Vector Vector::cross(const Vector& v)const {
	return Vector(
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	);
}
float dot(const Vector& v,const Vector& v1) {
	float dott = ((v.x * v1.x) + (v.y * v1.y) + (v.z * v1.z));
	return dott;
}
void Vector::normalize() {
	float len = this->length();
	assert(abs(len) > EPSILON);
	float coeff = 1 / len;
	x = x * coeff;
	y = y * coeff;
	z = z * coeff;
}