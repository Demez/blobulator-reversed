#pragma once

#include "blobulator/point3d.h"

struct PhysParticle
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

	Point3D* getInnerDimensions();
	Point3D* getOuterDimensions();

	void generateCheckList(float, float);
	float getMarginWidth();

	void insertParticle(PhysParticle*);

	void recalculateBB();
	void recalculateDimensions();

	void setCacheParams(float, float);

	void setOffset(Point3D*);
};