﻿using System;
using System.Collections.Generic;
using BenchmarkDotNet.Attributes;
using BenchmarkDotNet.Running;

using CGALDotNet;
using CGALDotNet.Geometry;
using CGALDotNet.Polygons;
using CGALDotNet.Triangulations;
using CGALDotNet.Arrangements;
using CGALDotNet.Polyhedra;
using CGALDotNet.Meshing;
using CGALDotNet.Hulls;
using CGALDotNet.Processing;

namespace CGALDotNetConsole
{
    public class Program
    {
        

        public static void Main(string[] args)
        {

            var polygon = PolygonFactory<EEK>.CreateCircle(5, 5);

            var mesh = new Polyhedron3<EEK>();
            mesh.CreatePolygonMesh(polygon, true);
            mesh.Triangulate();

            var prim = mesh.GetPrimativeCount();

            mesh.Print();

            Console.WriteLine(prim);
 
        }



    }
}
