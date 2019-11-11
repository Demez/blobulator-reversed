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
	bool b1, b2, b3, b4, b5, b6, 
		b7, b8, b9, b10, b11, b12; // not a bit field woops
	int max_cache_elements_size;
};

struct PCacheSlice_t
{
	PSliceData_t* sliceData;
};