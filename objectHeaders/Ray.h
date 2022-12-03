#pragma once
#include "Vector.h"
#include "Camera.h"
class Ray {
public:
	Ray() : origin(), direction(0.0, 0.0, -1.0) {}
	Ray(const Vector& origin, const Vector& direction) : origin(origin), direction(direction)
	{
		this->direction.normalize();
	}
	// getters
	Vector getOrigin() const { return origin; }
	Vector getDirection() const { return direction; }
	Vector getHitPoint()  { return hitPoint; }
	Vector getHitNormal()  { return hitNormal; }
	//setter
	void setHitPoint(Vector& v) {
		hitPoint = v;
	}
	void setHitNormal(Vector& v) {
		hitNormal = v;
	}
private:
	Vector origin;
	Vector direction;
	Vector hitPoint;
	Vector hitNormal;
};
Ray createRay(int rowIdx,int colIdx,int imageWidth,int imageHeight,Camera cam) {
	//find center pixcel
	float x = (float)rowIdx + 0.5f;
	float y = (float)colIdx + 0.5f;
	//convert raster to NDC
	x /= (float)(imageHeight * ((float)imageWidth / (float)imageHeight));
	y /= imageHeight;
	//convert NDC to screen
	x = (2.0f * x) - 1.0f;
	y = 1.0f - (2.0f * y);
	//aspect ration
	x = x * ((float)imageWidth / (float)imageHeight);
	return Ray(cam.getPosition(), cam.getOrientation()* Vector(x, y, -1.0f));
}