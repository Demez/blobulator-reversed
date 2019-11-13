#pragma once

// Point3D_u_0 is suspicious

union Point3D_u_0
{
	__m128 sse_vec;
	float p[4];
};

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
	const float operator[](int) const;

	float unit();

	void set(int, int, int);
	
	Point3D_u_0 _u_0; // no name? is it meant to be private?
};


struct YZ
{
	unsigned char y, z;
};

struct XYZ
{
	unsigned char x, y, z;
};