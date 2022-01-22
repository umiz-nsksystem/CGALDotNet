﻿using System;
using System.Collections.Generic;
using System.Text;

using CGALDotNet.Geometry;

namespace CGALDotNet.Triangulations
{
    internal abstract class DelaunayTriangulationKernel2 : BaseTriangulationKernel2
    {
        internal abstract bool MoveVertex(IntPtr ptr, int index, Point2d point, bool ifNoCollision, out TriVertex2 vertex);

        internal abstract int VoronoiSegmentCount(IntPtr ptr);

        internal abstract int VoronoiRayCount(IntPtr ptr);

        internal abstract void GetVoronoiSegments(IntPtr ptr, Segment2d[] segments, int count);

        internal abstract void GetVoronoiRays(IntPtr ptr, Ray2d[] rays, int count);

        internal abstract void VoronoiCount(IntPtr ptr, out int numSegments, out int numRays);

    }
}
