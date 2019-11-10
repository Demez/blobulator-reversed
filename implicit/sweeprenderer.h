#pragma once

#include "blobulator/implicit/imptiler.h"
#include "blobulator/implicit/projectingparticlecache.h"
#include "blobulator/point3d.h"

#define RENDERER_CLASS SweepRenderer

// TODO: Finish defining Slice_t
// TODO: Find missing members of SweepRenderer (and maybe functions)

struct Slice_t
{
	Slice_t()
	{
		d7 = 16;
	}
	~Slice_t()
	{
		free(&d7); // 28
		free(p); // 8
		if (d1 != 0)
		{
			(**(code * *)(**(int**)g_pMemAlloc_exref + 0x14))(*(undefined4*)((*(uint*)& this->field_0x4 & 0xfffffffc) - 4));
			*(g_pMemAlloc + 20)(((this + 4) & 0xFFFFFFFC) - 4);
		}
	}

	void* p;
	uint d1, d2, d3, d4, d5, d6, d7;
	uint data
};

struct CornerInfo;
class IndexTriVertexBuffer;
class ImpParticle;
class ImpTile;
class Point3D;

typedef void (*)(unsigned char, unsigned char, unsigned char, float, float, float, CornerInfo*, ProjectingParticleCache*) tCalcCornerFunc;
typedef void (*)(unsigned char, unsigned char, unsigned char, float, float, float, CornerInfo*, ProjectingParticleCache*) tCalcSign2Func;
typedef void (*)(unsigned char, unsigned char, unsigned char, float, float, float, ProjectingParticleCache*) tCalcSignFunc;
typedef void (*)(float, float, float, int, CornerInfo*, CornerInfo*, IndexTriVertexBuffer*) tCalcVertexFunc;

class SweepRenderer
{
public:
	SweepRenderer();

	void addParticle(ImpParticle*, bool);

	void changeCubeWidth(float);
	void changeRadii(float, float);

	void allocSliceCorners(Slice_t*);
	void allocSliceTodoList(Slice_t*);

	void deallocSliceCorners(Slice_t*);
	void deallocSliceTodoList(Slice_t*);

	void beginFrame(bool, void *);
	void endFrame();

	void beginTile(ImpTile*);
	void endTitle();

	void addParticle(ImpParticle*, bool);

	Point3D* getInnerDimensions();

	int getMarginNCubes();
	float getMarginWidth();

	void setCubeWidth(float);
	float getCubeWidth();

	void setCutoffR(float);
	float getCutoffR();

	void setRenderR(float);
	float getRenderR();

	bool isParticleWithinBounds(ImpParticle*);

	void setOffset(Point3D*);

	void recalculateBB();
	void recalculateDimensions();

	void render_slice(unsigned char, Slice_t*, Slice_t*, Slice_t*);
	void render_slices();

	void seed_surface(Point3D*);

	void setCalcCornerFunc(tCalcCornerFunc pfnCornerFunc);
	void setCalcSign2Func(tCalcSign2Func pfnSign2Func);
	void setCalcSignFunc(tCalcSignFunc pfnSignFunc);
	void setCalcVertexFunc(tCalcVertexFunc pfnVertexFunc);

	float oneOverCubewidth;
	float oneOverThreshold;
	float addAmt;
	int cornerInfoSize;
	float cubeWidth;
	float cutoffR;
	float cutoffRSq;
	short fieldCalcSteps;
	float threshold;
	float renderR;
	float scaledRenderRSq;
	float scaler;
	float scalerSq;

private:
	int marginNCubes;
	float marginWidth;
	Point3D outerDimensions;
	Point3D innerDimensions;
	bool tile_mode;
};