#pragma once
#include <cmath>
#include "Vector.h"
#define PI 3.14159265
class Matrix {
public:
	Matrix();
	Matrix(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
	Vector operator* (const Vector& v1);
	void print() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				std::cout << m[i][j]<<" ";
			}
		}
	}
private:
	float m[3][3];
};
Matrix::Matrix() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			m[i][j] = 0.0f;
		}
	}
}
Matrix::Matrix(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;

	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;

	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;
}
Vector Matrix::operator*(const Vector& v) {
	return Vector(
		v.x * m[0][0] + v.y * m[0][1] + v.z * m[0][2],
		v.x * m[1][0] + v.y * m[1][1] + v.z * m[1][2],
		v.x * m[2][0] + v.y * m[2][1] + v.z * m[2][2]
	);

}