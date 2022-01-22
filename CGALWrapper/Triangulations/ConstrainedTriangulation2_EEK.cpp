#pragma once

#include "ConstrainedTriangulation2_EEK.h"
#include "ConstrainedTriangulation2.h"
#include "TriVertex2.h"
#include "TriFace2.h"
#include "TriEDge2.h"

typedef typename EEK::Point_2 Point_2;
typedef CGAL::No_constraint_intersection_tag Tag1;
typedef CGAL::No_constraint_intersection_requiring_constructions_tag Tag2;
typedef CGAL::Exact_predicates_tag Tag3;
typedef CGAL::Exact_intersections_tag Tag4;

typedef CGAL::Triangulation_vertex_base_with_info_2<int, EEK> Vb;
typedef CGAL::Constrained_triangulation_face_base_2<EEK> CFb;
typedef CGAL::Triangulation_face_base_with_info_2<int, EEK, CFb> Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb> Tds;
typedef CGAL::Constrained_triangulation_2<EEK, Tds, Tag4> Triangulation_2;

typedef typename Triangulation_2::Face_handle Face;
typedef typename Triangulation_2::Vertex_handle Vertex;
typedef typename Triangulation_2::Edge Edge;

typedef ConstrainedTriangulation2<EEK, Triangulation_2, Vertex, Face> Tri2;

void* ConstrainedTriangulation2_EEK_Create()
{
	return Tri2::NewTriangulation2();
}

void ConstrainedTriangulation2_EEK_Release(void* ptr)
{
	Tri2::DeleteTriangulation2(ptr);
}

void ConstrainedTriangulation2_EEK_Clear(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->Clear();
}

void* ConstrainedTriangulation2_EEK_Copy(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->Copy();
}

void ConstrainedTriangulation_EEK_SetIndices(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->SetIndices();
}

int ConstrainedTriangulation2_EEK_BuildStamp(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->BuildStamp();
}

BOOL ConstrainedTriangulation2_EEK_IsValid(void* ptr, int level)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->IsValid(level);
}

int ConstrainedTriangulation2_EEK_VertexCount(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->VertexCount();
}

int ConstrainedTriangulation2_EEK_FaceCount(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->FaceCount();
}

void ConstrainedTriangulation2_EEK_InsertPoint(void* ptr, Point2d point)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->InsertPoint(point);
}

void ConstrainedTriangulation2_EEK_InsertPoints(void* ptr, Point2d* points, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->InsertPoints(points, count);
}

void ConstrainedTriangulation2_EEK_InsertPolygon(void* triPtr, void* polyPtr)
{
	auto tri = Tri2::CastToTriangulation2(triPtr);
	tri->InsertPolygon(polyPtr);
}

void ConstrainedTriangulation2_EEK_InsertPolygonWithHoles(void* triPtr, void* pwhPtr)
{
	auto tri = Tri2::CastToTriangulation2(triPtr);
	tri->InsertPolygonWithHoles(pwhPtr);
}

void ConstrainedTriangulation2_EEK_GetPoints(void* ptr, Point2d* points, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetPoints(points, count);
}

void ConstrainedTriangulation2_EEK_GetIndices(void* ptr, int* indices, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetIndices(indices, count);
}

BOOL ConstrainedTriangulation2_EEK_GetVertex(void* ptr, int index, TriVertex2& vertex)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->GetVertex(index, vertex);
}

void ConstrainedTriangulation2_EEK_GetVertices(void* ptr, TriVertex2* vertices, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetVertices(vertices, count);
}

bool ConstrainedTriangulation2_EEK_GetFace(void* ptr, int index, TriFace2& face)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->GetFace(index, face);
}

void ConstrainedTriangulation2_EEK_GetFaces(void* ptr, TriFace2* faces, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetFaces(faces, count);
}

BOOL ConstrainedTriangulation2_EEK_GetSegment(void* ptr, int faceIndex, int neighbourIndex, Segment2d& segment)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->GetSegment(faceIndex, neighbourIndex, segment);
}

BOOL ConstrainedTriangulation2_EEK_GetTriangle(void* ptr, int faceIndex, Triangle2d& triangle)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->GetTriangle(faceIndex, triangle);
}

void ConstrainedTriangulation2_EEK_GetTriangles(void* ptr, Triangle2d* triangles, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetTriangles(triangles, count);
}

BOOL ConstrainedTriangulation2_EEK_GetCircumcenter(void* ptr, int faceIndex, Point2d& circumcenter)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->GetCircumcenter(faceIndex, circumcenter);
}

void ConstrainedTriangulation2_EEK_GetCircumcenters(void* ptr, Point2d* circumcenters, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetCircumcenters(circumcenters, count);
}

int ConstrainedTriangulation2_EEK_NeighbourIndex(void* ptr, int faceIndex, int index)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->NeighbourIndex(faceIndex, index);
}

BOOL ConstrainedTriangulation2_EEK_LocateFace(void* ptr, Point2d point, TriFace2& face)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->LocateFace(point, face);
}

BOOL ConstrainedTriangulation2_EEK_MoveVertex(void* ptr, int index, Point2d point, TriVertex2& vertex)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->MoveVertex(index, point, vertex);
}

BOOL ConstrainedTriangulation2_EEK_RemoveVertex(void* ptr, int index)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->RemoveVertex(index);
}

BOOL ConstrainedTriangulation2_EEK_FlipEdge(void* ptr, int faceIndex, int neighbour)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->FlipEdge(faceIndex, neighbour);
}

void ConstrainedTriangulation2_EEK_Transform(void* ptr, Point2d translation, double rotation, double scale)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->Transform(translation, rotation, scale);
}

//Constrained only

int ConstrainedTriangulation2_EEK_ConstrainedEdgesCount(void* ptr)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->ConstrainedEdgesCount();
}

BOOL ConstrainedTriangulation2_EEK_HasIncidentConstraints(void* ptr, int index)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->HasIncidentConstraints(index);
}

int ConstrainedTriangulation2_EEK_IncidentConstraintCount(void* ptr, int index)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->IncidentConstraintCount(index);
}

void ConstrainedTriangulation2_EEK_InsertSegmentConstraintFromPoints(void* ptr, Point2d a, Point2d b)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->InsertSegmentConstraint(a, b);
}

void ConstrainedTriangulation2_EEK_InsertSegmentConstraintFromVertices(void* ptr, int vertIndex1, int vertIndex2)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->InsertSegmentConstraint(vertIndex1, vertIndex2);
}

void ConstrainedTriangulation2_EEK_InsertSegmentConstraints(void* ptr, Segment2d* segments, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->InsertSegmentConstraints(segments, count);
}

void ConstrainedTriangulation2_EEK_InsertPolygonConstraint(void* triPtr, void* polyPtr)
{
	auto tri = Tri2::CastToTriangulation2(triPtr);
	tri->InsertPolygonConstraint(polyPtr);
}

void ConstrainedTriangulation2_EEK_InsertPolygonWithHolesConstraint(void* triPtr, void* pwhPtr)
{
	auto tri = Tri2::CastToTriangulation2(triPtr);
	tri->InsertPolygonWithHolesConstraint(pwhPtr);
}

void ConstrainedTriangulation2_EEK_GetEdgeConstraints(void* ptr, TriEdge2* constraints, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetConstraints(constraints, count);
}

void ConstrainedTriangulation2_EEK_GetSegmentConstraints(void* ptr, Segment2d* constraints, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetConstraints(constraints, count);
}

void ConstrainedTriangulation2_EEK_GetIncidentConstraints(void* ptr, int vertexIndex, TriEdge2* constraints, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->GetIncidentConstraints(vertexIndex, constraints, count);
}

void ConstrainedTriangulation2_EEK_RemoveConstraint(void* ptr, int faceIndex, int neighbourIndex)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->RemoveConstraint(faceIndex, neighbourIndex);
}

void ConstrainedTriangulation2_EEK_RemoveIncidentConstraints(void* ptr, int vertexIndex)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	tri->RemoveIncidentConstraints(vertexIndex);
}

int ConstrainedTriangulation2_EEK_MarkDomains(void* ptr, int* indices, int count)
{
	auto tri = Tri2::CastToTriangulation2(ptr);
	return tri->MarkDomains(indices, count);
}


