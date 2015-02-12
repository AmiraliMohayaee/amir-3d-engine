#pragma once

#include "Octree.h"

namespace Engine
{
	Octree* MakeOctree(const Tris& tris, const Box3D& box, int recursionDepth);
}