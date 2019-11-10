#pragma once

#include "blobulator/point3d.h"
#include "blobulator/implicit/imprenderer.h"

#define RENDERER_CLASS ImpRenderer

class ImpRendererFactory
{
public:
	ImpRendererFactory();

	SweepRenderer* getRenderer();
	void returnRenderer(SweepRenderer*);
};

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