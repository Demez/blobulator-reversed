#pragma once

#include "iclientrenderable.h"

#include "blobulator/point3d.h"
#include "blobulator/implicit/sweeprenderer.h"

#ifndef RENDERER_CLASS
#define RENDERER_CLASS ImpRenderer
#endif

// TODO: Finish
class ImpRendererFactory
{
public:
	ImpRendererFactory();

	SweepRenderer* getRenderer();
	void returnRenderer(SweepRenderer*);
};

// TODO: Finish
class ImpRenderer : public RenderableInstance_t
{
public:
	bool setCalcSignFunc(int math);

	void beginFrame(bool draw, void* renderCon);
	void setOffset(Point3D point);
	void setMaxNoSlicesToDraw(int many);
	void addParticle(ImpParticle* particle);
	void endTile();
	void endFrame();

	int getLastSliceDrawn();
	int getMarginNCubes();
	int getCubeWidth();
};