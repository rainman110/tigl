/* 
* Copyright (C) 2007-2011 German Aerospace Center (DLR/SC)
*
* Created: 2010-08-13 Markus Litz <Markus.Litz@dlr.de>
* Changed: $Id$ 
*
* Version: $Revision$
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/**
* @file
* @brief  Export routines for CPACS configurations.
*/

// standard libraries
#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <string>

#include "CTiglExportVtk.h"
#include "CCPACSConfiguration.h"
#include "CTiglAbstractPhysicalComponent.h"
#include "CTiglAbstractSegment.h"
#include "CCPACSWing.h"
#include "CCPACSConfiguration.h"
#include "CCPACSConfigurationManager.h"
#include "CCPACSWingSegment.h"

// open cascade basics
#include "gp_Pnt.hxx"
#include "gp_Lin.hxx"
#include "gp_Vec.hxx"
#include "Precision.hxx"
#include "Geom_Line.hxx"
#include "Geom_Curve.hxx"
#include "Geom_Surface.hxx"
#include "Geom_BSplineSurface.hxx"
#include "GProp_PGProps.hxx"
#include "TopoDS_Shape.hxx"
#include "TopoDS_Edge.hxx"
#include "TopoDS_Wire.hxx"
#include "TColgp_Array1OfPnt.hxx"
#include "TColgp_Array1OfPnt2d.hxx"

// creators
#include "ShapeFix_Shape.hxx"
#include "BRep_Builder.hxx"
#include "BRepBuilderAPI_MakeFace.hxx"
#include "BRepBuilderAPI_MakeWire.hxx"
#include "BRepBuilderAPI_MakeShape.hxx"
#include "BRepBuilderAPI_MakeVertex.hxx"

// algorithms
#include "BRepMesh.hxx"
#include "BRepTools.hxx"
#include "BRep_Tool.hxx"
#include "BRepLib_FindSurface.hxx"
#include "BRepExtrema_DistShapeShape.hxx"
#include "Poly_Triangulation.hxx"
#include "TopOpeBRepDS_SurfaceExplorer.hxx"
#include "TopExp_Explorer.hxx"
#include "GeomAPI_IntCS.hxx"
#include "GeomAPI_IntSS.hxx"
#include "ShapeAnalysis_Surface.hxx"
#include "TopOpeBRepDS_DataStructure.hxx"
#include "BRepBuilderAPI_MakeEdge.hxx"
#include "GeomAPI_ProjectPointOnSurf.hxx"
#include "BrepGProp_Face.hxx"

#include "CTiglPolyData.h"
#include "CTiglTriangularizer.h"

namespace tigl {

    // Constructor
    CTiglExportVtk::CTiglExportVtk(CCPACSConfiguration& config)
        :myConfig(config)
    {
    }

    // Destructor
    CTiglExportVtk::~CTiglExportVtk(void)
    {
    }
	
    
    // Exports a by index selected wing, boolean fused and meshed, as STL file
    void CTiglExportVtk::ExportMeshedWingVTKByIndex(const int wingIndex, const std::string& filename, const double deflection)
    {
        //exportMode = TIGL_VTK_COMPLEX;
        CTiglAbstractPhysicalComponent & component = myConfig.GetWing(wingIndex);
        TopoDS_Shape& loft = component.GetLoft();
        
       LOG(ERROR) << "tiglExportMeshedWingByIndexVTK not yet implemented!!" << std::endl;

    }

    // Exports a by UID selected wing, boolean fused and meshed, as STL file
    void CTiglExportVtk::ExportMeshedWingVTKByUID(const std::string wingUID, const std::string& filename, const double deflection)
    {
        CTiglAbstractPhysicalComponent & component = myConfig.GetWing(wingUID);
        TopoDS_Shape loft = component.GetLoft();

       LOG(ERROR) << "tiglExportMeshedWingByUIDVTK not yet implemented!!" << std::endl;
    }



    // Exports a by index selected fuselage, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedFuselageVTKByIndex(const int fuselageIndex, const std::string& filename, const double deflection)
    {
        CTiglAbstractPhysicalComponent & component = myConfig.GetFuselage(fuselageIndex);
        TopoDS_Shape loft = component.GetLoft();

        LOG(ERROR) << "tiglExportMeshedFuselageByIndexVTK not yet implemented!!" << std::endl;
    }

    // Exports a by UID selected fuselage, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedFuselageVTKByUID(const std::string fuselageUID, const std::string& filename, const double deflection)
    {
        CTiglAbstractPhysicalComponent & component = myConfig.GetFuselage(fuselageUID);
        TopoDS_Shape loft = component.GetLoft();
        
        LOG(ERROR) << "tiglExportMeshedFuselageByIndexUID not yet implemented!!" << std::endl;
    }
    

    // Exports a whole geometry, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedGeometryVTK(const std::string& filename, const double deflection)
    {
        LOG(ERROR) << "tiglExportMeshedGeometryVTK not yet implemented!!" << std::endl;
    }

    /************* Simple ones *************************/
    // Exports a by UID selected wing, boolean fused and meshed, as STL file
    void CTiglExportVtk::ExportMeshedWingVTKSimpleByUID(const std::string wingUID, const std::string& filename, const double deflection)
    {
        CTiglAbstractPhysicalComponent & component = myConfig.GetWing(wingUID);
        TopoDS_Shape& loft = component.GetLoft();
        BRepMesh::Mesh(loft, deflection);
        
        CTiglTriangularizer loftTrian(loft);
        loftTrian.writeVTK(filename.c_str());
    }
    
    /************* Simple ones *************************/
    // Exports a by UID selected wing, boolean fused and meshed, as STL file
    void CTiglExportVtk::ExportMeshedWingVTKSimpleByIndex(const int wingIndex, const std::string& filename, const double deflection)
    {
        const std::string& wingUID = myConfig.GetWing(wingIndex).GetUID();
        ExportMeshedWingVTKSimpleByUID(wingUID, filename, deflection);
    }

    // Exports a by UID selected fuselage, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedFuselageVTKSimpleByUID(const std::string fuselageUID, const std::string& filename, const double deflection)
    {
        CTiglAbstractPhysicalComponent & component = myConfig.GetFuselage(fuselageUID);
        TopoDS_Shape& loft = component.GetLoft();
        BRepMesh::Mesh(loft, deflection);
        
        CTiglTriangularizer loftTrian(loft);
        loftTrian.writeVTK(filename.c_str());
    }
    
    // Exports a by UID selected fuselage, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedFuselageVTKSimpleByIndex(const int fuselageIndex, const std::string& filename, const double deflection){
        const std::string& fuselageUID = myConfig.GetFuselage(fuselageIndex).GetUID();
        ExportMeshedFuselageVTKSimpleByUID(fuselageUID, filename, deflection);
    }


    // Exports a whole geometry, boolean fused and meshed, as VTK file
    void CTiglExportVtk::ExportMeshedGeometryVTKSimple(const std::string& filename, const double deflection)
    {

        LOG(ERROR) << "tiglExportMeshedGeometryVTKSimple not yet implemented!!" << std::endl;
    }


//    // Helper function to detect unique points in all triangles
//    unsigned int VtkWriter::FindUniquePoints(const TopoDS_Shape & shape, CTiglAbstractPhysicalComponent & component, const double deflection) {
//        TopExp_Explorer shellExplorer;
//        TopExp_Explorer faceExplorer;
//        TopOpeBRepDS_SurfaceExplorer surfaceExplorer;
//        BRep_Builder builder;
//        GProp_PGProps props;
//        const int segmentCount = component.GetSegmentCount();

//        // the surfaces of our shape
//        const BRepLib_FindSurface findSurface(shape, /* tolerance */1);
//        const Handle(Geom_Surface) & surface = findSurface.Surface();

//        // 1. mesh
//        BRepTools::Clean(shape);
//        BRepMesh::Mesh(shape, deflection);

//        for (shellExplorer.Init(shape, TopAbs_SHELL); shellExplorer.More(); shellExplorer.Next()) {
//            const TopoDS_Shell shell = TopoDS::Shell(shellExplorer.Current());

//            for (faceExplorer.Init(shell, TopAbs_FACE); faceExplorer.More(); faceExplorer.Next()) {
//                TopoDS_Face face = TopoDS::Face(faceExplorer.Current());
//                TopLoc_Location location;
//                const Handle(Poly_Triangulation) triangulation = BRep_Tool::Triangulation(face, location);
//                if (triangulation.IsNull())
//                    continue;

//                gp_Trsf nodeTransformation = location;
//                const TColgp_Array1OfPnt& nodes = triangulation->Nodes(); // get (face-local) list of nodes

//                int index1, index2, index3;
//                const Poly_Array1OfTriangle& triangles = triangulation->Triangles();
//                for (int j = triangles.Lower(); j <= triangles.Upper(); j++) // iterate over triangles in the array
//                {
//                    const Poly_Triangle& triangle = triangles(j);
//                    triangle.Get(index1, index2, index3); // get indices into index1..3
//                    const gp_Pnt tpoint1 = nodes(index1).Transformed(nodeTransformation);
//                    const gp_Pnt tpoint2 = nodes(index2).Transformed(nodeTransformation);
//                    const gp_Pnt tpoint3 = nodes(index3).Transformed(nodeTransformation);

//                    // determine unique point indices
//                    FindOrCreatePointIndex(triangleList1, tpoint1);
//                    FindOrCreatePointIndex(triangleList2, tpoint2);
//                    FindOrCreatePointIndex(triangleList3, tpoint3);

//                    // determine surface point of triangle center, normal vector and surface point of the normal on the wing segment, then eta and xi
//                    TColgp_Array1OfPnt triangle1Array(0, 2);
//                    triangle1Array(0) = tpoint1;
//                    triangle1Array(1) = tpoint2;
//                    triangle1Array(2) = tpoint3;

//                    // 2. a. center of gravity of triangle, b. normal vector from inside -> outside
//                    const gp_Pnt baryCenter = props.Barycentre(triangle1Array); // get center of triangle
//                    const gp_Vec normal = FindNormal(tpoint1, tpoint2, tpoint3); // find normal vector

//                    // determine intersection of normal vector with fused geometry
//                    const gp_Lin line(baryCenter, normal);
//                    Geom_Line tempLine(line);
//                    const Handle(Geom_Curve) & curve((const Handle(Geom_Curve) &) tempLine);

//                    // 3. intersection with surface to find a "real" surface point.
//                    GeomAPI_ProjectPointOnSurf project1(baryCenter, surface);
//                    if (project1.IsDone()) {
//                        int i = project1.NbPoints(); // else try next surface

//                        // find nearest intersection point (point on the correct side of the surface)
//                        Standard_Real minimumDist = 1e8; // use an arbitrary high number...
//                        Standard_Boolean found = Standard_False;
//                        int foundShapeIndex = 0;

//                        const BRepBuilderAPI_MakeVertex foundVertex(project1.NearestPoint());
//                        for (int s = 1; s <= segmentCount; s++) // find segment belonging to the intersection point on the explored surface (may always be just one, but we don't know for sure)
//                        {
//                            CTiglAbstractSegment & segment = component.GetSegment(s);
//                            TopoDS_Shape segmentLoft = segment.GetLoft(); // get 3d shape of the segment

//                            // 4. find minimum distance to determine the linked segment of the surface intersection
//                            const BRepExtrema_DistShapeShape dist(segmentLoft, foundVertex);
//                            if (dist.IsDone() && (dist.NbSolution() > 0)) {
//                                for (int p = 0; p < dist.NbSolution(); p++) {
//                                    const Standard_Real currentDist = dist.Value();
//                                    if (currentDist < minimumDist) {
//                                        minimumDist = currentDist;
//                                        foundShapeIndex = s;
//                                        found = Standard_True;
//                                    }
//                                }
//                            }
//                        }
//                        if (found) // a minimum distance was found: we know the segment the intersecting point comes from! What we don't know is if we're on uppe or lower side, but currently we don't need this information for the projection
//                        {
//							// Gather metadata needed for VTK metadata-node
//                            bool isUpperSide = true;
//                            double eta = 0.0;
//                            double xsi = 0.0;
//							std::string uid = component.GetSegment(foundShapeIndex).GetUID();

//					        // Important: works only for wings because on fuselage there is not lower side (?)!
//							if(component.GetComponentType() == TIGL_COMPONENT_WING)
//							{
//							    CCPACSWingSegment& wingSegment = (CCPACSWingSegment&)component.GetSegment(foundShapeIndex);
//								isUpperSide = wingSegment.GetIsOnTop(project1.NearestPoint());
//								eta = wingSegment.GetEta(project1.NearestPoint(), isUpperSide);
//                                xsi = wingSegment.GetXsi(project1.NearestPoint(), isUpperSide);
//							}

//							// set data
//							triangleUID.push_back(uid);
//                            triangleSegment.push_back(foundShapeIndex);
//                            triangleOnTop.push_back(isUpperSide);
//                            triangleEta.push_back(eta);
//                            triangleXsi.push_back(xsi);
//                        }
//                    } // if surface intersect worked
//                } // for triangles
//            } // for faces
//        } // for shells

//        // copy map to enumerated array
//        if(pointArray) delete[] pointArray;
//        pointArray = new gp_Pnt[pointMap.size()];
//        const unsigned int points = pointMap.size();
//        for (PointMapType::iterator it = pointMap.begin(); it != pointMap.end(); ++it) {
//			pointArray[(it->second)] = (it->first);// copy keys (points) to the array element of the value (index number)
//        }
//        pointMap.clear();
//        return points;
//    }



} // end namespace tigl
