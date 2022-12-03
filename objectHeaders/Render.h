#pragma once
#include "Vector.h"
#include "Ray.h"
#include "Triangle.h"
#include "Lights.h"
#include "Color.h"
#include "Settings.h"
#include "Mesh.h"
#include "Material.h"
#include <math.h>
#include <iostream>
#define crtTab "\t"
static const Vector ALBEDO = Vector(0.8f, 0.8f, 0.8f);
static const float SHADOW_BIAS = 0.001f;

bool findIntersection(Ray& ray,  Triangle tri,const Camera& cam){
	bool answer = false;
	Vector hitNormal;// = Vector(0,0,0);
	//&& dot(tri.v(0), tri.getNormal()) < 0.f
	if (dot(tri.getNormal(), ray.getDirection()) < 0.f ) {
		//calculate distance from ray.origin to ray project
		float rProj = dot(tri.getNormal(), ray.getDirection());
		//float rProj = dot(ray.getDirection() , tri.getNormal());
		//calculate distance from ray.origin to plane
		float rpDist = dot(tri.v(0),tri.getNormal());
		
		//calculate distance from ray.origin to plane and project it to plane
		
		float t = (-dot(tri.getNormal(), ray.getOrigin()) + rpDist) / rProj;
		//calculate parametric equation (Параметрично уравнение на лъч)
		Vector P = Vector(ray.getOrigin() + (ray.getDirection() * t));
		ray.setHitPoint(P);
		
		//check P is near by triangle
		Vector V0P = Vector(P - tri.v(0));
		Vector V1P = Vector(P - tri.v(1));
		Vector V2P = Vector(P - tri.v(2));
		
		float checkSideOne = dot(tri.getNormal(), tri.E0().cross(V0P));
		float checkSideTwo = dot(tri.getNormal(), tri.E1().cross(V1P));
		float checkSideThree = dot(tri.getNormal(), tri.E2().cross(V2P));
		
		if (t >= 0.0f && checkSideOne >= 0.0f && checkSideTwo >= 0.0f && checkSideThree >= 0.0f) {
			Vector v0v1 = Vector(tri.v(1)-tri.v(0));
			Vector v0v2 = Vector(tri.v(2)-tri.v(0));
			float u = (V0P.cross(v0v2)).length() / (v0v1.cross(v0v2)).length();
			float v = (v0v1.cross(V0P)).length() / (v0v1.cross(v0v2)).length();
			float w = 1 - u - v;
			answer = true;
			hitNormal = tri.V1N() * u + tri.V2N() * v + tri.V0N() * w;
			ray.setHitNormal(hitNormal);
		}
	}
	return answer;
}

Color shading(Vector& point, const Vector& Normal, Settings settings, Lights lights, Camera cam, Mesh mesh,int materialIndex) {
	Vector finalColor = Vector(0,0,0);
	bool check = false;
	Vector LightContribution;
	for (int lightIndex = 0; lightIndex < lights.getAllLights(); lightIndex++) {
		Vector lightDir = lights.getPostion(lightIndex) - point;
		//lightDir.normalize();
		float sphereRadios = lightDir.length();
		//std::cout<<dot(lightDir,Normal)
		lightDir.normalize();
		//float cosLaw = std::max(0.0f, dot(lightDir, Normal));
		float cosLaw =  dot(lightDir, Normal);
		float sphereArea = 4 * PI * sphereRadios * sphereRadios;

		bool checkForNotIntersect = false;
		Ray shadowRay(point + Normal * SHADOW_BIAS, lightDir);
		
		
		float li = lights.getIntensity(lightIndex);
		int index;
		for (int i = 0; i < mesh.getObject(); i++) {
				for(int j = 0; j < mesh.getTriangles(i);j++) {
				
					if (findIntersection(shadowRay, mesh.getTriangle(i,j),cam) == true) {
						checkForNotIntersect = true;
						index = i;
						break;
					}

				}
			
		}
		if (checkForNotIntersect == true) {
			if(index == materialIndex) {
				float r = (float)(li / sphereArea * ALBEDO.x * cosLaw);
			float g = (float)(li / sphereArea * ALBEDO.y * cosLaw);
			float b = (float)(li / sphereArea * ALBEDO.z * cosLaw);
			
			LightContribution = Vector(r, g, b);
			}
			else
				LightContribution = Vector(0,0,0);
		}
		else {
			float r = (float)(li / sphereArea * ALBEDO.x * cosLaw);
			float g = (float)(li / sphereArea * ALBEDO.y * cosLaw);
			float b = (float)(li / sphereArea * ALBEDO.z * cosLaw);
			
			LightContribution = Vector(r, g, b);
		}
		finalColor = finalColor + LightContribution;
	}
	Color ans;
	ans.setR(abs(finalColor.x * maxColorComponent));
	ans.setG(abs(finalColor.y * maxColorComponent));
	ans.setB(abs(finalColor.z * maxColorComponent));
	
	return ans;
}