#pragma once

#include "blobulator/implicit/impparticle.h"
#include "blobulator/point3d.h"

class ProjectingParticleCache
{
public:
	ProjectingParticleCache();
	~ProjectingParticleCache();

	void addParticle(ImpParticle*);
	
	void beginTile();
	void endTile();

	void beginSlice(unsigned char);
	void endSlice(unsigned char);

	void setOffset(Point3D*);

	void buildCache(float, float, Point3D*, Point3D*);

private:
	void insertIntoCache(ImpParticle *, float, float, Point3D*, Point3D*);
};