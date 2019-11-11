#pragma once

#include "tier0/platform.h"
#include "materialsystem/IMesh.h"

#include "blobulator/implicit/imptiler.h"
#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/projectingparticlecache.h"
#include "blobulator/point3d.h"
#include "blobulator/smartarray.h"

#define RENDERER_CLASS SweepRenderer

// TODO: Find missing members of SweepRenderer (and maybe functions)

/*
	The following structs are accurate other than
	maybe the suspciious bit field in Slice_t.
*/

// TODO: Remove these to their respective files

struct YZ
{
	unsigned char y, z;
};

struct XYZ
{
	unsigned char x, y, z;
};

struct CubeInfo_s_0
{
	unsigned short cornerInfoNo;
	bool doneAbove, doneBelow : 1;
};

union DECL_ALIGN(4) CubeInfo
{
	CubeInfo_s_0 _s_0;
	unsigned int everything;
};

// 40 bits
struct Slice_t
{
	CubeInfo* corners[101];					/* offset: 0  */
	bool b1, b2, b3, b4, b5, b6, b7, b8, 	/* offset: 4-15 */
		b9, b10, b11, b12, b13, b14, b15, b16; // this isn't a bit-field woops
	SmartArray<YZ, 0, 0> todo_list;			/* offset: 16 */
	SmartArray<YZ, 0, 16> seed_list;		/* offset: 28 */
};

struct DECL_ALIGN(2) vbId_t
{
	unsigned short time;
	unsigned short id;
};

struct DECL_ALIGN(4) CornerInfo
{
	float value;
	float normal[3];
	vbId_t edges[3];
	CornerInfo* next;
	unsigned char x, y, z;
	unsigned char dones;
};

struct DECL_ALIGN(4) IndexTriVertexBuffer
{
	unsigned short m_curTime;
	unsigned short m_nVerticesOutput;
	IMesh* m_pMesh;
	CMeshBuilder* m_pBuilder;
	unsigned short m_stat_no_flashes;
};

struct ImpTile;

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

	ProjectingParticleCache* pCache;
	IndexTriVertexBuffer* vertexBuffer;
	int maxNoSlicesToDraw;
	int last_slice_drawn;
	bool polygonizationEnabled;
	undefined field_0x11;
	undefined field_0x12;
	undefined field_0x13;
	undefined field_0x14;
	undefined field_0x15;
	undefined field_0x16;
	undefined field_0x17;
	undefined field_0x18;
	undefined field_0x19;
	undefined field_0x1a;
	undefined field_0x1b;
	undefined field_0x1c;
	undefined field_0x1d;
	undefined field_0x1e;
	undefined field_0x1f;
	Point3D offset;
	Point3D outerBBMins;
	Point3D outerBBMaxs;
	Point3D innerBBMins;
	Point3D innerBBMaxs;
	undefined field_0x70;
	undefined field_0x71;
	undefined field_0x72;
	undefined field_0x73;
	undefined field_0x74;
	undefined field_0x75;
	undefined field_0x76;
	undefined field_0x77;
	undefined field_0x78;
	undefined field_0x79;
	undefined field_0x7a;
	undefined field_0x7b;
	Slice_t slices[102];
	undefined field_0x106c;
	undefined field_0x106d;
	undefined field_0x106e;
	undefined field_0x106f;
	undefined field_0x1070;
	undefined field_0x1071;
	undefined field_0x1072;
	undefined field_0x1073;
	undefined field_0x1074;
	undefined field_0x1075;
	undefined field_0x1076;
	undefined field_0x1077;
	undefined field_0x1078;
	undefined field_0x1079;
	undefined field_0x107a;
	undefined field_0x107b;
	undefined field_0x107c;
	undefined field_0x107d;
	undefined field_0x107e;
	undefined field_0x107f;
	undefined field_0x1080;
	undefined field_0x1081;
	undefined field_0x1082;
	undefined field_0x1083;
	SmartArray<SmartArray<YZ, 0, 0>, 0, 16> unused_todo_lists;
	int n_alloced_slice_corners;
	int n_alloced_slice_corner_infos;
	int n_alloced_slice_todo_lists;

/*	float oneOverCubewidth;
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
	bool tile_mode;*/
};