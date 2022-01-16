﻿using System;
using System.Collections.Generic;
using System.Text;

namespace CGALDotNet.Processing
{
    internal abstract class PolygonMeshProcessingNormalsKernel : FuncKernel
    {
        internal abstract IntPtr Create();

        internal abstract void Release(IntPtr ptr);
    }
}