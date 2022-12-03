#pragma once
#include "Vector.h"
#include <vector>
class Lights {
public:
	//Lights();


	//Getter
	int getAllLights() {
		return position.size();
	}
	Vector getPostion(int index) {
		return position[index];
	}
	float getIntensity(int index) {
		return intensity[index];
	}
	//Setter
	void setPosition(Vector v) {
		position.push_back(v);
	}
	void setIntensity(float v) {
		intensity.push_back(v);
	}
private:
	std::vector <float> intensity;
	std::vector <Vector> position;
};
