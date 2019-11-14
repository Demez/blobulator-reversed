#define LINK_TEST

#include "blobulator/implicit/sweeprenderer.h"
#include "blobulator/point3d.h"
#include <windows.h>

#pragma warning(push, 0)
#pragma optimize("", off)

#define SWEEPRENDERER_TEST
//#define POINT3D_TEST

#if defined(SWEEPRENDERER_TEST)
int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
	SweepRenderer* sweep = new SweepRenderer();

	sweep->addParticle(&ImpParticle(), false);
	sweep->changeCubeWidth(0);
	sweep->allocSliceCorners(nullptr);
	sweep->allocSliceTodoList(nullptr);
	sweep->deallocSliceCorners(nullptr);
	sweep->deallocSliceTodoList(nullptr);
	sweep->beginFrame(false, nullptr);
	sweep->endFrame();
	sweep->beginTile(nullptr);
	sweep->endTile();
	SweepRenderer::getInnerDimensions();
	sweep->isParticleWithinBounds(nullptr);
	sweep->recalculateBB();
	sweep->recalculateDimensions();
	sweep->render_slice(0, nullptr, nullptr, nullptr);
	sweep->render_slices();
	sweep->seed_surface(Point3D());
	sweep->setOffset(Point3D());
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
#endif

#pragma warning(pop)