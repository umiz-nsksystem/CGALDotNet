#pragma once

#include "../CGALWrapper.h"
#include "../Geometry/Index.h"
#include "../Polyhedra/Polyhedron3.h"
#include "../Polyhedra/SurfaceMesh3.h"
#include "../Polylines/Polyline3.h"

#include <CGAL/Polygon_mesh_processing/detect_features.h>

template<class K>
class PolygonMeshProcessingFeatures
{

public:

	typedef typename K::Point_3 Point_3;

	typedef CGAL::Polyhedron_3<K, CGAL::Polyhedron_items_with_id_3> Polyhedron;
	typedef typename boost::graph_traits<Polyhedron>::edge_descriptor PEdge_Des;
	typedef typename boost::graph_traits<Polyhedron>::face_descriptor PFace_Des;

	typedef typename CGAL::Surface_mesh<Point_3> SurfaceMesh;
	typedef typename SurfaceMesh::Face_index SFace;
	typedef typename boost::graph_traits<SurfaceMesh>::edge_descriptor SEdge_Des;
	typedef typename boost::graph_traits<SurfaceMesh>::face_descriptor SFace_Des;

	std::vector<PEdge_Des> polyhedron_edge_buffer;

	std::vector<SEdge_Des> surface_edge_buffer;

	std::unordered_map<int, std::vector<int>> polyhedron_patch_buffer;

	std::unordered_map<int, std::vector<int>> surface_patch_buffer;

	inline static PolygonMeshProcessingFeatures* NewPolygonMeshProcessingFeatures()
	{
		return new PolygonMeshProcessingFeatures();
	}

	inline static void DeletePolygonMeshProcessingFeatures(void* ptr)
	{
		auto obj = static_cast<PolygonMeshProcessingFeatures*>(ptr);

		if (obj != nullptr)
		{
			delete obj;
			obj = nullptr;
		}
	}

	inline static PolygonMeshProcessingFeatures* CastToPolygonMeshProcessingFeatures(void* ptr)
	{
		return static_cast<PolygonMeshProcessingFeatures*>(ptr);
	}

	void AddSurfaceFaceToPatchBuffer(SFace face, int patch)
	{
		auto list = surface_patch_buffer.find(patch);
		if (list != surface_patch_buffer.end())
		{
			list->second.push_back(face);
		}
		else
		{
			std::pair<int, std::vector<int>> pair;
			pair.first = patch;
			pair.second.push_back(face);
			surface_patch_buffer.insert(pair);
		}
	}

	//Polyhedron

	static int DetectSharpEdges_PH(void* feaPtr, void* meshPtr, double feature_angle)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		auto mesh = Polyhedron3<K>::CastToPolyhedron(meshPtr);

		std::unordered_map<PEdge_Des, bool> map;
		CGAL::Polygon_mesh_processing::detect_sharp_edges(mesh->model, feature_angle, boost::make_assoc_property_map(map));

		fea->polyhedron_edge_buffer.clear();
		for(auto& pair : map)
		{
			if (pair.second)
				fea->polyhedron_edge_buffer.push_back(pair.first);
		}

		return (int)fea->polyhedron_edge_buffer.size();
	}

	static void GetSharpEdges_PH(void* feaPtr, void* meshPtr, int* indices, int count)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		auto mesh = Polyhedron3<K>::CastToPolyhedron(meshPtr);

		int index = 0;
		for (auto edge : fea->polyhedron_edge_buffer)
		{
			auto hedge = edge.halfedge();
			indices[index++] = mesh->FindEdgeIndex(hedge);

			if (index >= count)
				break;
		}
	
		fea->polyhedron_edge_buffer.clear();
	}

	static Index2 SharpEdgesSegmentation_PH(void* feaPtr, void* meshPtr, double feature_angle)
	{
		return { 0, 0 };
	}

	static void ClearPatchBuffer_PH(void* feaPtr)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		fea->polyhedron_patch_buffer.clear();
	}

	static int GetPatchBufferFaceCount_PH(void* feaPtr, int patchIndex)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);

		auto list = fea->polyhedron_patch_buffer.find(patchIndex);
		if (list != fea->polyhedron_patch_buffer.end())
		{
			return (int)list->second.size();
		}
		else
			return 0;
	}

	static int GetPatchBufferFaceIndex_PH(void* feaPtr, int patchIndex, int faceIndex)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);

		auto list = fea->polyhedron_patch_buffer.find(patchIndex);
		if (list != fea->polyhedron_patch_buffer.end())
		{
			if (faceIndex < 0 || faceIndex >= (int)list->second.size())
				return NULL_INDEX;

			return list->second[faceIndex];
		}
		else
			return 0;
	}

	//SurfaceMesh

	static int DetectSharpEdges_SM(void* feaPtr, void* meshPtr, double feature_angle)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		auto mesh = SurfaceMesh3<K>::CastToSurfaceMesh(meshPtr);

		std::unordered_map<SEdge_Des, bool> map;
		CGAL::Polygon_mesh_processing::detect_sharp_edges(mesh->model, feature_angle, boost::make_assoc_property_map(map));

		fea->surface_edge_buffer.clear();
		for (auto& pair : map)
		{
			if (pair.second)
				fea->surface_edge_buffer.push_back(pair.first);
		}

		return (int)fea->surface_edge_buffer.size();
	}

	static void GetSharpEdges_SM(void* feaPtr, void* meshPtr, int* indices, int count)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		auto mesh = SurfaceMesh3<K>::CastToSurfaceMesh(meshPtr);

		int index = 0;
		for (auto edge : fea->surface_edge_buffer)
		{
			auto hedge = edge.halfedge();
			indices[index++] = mesh->FindEdgeIndex(hedge);

			if (index >= count)
				break;
		}

		fea->surface_edge_buffer.clear();
	}

	static Index2 SharpEdgesSegmentation_SM(void* feaPtr, void* meshPtr, double feature_angle)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		auto mesh = SurfaceMesh3<K>::CastToSurfaceMesh(meshPtr);

		typedef boost::property_map<SurfaceMesh, CGAL::edge_is_feature_t>::type EIFMap;
		typedef boost::property_map<SurfaceMesh, CGAL::face_patch_id_t<int> >::type PIMap;
		typedef boost::property_map<SurfaceMesh, CGAL::vertex_incident_patches_t<int> >::type VIMap;
		namespace PMP = CGAL::Polygon_mesh_processing;

		EIFMap eif = get(CGAL::edge_is_feature, mesh->model);
		PIMap pid = get(CGAL::face_patch_id_t<int>(), mesh->model);
		VIMap vip = get(CGAL::vertex_incident_patches_t<int>(), mesh->model);

		auto param = PMP::parameters::vertex_incident_patches_map(vip);
		auto number_of_patches = PMP::sharp_edges_segmentation(mesh->model, feature_angle, eif, pid, param);

		fea->surface_edge_buffer.clear();
		fea->surface_patch_buffer.clear();

		int index = 0;
		for (auto edge : edges(mesh->model))
		{
			if (get(eif, edge))
			{
				fea->surface_edge_buffer.push_back(edge);
			}
		}

		for (auto face : faces(mesh->model))
		{
			if (get(pid, face))
			{
				int patch = pid[face];
				fea->AddSurfaceFaceToPatchBuffer(face, patch);
			}
		}

		return { (int)fea->surface_edge_buffer.size(), (int)number_of_patches };
	}

	static void ClearPatchBuffer_SM(void* feaPtr)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);
		fea->surface_patch_buffer.clear();
	}

	static int GetPatchBufferFaceCount_SM(void* feaPtr, int patchIndex)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);

		auto list = fea->surface_patch_buffer.find(patchIndex);
		if (list != fea->surface_patch_buffer.end())
		{
			return (int)list->second.size();
		}
		else
			return 0;
	}

	static int GetPatchBufferFaceIndex_SM(void* feaPtr, int patchIndex, int faceIndex)
	{
		auto fea = CastToPolygonMeshProcessingFeatures(feaPtr);

		auto list = fea->surface_patch_buffer.find(patchIndex);
		if (list != fea->surface_patch_buffer.end())
		{
			if (faceIndex < 0 || faceIndex >= (int)list->second.size())
				return NULL_INDEX;

			return list->second[faceIndex];
		}
		else
			return 0;
	}

};
