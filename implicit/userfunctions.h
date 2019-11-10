#pragma once

// TODO: I don't know where these are actually meant to be defined

struct ImpParticle;

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
	uint zArray[101];
	SmartArray<PCacheElem_t, 0, 16> cacheElements;
	/*
	I assume the 12 individual bits shown in Ghidra's
	Structure Editor here is a bit field of 12 bits
	*/
	bool b1 : 1;
	bool b2 : 1;
	bool b3 : 1;
	bool b4 : 1;
	bool b5 : 1;
	bool b6 : 1;
	bool b7 : 1;
	bool b8 : 1;
	bool b9 : 1;
	bool b10 : 1;
	bool b11 : 1;
	bool b12 : 1;
	int max_cache_elements_size;
};

struct PCacheSlice_t
{
	PSliceData_t* sliceData;
};