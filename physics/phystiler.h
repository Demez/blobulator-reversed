#pragma once

#include "blobulator/implicit/impparticle.h"
#include "blobulator/physics/physparticlecache_inl.h"
#include "blobulator/point3d.h"
#include "blobulator/smartarray.h"

// Do functions
class PhysTilerFactory
{

};

// TODO
class PhysTile
{
};

class PhysTiler;

// FINISH
DECL_ALIGN(4) class PhysTileIterator
{
	friend class PhysTiler; // the only constructor is private, so i assume only PhysTiler may use it
public:
	void reset();

	int n;
	PhysTiler* tiler;

private:
	PhysTileIterator(PhysTiler*);
};

// Do functions
class PhysTiler
{
public:
	PhysTiler(PhysParticleCache*);
	PhysTiler(float, float);

	PhysTileIterator* acquireIterator();
	void releaseIterator(PhysTileIterator*);

	void beginFrame(Point3D&);
	void beginIteration();

	void endFrame();
	void endIteration();

	PhysParticle* getNextParticleAndNeighbors(PhysParticle***, int*);

	void insertParticle(PhysParticle*);

	void setCacheParams(float, float);

	PhysParticleCache* m_pParticleCache;

private:
	PhysTile* createTile(int, int, int);
	PhysTile* findTile(int, int, int);


	Point3D calcTileCorner(int, int, int);
	Point3D calcTileOffset(int, int, int);

	unsigned char field_0x4;
	unsigned char field_0x5;
	unsigned char field_0x6;
	unsigned char field_0x7;
	unsigned char field_0x8;
	unsigned char field_0x9;
	unsigned char field_0xa;
	unsigned char field_0xb;
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
	PhysTileIterator* iterator;
	bool iterator_active;
	unsigned char field_0x21;
	unsigned char field_0x22;
	unsigned char field_0x23;
	PhysTile* iteration_tile;
	int iteration_tile_num;
	int iteration_particle_count;
	int iteration_particle_num;
	unsigned char field_0x34;
	unsigned char field_0x35;
	unsigned char field_0x36;
	unsigned char field_0x37;
	unsigned char field_0x38;
	unsigned char field_0x39;
	unsigned char field_0x3a;
	unsigned char field_0x3b;
	unsigned char field_0x3c;
	unsigned char field_0x3d;
	unsigned char field_0x3e;
	unsigned char field_0x3f;
	Point3D offset;
	Point3D outer_cache_dim;
	Point3D render_dim;
	float render_margin;
	unsigned char field_0x74;
	unsigned char field_0x75;
	unsigned char field_0x76;
	unsigned char field_0x77;
	unsigned char field_0x78;
	unsigned char field_0x79;
	unsigned char field_0x7a;
	unsigned char field_0x7b;
	unsigned char field_0x7c;
	unsigned char field_0x7d;
	unsigned char field_0x7e;
	unsigned char field_0x7f;
	Point3D corner_offset;
};