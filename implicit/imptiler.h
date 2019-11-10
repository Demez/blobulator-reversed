#pragma once

#include "blobulator/point3d.h"
#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/imprenderer.h"

class SweepRenderer;
class ImpTile;

class ImpTiler
{
public:
	ImpTiler(SweepRenderer*);
	~ImpTiler();

	void addParticleToTile(ImpParticle*, int, int, int);
	void insertParticle(ImpParticle*);

	void beginFrame(Point3D, void*, bool);
	void endFrame(void);

	ImpTile* createTile(int, int, int);
	ImpTile* findTile(int, int, int);

	Point3D calcTileCorner(int, int, int);
	Point3D calcTileOffset(int, int, int);

	void drawSurface(void);
	void drawSurfaceSorted(Point3D&);

	void drawTile(ImpTile*);
	void drawTile(int, int, int);

	int getNoTiles(void);
	ImpTile* getTile(int);
	Point3D getTileOffset(int);
};

class ImpTile
{
public:
	ImpTile(int, int, int);
	~ImpTile();
};

class ImpTilerFactory
{
public:
	ImpTilerFactory();

	ImpTiler* getTiler();
	void returnTiler(ImpTiler*);
};