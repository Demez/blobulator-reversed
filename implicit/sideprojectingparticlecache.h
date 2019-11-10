#pragma once

#include "blobulator/implicit/impparticle.h"
#include "blobulator/Point3D.h"

class SideProjectingParticleCache
{
public:
	SideProjectingParticleCache();
	~SideProjectingParticleCache();

	void addParticle(ImpParticle*);

	void beginSlice(unsigned char);
	void endSlice(unsigned char);

	void beginTile();
	void endTile();

	void beginSlice(unsigned char);
	void endSlice(unsigned char);

	void setOffset(Point3D*);

	void buildCache(float, float, Point3D*, Point3D*);

private:
	void clearSlicesData(PCacheSlice_t *);

	void insertParticleIntoSlice(PCacheSlice_t *, PCacheParticle_t *);
	void allocSliceData(PCacheSlice_t*);

	void insertIntoCache(ImpParticle*, float, float, Point3D*, Point3D*);

	unsigned int const botSentinel;
	int const max_clearableSlices
};