﻿using System;
using System.Collections.Generic;
using System.Text;

using CGALDotNet;
using CGALDotNet.Geometry;
using CGALDotNet.Triangulations;
using CGALDotNet.Polygons;

namespace CGALDotNetConsole.Examples
{
    class DelaunayTriangulation2Examples
    {
        public static void CreateDelaunayTriangulation()
        {
            Console.WriteLine("Create delaunauy triangulation example\n");

            var points = new Point2d[]
            {
                new Point2d(0, 0),
                new Point2d(5, 0),
                new Point2d(5, 5),
                new Point2d(2, 2),
                new Point2d(0, 5)
            };

            var tri = new DelaunayTriangulation2<EEK>(points);
            tri.Print();


            tri.InsertPoint(new Point2d(1, 1));

            /*
            Console.WriteLine("Is valid " + tri.IsValid());

            var segments = tri.GetVoronoiSegments();
            var rays = tri.GetVoronoiRays();

            foreach (var seg in segments)
                Console.WriteLine(seg);

            foreach (var ray in rays)
               Console.WriteLine(ray);
            */
        }
    }
}