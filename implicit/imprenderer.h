#pragma once

#include "iclientrenderable.h"

#include "blobulator/point3d.h"
#include "blobulator/implicit/sweeprenderer.h"

#ifndef RENDERER_CLASS
#define RENDERER_CLASS ImpRenderer
#endif

static class ImpRendererFactory
{
public:
	ImpRendererFactory();

	SweepRenderer* getRenderer();
	void returnRenderer(SweepRenderer*);
} factory;