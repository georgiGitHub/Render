#pragma once
#include "Matrix.h"
class Camera {
public:
	Camera() :position(), orientation(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f) {}
	Camera(const Vector& position, const Matrix& orientation) : position(position), orientation(orientation) {};
	//move effects
	void truck(float dist);
	void dolly(float dist);
	void pedestal(float dist);
	void pan(float angle);
	void tilt(float angle);
	void roll(float angle);
	//Getters
	Matrix getOrientation()const {
		return orientation;
	};
	Vector getPosition()const {
		return position;
	}
	//Setter
	void setOrientation(const Matrix& newOrientation) {
		orientation = newOrientation;
	}
	void setPosition(const Vector& newPos) {
		position = newPos;
	}
private:
	Matrix orientation;
	Vector position;
};
void Camera::truck(float dist) {
	position = Vector(position.x +dist,position.y,position.z);
}
void Camera::dolly(float dist) {
	position = Vector(position.x, position.y, position.z + dist);
}
void Camera::pedestal(float dist) {
	position = Vector(position.x, position.y + dist, position.z);
}
void Camera::pan(float angle) {
	double c = cos(angle * PI / 180);
	double s = sin(angle * PI / 180);
	orientation = Matrix(
		c, 0, -s,
		0, 1, 0,
		s, 0, c
	);
}
void Camera::tilt(float angle) {
	double c = cos(angle * PI / 180);
	double s = sin(angle * PI / 180);
	orientation = Matrix(
		1, 0, 0,
		0, c, -s,
		0, s, c
	);
}
void Camera::roll(float angle) {
	double c = cos(angle * PI / 180);
	double s = sin(angle * PI / 180);
	orientation = Matrix(
		c, -s, 0,
		s, c, 0,
		0, 0, 1
	);
}