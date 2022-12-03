#pragma once
#include <vector>
#include "Vector.h"
#include "Triangle.h"

class Mesh {
public:
	//Getters
	int getMaterialIndex(int i){
		return materialIndex[i];
	}
	Vector getVertecs(int index) {
		return verts[index];
	}
	Triangle getTriangle(int i,int j) {
		return triangles[i][j];
	}
	int getTriangles(int i) {
		return triangles[i].size();
	}
	int getObject() {
		return objects;
	}
	int size() {
		return triangles.size();
	}
	//Setters
	void setMaterialIndex (int x) {
		materialIndex.emplace_back(x);
	}
	void setVertecs(Vector vert) {
		verts.emplace_back(vert);
	}
	void setTriangles(std::vector<Triangle> triangle) {
		triangles.emplace_back(triangle);
	}
	void setObject(int k) {
		objects = k;
	}
	void clearVertecs() {
		verts.clear();
	}
private:
	std::vector<Vector> verts;
	std::vector<std::vector<Triangle>> triangles;
	int objects;
	std::vector<Triangle> alltriangle;
	std::vector<int> materialIndex;
};