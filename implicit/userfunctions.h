#pragma once

// TODO: I don't know where these are actually meant to be defined

#include "blobulator/smartarray.h"

class ImpParticle;

// NOTE: The following types I believe are accurate

struct PCacheElem_t
{
	short center_x;
	unsigned char bot_x;
	unsigned char top_x;
	PCacheElem_t* prev;
	PCacheElem_t* next;
	ImpParticle* p;
};

struct PSliceData_t
{
	unsigned int zArray[101];
	SmartArray<PCacheElem_t, 0, 16> cacheElements;
	unsigned char field_0x1a0;
	unsigned char field_0x1a1;
	unsigned char field_0x1a2;
	unsigned char field_0x1a3;
	unsigned char field_0x1a4;
	unsigned char field_0x1a5;
	unsigned char field_0x1a6;
	unsigned char field_0x1a7;
	unsigned char field_0x1a8;
	unsigned char field_0x1a9;
	unsigned char field_0x1aa;
	unsigned char field_0x1ab;
	int max_cache_elements_size;
};

struct PCacheSlice_t
{
	PSliceData_t* sliceData;
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

DECL_ALIGN(4) class IndexTriVertexBuffer
{
	unsigned short m_curTime;
	unsigned short m_nVerticesOutput;
	IMesh* m_pMesh;
	CMeshBuilder* m_pBuilder;
	unsigned short m_stat_no_flashes;
};

class ProjectingParticleCache;

typedef void (__cdecl*tCalcCornerFunc)(unsigned char, unsigned char, unsigned char, float, float, float, CornerInfo*, ProjectingParticleCache*);
typedef void (__cdecl*tCalcSign2Func)(unsigned char, unsigned char, unsigned char, float, float, float, CornerInfo*, ProjectingParticleCache*);
typedef void (__cdecl*tCalcSignFunc)(unsigned char, unsigned char, unsigned char, float, float, float, ProjectingParticleCache*);
typedef void (__cdecl*tCalcVertexFunc)(float, float, float, int, CornerInfo* const, CornerInfo* const, IndexTriVertexBuffer*);

#pragma warning(push, 0)
const __m128 Four_Zeros;
#pragma warning(pop)