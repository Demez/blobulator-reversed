#pragma once

#include "blobulator/point3d.h"
#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/sweeprenderer.h"

class ImpTile;
class SweepRenderer;

class ImpTiler
{
public:
	ImpTiler(SweepRenderer*);
	~ImpTiler();

	void insertParticle(ImpParticle*);

	void beginFrame(Point3D&, void*, bool);
	void endFrame(void);

	void drawSurface(void);
	void drawSurfaceSorted(Point3D&);

	void drawTile(ImpTile*);
	void drawTile(int, int, int);

	int getNoTiles(void);
	ImpTile* getTile(int);
	Point3D getTileOffset(int);

private:
	void addParticleToTile(ImpParticle*, int, int, int);
	ImpTile* findTile(int, int, int);
	ImpTile* createTile(int, int, int);
	Point3D calcTileCorner(int, int, int);
	Point3D calcTileOffset(int, int, int);

	SweepRenderer* m_sweepRenderer;
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
	int maxNoTilesToDraw;
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
	Point3D last_tiles_offset;
	Point3D offset;
	Point3D render_dim;
	float render_margin;
	unsigned char field_0x54;
	unsigned char field_0x55;
	unsigned char field_0x56;
	unsigned char field_0x57;
	unsigned char field_0x58;
	unsigned char field_0x59;
	unsigned char field_0x5a;
	unsigned char field_0x5b;
	unsigned char field_0x5c;
	unsigned char field_0x5d;
	unsigned char field_0x5e;
	unsigned char field_0x5f;
	Point3D corner_offset;
};

// 68 bytes
class ImpTile
{
public:
	ImpTile(int, int, int);
	~ImpTile();

    bool done;
	unsigned char field_0x1;
	unsigned char field_0x2;
	unsigned char field_0x3;
    int x, y, z;
    Point3D center;
    bool old_tile;
	unsigned char field_0x21;
	unsigned char field_0x22;
	unsigned char field_0x23;
	unsigned char field_0x24;
	unsigned char field_0x25;
	unsigned char field_0x26;
	unsigned char field_0x27;
	unsigned char field_0x28;
	unsigned char field_0x29;
	unsigned char field_0x2a;
	unsigned char field_0x2b;
	unsigned char field_0x2c;
	unsigned char field_0x2d;
	unsigned char field_0x2e;
	unsigned char field_0x2f;
    Point3D debug_color;
    float dist;
};

class ImpTilerFactory
{
public:

	ImpTiler* getTiler();
	void returnTiler(ImpTiler*);

	static ImpTilerFactory* factory;

private:
	ImpTilerFactory();
};