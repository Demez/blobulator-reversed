#define LINK_TEST

#include "blobulator/implicit/sweeprenderer.h"
#include "blobulator/point3d.h"
#include <windows.h>

#pragma warning(push, 0)
#pragma optimize("", off)

#define IMPTILER_TEST
//#define SWEEPRENDERER_TEST
//#define POINT3D_TEST

#if defined(SWEEPRENDERER_TEST)
int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
	SweepRenderer::changeRadii(0, 0);
	SweepRenderer::getMarginNCubes();
	SweepRenderer::getMarginWidth();
	SweepRenderer::setCalcCornerFunc(0, nullptr);
	SweepRenderer::setCalcSign2Func(nullptr);
	SweepRenderer::setCalcSignFunc(nullptr);
	SweepRenderer::setCalcVertexFunc(nullptr);
	SweepRenderer::setCubeWidth(0);
	SweepRenderer::getCubeWidth();
	SweepRenderer::setCutoffR(0);
	SweepRenderer::getCutoffR();
	SweepRenderer::setRenderR(0);
	SweepRenderer::getRenderR();
	SweepRenderer::getInnerDimensions();

	SweepRenderer* sweep = new SweepRenderer();

	sweep->recalculateBB();
	sweep->recalculateDimensions();

	ImpParticle particle;
	sweep->addParticle(&particle, false);
	sweep->changeCubeWidth(0);

	sweep->isParticleWithinBounds(&particle);

	sweep->seed_surface(Point3D());

	Slice_t slice;
	Slice_t slice2;
	sweep->allocSliceCorners(&slice);
	sweep->allocSliceTodoList(&slice2);
	sweep->deallocSliceCorners(&slice);

	sweep->setOffset(Point3D());

	sweep->deallocSliceTodoList(&slice2);

	sweep->beginFrame(false, nullptr);
	sweep->endFrame();


	sweep->beginTile(nullptr);
	sweep->endTile();
	sweep->render_slice(0, nullptr, nullptr, nullptr);
	sweep->render_slices();
}
#elif defined(POINT3D_TEST)
int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
	Point3D p3d;
	p3d.crossProduct(p3d);
	p3d.dot(Point3D());
	p3d.length();
	p3d.mult(0.0f);
	p3d.normalize();
	p3d * 0;
	p3d + Point3D();
	p3d - Point3D();
	p3d / 0.0f;
	{ float f = p3d[0]; }
	p3d.set(0, 0, 0);
}
#elif defined IMPTILER_TEST
int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
	SweepRenderer* sweep = new SweepRenderer();
	ImpTiler* tiler = new ImpTiler(sweep);

	tiler->addParticleToTile(&ImpParticle(), 0, 0, 0);
	tiler->beginFrame(Point3D(), nullptr, false);
	tiler->calcTileCorner(0, 0, 0);
	tiler->calcTileOffset(0, 0, 0);
	tiler->createTile(0, 0, 0);
	tiler->drawSurface();
	tiler->drawSurfaceSorted(Point3D());
	tiler->drawTile(&ImpTile(0, 0, 0));
	tiler->endFrame();
	tiler->findTile(0, 0, 0);
	tiler->getNoTiles();
	tiler->insertParticle(&ImpParticle());
}
#endif

#pragma warning(pop)