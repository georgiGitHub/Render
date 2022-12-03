#pragma once
#include "Vector.h"

static const int maxColorComponent = 255;
class Color {
public:
	Color();
	//Getter
	float getR() {
		return r;
	}
	float getG() {
		return g;
	}
	float getB() {
		return b;
	}


	//Setter
	void setR(float a) {
		if (a > 255) a = 255;
		r = a;
	}
	void setG(float a) {
		if (a > 255) a = 255;
		g = a;
	}
	void setB(float a) {
		if (a > 255) a = 255;
		b = a;
	}

	
private:
	float r;
	float g;
	float b;
};
Color::Color() {
	r = 0;
	g = 0;
	b = 0;
	
}