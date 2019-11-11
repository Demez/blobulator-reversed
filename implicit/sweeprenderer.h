#pragma once

#include "blobulator/implicit/imptiler.h"
#include "blobulator/implicit/projectingparticlecache.h"
#include "blobulator/point3d.h"

#define RENDERER_CLASS SweepRenderer

// TODO: Finish defining Slice_t
// TODO: Find missing members of SweepRenderer (and maybe functions)

struct CubeInfo_s_0
{
	ushort cornerInfoNo;
	bool doneAbove, doneBelow : 1;
};

union CubeInfo
{
	CubeInfo_s_0 _s_0;
	uint everything;
} align();

// 40 bits
struct Slice_t
{
	CubeInfo* corners[101];					/* offset: 0  */
	bool b1, b2, b3, b4, b5, b6, b7, b8, 	/* offset: 4-15 */
	b9, b10, b11, b12, b13, b14, b15, b16 : 1;
	SmartArray<YZ, 0, 0> todo_list;			/* offset: 16 */
	SmartArray<YZ, 0, 16> seed_list;		/* offset: 28 */
};

struct vbId_t
{
	ushort time;
	ushort id;
} align();

struct CornerInfo
{
	float value;
	float normal[3];
	vbId_t edges[3];
	CornerInfo* next;
	uchar x, y, z;
	uchar dones;
} align();

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