#pragma once

#include "tier0/platform.h"
#include <xmmintrin.h>

DECL_ALIGN(4) class Point3D
{
public:

	Point3D();
	Point3D(float, float, float);

	Point3D crossProduct(const Point3D&) const;
	float dot(const Point3D&) const;
	float length() const;

	Point3D& mult(float);
	Point3D& normalize();

	Point3D operator*(float) const;
	Point3D operator+(const Point3D&) const;
	Point3D operator-(const Point3D&) const;
	Point3D operator/(Point3D*) const;
	Point3D operator/(float) const;

	float& operator[](int);
	const float operator[](int) const;

	void set(float, float, float);

	/*DECL_ALIGN(4)*/ union
	{
		__m128 sse_vec3;
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
	unsigned char y, z;
};