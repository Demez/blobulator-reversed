#pragma once

class Point3D
{
public:

	Point3D();
	Point3D(int, int, int);

	Point3D* crossProduct(Point3D*);
	float dot(Point3D*);
	float length();

	Point3D* mult(float);
	Point3D* normalize();

	Point3D* operator*(float);
	Point3D* operator+(Point3D*);
	Point3D* operator-(Point3D*);
	Point3D* operator/(Point3D*);
	Point3D* operator/(float);

	float* operator[](int);
	float operator[](int);

	float unit();

	void set(int, int, int);
};