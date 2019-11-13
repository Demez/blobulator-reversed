#pragma once

#include "tier0/platform.h"

DECL_ALIGN(4) struct Point3D
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
	const float operator[](int) const;

	float unit();

	void set(int, int, int);
	
	DECL_ALIGN(4) union
	{
		__m128 sse_vec;
		float p[4];
	};
};

DECL_ALIGN(1) struct YZ
{
	unsigned char y, z;
};

DECL_ALIGN(1) struct XYZ
{
	unsigned char x, y, z;
};

DECL_ALIGN(1) struct pcache_YZ_t
{
	unsigned char y;
	unsigned char z;
};