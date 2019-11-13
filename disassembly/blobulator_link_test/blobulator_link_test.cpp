#include "blobulator/implicit/sweeprenderer.h"

#pragma optimize("", off)

static class main
{
public:
	main()
	{
		SweepRenderer* sweep = new SweepRenderer();

		sweep->addParticle(nullptr, false);
		sweep->changeCubeWidth(0);
		sweep->changeRadii(0, 0);
		sweep->allocSliceCorners(nullptr);
		sweep->allocSliceTodoList(nullptr);
		sweep->deallocSliceCorners(nullptr);
		sweep->deallocSliceTodoList(nullptr);
		sweep->beginFrame(false, nullptr);
		sweep->endFrame();
		sweep->beginTile(nullptr);
		sweep->endTitle();
		sweep->getInnerDimensions();
		sweep->isParticleWithinBounds(nullptr);
		sweep->recalculateBB();
		sweep->recalculateDimensions();
		sweep->render_slice(0, nullptr, nullptr, nullptr);
		sweep->render_slices();
		sweep->seed_surface(nullptr);
		SweepRenderer::getMarginNCubes();
		SweepRenderer::getMarginWidth();
		SweepRenderer::setCalcCornerFunc(nullptr);
		SweepRenderer::setCalcSign2Func(nullptr);
		SweepRenderer::setCalcSignFunc(nullptr);
		SweepRenderer::setCalcVertexFunc(nullptr);
		SweepRenderer::setCubeWidth(0);
		SweepRenderer::getCubeWidth();
		SweepRenderer::setCutoffR(0);
		SweepRenderer::getCutoffR();
		SweepRenderer::setRenderR(0);
		SweepRenderer::getRenderR();
		SweepRenderer::setOffset(nullptr);
	}
} s_main;