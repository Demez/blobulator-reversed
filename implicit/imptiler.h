#pragma once

#include "blobulator/point3d.h"
#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/sweeprenderer.h"

#ifdef LINK_TEST
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

class ImpTile;
class SweepRenderer;

class ImpTiler
{
#ifdef LINK_TEST
	friend int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);
#endif
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
	ImpTilerFactory();

	ImpTiler* getTiler();
	void returnTiler(ImpTiler*);
};