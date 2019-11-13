#pragma once

#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/userfunctions.h"
#include "blobulator/point3d.h"
#include "blobulator/smartarray.h"

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

	void insertIntoCache(ImpParticle*, float, float, Point3D*, Point3D*);

	PCacheElem_t* botSentinel;
	PCacheElem_t* midSentinel;
	PCacheElem_t* topSentinel;
	unsigned char field_0xc;
	unsigned char field_0xd;
	unsigned char field_0xe;
	unsigned char field_0xf;
	unsigned char field_0x10;
	unsigned char field_0x11;
	unsigned char field_0x12;
	unsigned char field_0x13;
	unsigned char field_0x14;
	unsigned char field_0x15;
	unsigned char field_0x16;
	unsigned char field_0x17;
	unsigned char field_0x18;
	unsigned char field_0x19;
	unsigned char field_0x1a;
	unsigned char field_0x1b;
	unsigned char field_0x1c;
	unsigned char field_0x1d;
	unsigned char field_0x1e;
	unsigned char field_0x1f;
	unsigned char field_0x20;
	unsigned char field_0x21;
	unsigned char field_0x22;
	unsigned char field_0x23;
	SmartArray<pcache_YZ_t, 0, 16> clearList;
	int curCacheElement;
	PCacheElem_t** cachePlane[101];
};