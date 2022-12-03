#pragma once
#include "Color.h"
class Settings {
public:
	//Settings();
	//Getters
	int getImageHeight() {
		return imageHeight;
	}
	int getImageWidth() {
		return imageHeight;
	}
	//setter
	void setImageHeight(int imageHeight) {
		imageHeight = this->imageHeight;
	}
	void setImageWidth(int imageWidth) {
		imageWidth = this->imageWidth;
	}
	
private:
	int imageWidth;
	int imageHeight;
};
