#pragma once

#include "tier0/platform.h"
#include "materialsystem/IMesh.h"

#include "blobulator/implicit/imptiler.h"
#include "blobulator/implicit/impparticle.h"
#include "blobulator/implicit/projectingparticlecache.h"
#include "blobulator/implicit/userfunctions.h"
#include "blobulator/point3d.h"
#include "blobulator/smartarray.h"

#ifndef RENDERER_CLASS
#define RENDERER_CLASS SweepRenderer
#endif

// TODO: Find missing members of SweepRenderer (and maybe functions)
// TODO: Remove these to their respective files

DECL_ALIGN(4) union CubeInfo
{
	DECL_ALIGN(2) struct
	{
		unsigned short cornerInfoNo;
		bool doneAbove, doneBelow : 1;
	};
	unsigned int everything;
};

// 40 bits
struct Slice_t
{
	CubeInfo* corners[101];					/* offset: 0	*/
	unsigned char field_0x4;				/* offset: 4-15 */
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
	SmartArray<YZ, 0, 0> todo_list;			/* offset: 16	*/
	SmartArray<YZ, 0, 16> seed_list;		/* offset: 28	*/
};

DECL_ALIGN(2) struct vbId_t
{
	unsigned short time;
	unsigned short id;
};

DECL_ALIGN(4) struct CornerInfo
{
	float value;
	float normal[3];
	vbId_t edges[3];
	CornerInfo* next;
	unsigned char x, y, z;
	unsigned char dones;
};

DECL_ALIGN(4) struct IndexTriVertexBuffer
{
	unsigned short m_curTime;
	unsigned short m_nVerticesOutput;
	IMesh* m_pMesh;
	CMeshBuilder* m_pBuilder;
	unsigned short m_stat_no_flashes;
};

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

	Point3D* getInnerDimensions();

	int getMarginNCubes();
	float getMarginWidth();

	static void setCubeWidth(float);
	static float getCubeWidth();

	static void setCutoffR(float);
	static float getCutoffR();

	static void setRenderR(float);
	static float getRenderR();

	bool isParticleWithinBounds(ImpParticle*);

	void setOffset(Point3D*);

	void recalculateBB();
	void recalculateDimensions();

	void render_slice(unsigned char, Slice_t*, Slice_t*, Slice_t*);
	void render_slices();

	void seed_surface(Point3D*);

	static void setCalcCornerFunc(tCalcCornerFunc pfnCornerFunc);
	static void setCalcSign2Func(tCalcSign2Func pfnSign2Func);
	static void setCalcSignFunc(tCalcSignFunc pfnSignFunc);
	static void setCalcVertexFunc(tCalcVertexFunc pfnVertexFunc);

	ProjectingParticleCache* pCache;
	IndexTriVertexBuffer* vertexBuffer;
	int maxNoSlicesToDraw;
	int last_slice_drawn;
	bool polygonizationEnabled;
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
	Point3D offset;
	Point3D outerBBMins;
	Point3D outerBBMaxs;
	Point3D innerBBMins;
	Point3D innerBBMaxs;
	unsigned char field_0x70;
	unsigned char field_0x71;
	unsigned char field_0x72;
	unsigned char field_0x73;
	unsigned char field_0x74;
	unsigned char field_0x75;
	unsigned char field_0x76;
	unsigned char field_0x77;
	unsigned char field_0x78;
	unsigned char field_0x79;
	unsigned char field_0x7a;
	unsigned char field_0x7b;
	Slice_t slices[102];
	unsigned char field_0x106c;
	unsigned char field_0x106d;
	unsigned char field_0x106e;
	unsigned char field_0x106f;
	unsigned char field_0x1070;
	unsigned char field_0x1071;
	unsigned char field_0x1072;
	unsigned char field_0x1073;
	unsigned char field_0x1074;
	unsigned char field_0x1075;
	unsigned char field_0x1076;
	unsigned char field_0x1077;
	unsigned char field_0x1078;
	unsigned char field_0x1079;
	unsigned char field_0x107a;
	unsigned char field_0x107b;
	unsigned char field_0x107c;
	unsigned char field_0x107d;
	unsigned char field_0x107e;
	unsigned char field_0x107f;
	unsigned char field_0x1080;
	unsigned char field_0x1081;
	unsigned char field_0x1082;
	unsigned char field_0x1083;
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