#define LINK_TEST

#include "blobulator/implicit/sweeprenderer.h"
#include "blobulator/implicit/imptiler.h"
#include "blobulator/physics/physparticlecache_inl.h"
#include "blobulator/physics/phystiler.h"
#include "blobulator/point3d.h"
#include <windows.h>

#pragma warning(push, 0)
#pragma optimize("", off)

//#define IMPTILER_TEST
//#define SWEEPRENDERER_TEST
//#define POINT3D_TEST
//#define PHYSPARTICLECACHE_TEST
#define PHYSTILER_TEST

#if defined(SWEEPRENDERER_TEST)
int WINAPI WinMain(
	HINSTANCE hInstance,     /* [input] handle to current instance */
	HINSTANCE hPrevInstance, /* [input] handle to previous instance */
	LPSTR lpCmdLine,         /* [input] pointer to command line */
	int nCmdShow             /* [input] show state of window */
)
{
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

	ImpParticle particle;
	sweep->addParticle(&particle, false);

	sweep->isParticleWithinBounds(&particle);

	sweep->setOffset(Point3D());

	sweep->beginFrame(false, nullptr);
	sweep->endFrame();

	sweep->beginTile(nullptr);
	sweep->endTile();
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
#elif defined(PHYSPARTICLECACHE_TEST)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PhysParticleCache* cache = new PhysParticleCache(0, 0);
	cache->beginFrame();
	cache->endFrame();
	cache->beginTile(0);
	cache->endTile();
	cache->calcNeighbors(&PhysParticle(), PhysParticle***, &int(0));
	cache->getInnerDimensions();
	cache->getMarginWidth();
	cache->getOuterDimensions();
	cache->insertParticle(&PhysParticle());
	cache->setCacheParams(0, 0);
	cache->setOffset(Point3D());
}

#elif defined(PHYSTILER_TEST)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	PhysParticleCache cache(0, 0);
	PhysTiler* phys = new PhysTiler(&cache);

	phys->acquireIterator();
	phys->beginFrame(Point3D());
	phys->beginIteration();
	phys->endFrame();
	phys->endIteration();
//	phys->getNextParticleAndNeighbors(PhysParticle ***, &int(0));
	phys->insertParticle(&PhysParticle());
	phys->releaseIterator(phys->acquireIterator());
}
#endif

#pragma warning(pop)