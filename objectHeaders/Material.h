#pragma once
#include <string>
#include "Vector.h"
#include <vector>
class Material {
public:
	//Material();
    //Getter
    Vector getAlbedo(int index) {
        return albedo[index];
    }
    std::string getType(int index) {
        return type[index];
    }
    bool getSmoothShading(int index) {
        return smoothShading[index];
    }
	//Setter
	void setType(std::string type) {
        this -> type.emplace_back (type);
    }
    void setAlbedo(Vector albedo) {
        this -> albedo.emplace_back(albedo);
    }
    void setSmoothShading(bool smoothShading) {
        this -> smoothShading.emplace_back(smoothShading);
    }
	
private:
	std::vector <std::string>type;
    std::vector <Vector> albedo;
    std::vector <bool> smoothShading;
};