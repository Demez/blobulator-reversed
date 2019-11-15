#pragma once

#include "blobulator/point3d.h"

class PhysParticle
{
	Point3D center;
	float radius;
	int temp1;
};

class PhysParticleCache
{
public:
	PhysParticleCache(float, float);

	void beginFrame();
	void endFrame();

	void beginTile(int);
	void endTile();

	void calcNeighbors(PhysParticle*, PhysParticle***, int*);

	Point3D getInnerDimensions();
	Point3D getOuterDimensions();

	float getMarginWidth();

	void insertParticle(PhysParticle*);
	void setCacheParams(float, float);

	void setOffset(Point3D&);

private:
	void generateCheckList(float, float);

	void recalculateBB();
	void recalculateDimensions();
};