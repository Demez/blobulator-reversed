#pragma once

// TODO: Is ImpParticle a struct or a class?
// TODO: Is this accurate code?

// 16 bits
class Point3D;

// 24 bits
struct ImpParticle
{
	Point3D center;			/* offset: 0	*/
	float fieldRScaleSQ;	/* offset: 16	*/
	float scale;			/* offset: 20	*/
};

// 48 bits
struct ImpParticleWithOneInterpolant : ImpParticle
{
	Point3D interpolants1;	/* offset: 32	*/
};

// 64 bits
struct ImpParticleWithTwoInterpolants : ImpParticleWithOneInterpolant
{
	Point3D interpolants2;	/* offset: 48	*/
};

// 96 bits
struct ImpParticleWithFourInterpolants : ImpParticleWithTwoInterpolants
{
	Point3D interpolants3;	/* offset: 64	*/
	Point3D interpolants4;	/* offset: 80	*/
};