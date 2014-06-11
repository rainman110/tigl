/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2014-05-26 Martin Siggel <Martin.Siggel@dlr.de>
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

#include "CTiglMakeLoft.h"
#include "tigl_config.h"

#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopExp.hxx>
#include <BRep_Builder.hxx>
#include <BRepLib.hxx>
#ifdef LOFTALGO_FOUND
  #include <MakePatches.hxx>
#endif
#include <BRepOffsetAPI_ThruSections.hxx>
#include <BRepBuilderAPI_FindPlane.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepClass3d_SolidClassifier.hxx>
#include <BRepBuilderAPI_Sewing.hxx>
#include <StdFail_NotDone.hxx>
#include <Precision.hxx>

namespace 
{
    TopoDS_Solid MakeSolid(TopoDS_Shape& shell, const TopoDS_Wire& wire1,
                           const TopoDS_Wire& wire2, const Standard_Real presPln,
                           TopoDS_Face& face1, TopoDS_Face& face2);
    
    TopoDS_Shape MakeShells(TopoDS_Shape& shell, const Standard_Real presPln);
} // namespace

CMakeLoft::CMakeLoft(double tolerance)
{
    _hasPerformed = false;
    _makeSolid = true;
    _result.Nullify();
    _myTolerance = tolerance;
}

CMakeLoft::CMakeLoft(const TopoDS_Shape &profiles, const TopoDS_Shape &guides, double tolerance)
{
    _hasPerformed = false;
    _result.Nullify();
    _myTolerance = tolerance;
    addProfiles(profiles);
    addGuides(guides);
}

void CMakeLoft::addProfiles(const TopoDS_Shape &profiles)
{
    if (profiles.ShapeType() == TopAbs_COMPOUND) {
        for (TopoDS_Iterator anIter(profiles); anIter.More(); anIter.Next()) {
            TopoDS_Wire aSh = TopoDS::Wire(anIter.Value());
            this->profiles.push_back(aSh);
        }
    }
    else {
        this->profiles.push_back(TopoDS::Wire(profiles));
    }
}

void CMakeLoft::addGuides(const TopoDS_Shape &guides)
{
    if (guides.ShapeType() == TopAbs_COMPOUND) {
        for (TopoDS_Iterator anIter(guides); anIter.More(); anIter.Next()) {
            TopoDS_Wire aSh = TopoDS::Wire(anIter.Value());
            this->guides.push_back(aSh);
        }
    }
    else {
        this->guides.push_back(TopoDS::Wire(guides));
    }
}

TopoDS_Shape &CMakeLoft::Shape()
{
    Perform();
    
    return _result;
}

CMakeLoft::operator TopoDS_Shape &()
{
    return Shape();
}

void CMakeLoft::Perform() 
{
    if (_hasPerformed) {
        return;
    }
    
    if (guides.size() > 0) {
#ifdef LOFTALGO_FOUND
        // to the loft with guides
        makeLoftWithGuides();
#else
        makeLoftWithGuides();
#endif
    }
    else {
        makeLoftWithoutGuides();
    }
    _hasPerformed = true;
}

void CMakeLoft::setMakeSolid(bool enabled)
{
    _makeSolid = enabled;
}

/**
 * @brief Builds the loft using profiles and guide curves
 */
void CMakeLoft::makeLoftWithGuides()
{
#ifdef LOFTALGO_FOUND
    BRep_Builder b;
    TopoDS_Compound cprof, cguid;
    b.MakeCompound(cprof);
    b.MakeCompound(cguid);
    
    for (unsigned int i = 0; i < profiles.size(); ++i) {
        TopoDS_Wire& profile =  profiles[i];
        b.Add(cprof, profile);
    }
    for (unsigned int i = 0; i < guides.size(); ++i) {
        TopoDS_Wire& guide =  guides[i];
        b.Add(cguid, guide);
    }
    
    MakePatches SurfMaker(cguid, cprof);
    // Don't sew yet. We do it later in solid creation
    SurfMaker.Perform(_myTolerance, 1e-4, GeomFill_CoonsC2Style, Standard_False);
    TopoDS_Shape faces = SurfMaker.Patches();
    std::cout << "Status: " << SurfMaker.GetStatus() << std::endl;
    
    if (_makeSolid) {
        // check if the first wire is the same as the last
        Standard_Boolean vClosed = (profiles[0].IsSame(profiles[profiles.size()-1]));
        
        if (vClosed) {
            // we dont need side caps, just make shell and close it
            TopoDS_Shape shell = MakeShells(faces, _myTolerance);
            
            TopoDS_Solid solid;
            BRep_Builder B;
            B.MakeSolid(solid); 
            B.Add(solid, shell);
            
            // verify the orientation of the solid
            BRepClass3d_SolidClassifier clas3d(solid);
            clas3d.PerformInfinitePoint(Precision::Confusion());
            if (clas3d.State() == TopAbs_IN) {
                B.MakeSolid(solid); 
                TopoDS_Shape aLocalShape = faces.Reversed();
                B.Add(solid, TopoDS::Shell(aLocalShape));
            }
            _result = solid;
        }
        else {
            // make solid by adding side caps
            TopoDS_Wire wire1 = TopoDS::Wire(profiles[0]);
            TopoDS_Wire wire2 = TopoDS::Wire(profiles[profiles.size()-1]);
            TopoDS_Face innerCap, outerCap;
            _result = faces;
            _result = MakeSolid(faces, wire1, wire2, 1e-6, innerCap, outerCap);
        }
    }
    else {
        // don't make solid
        _result = MakeShells(faces, 1e-6);
    }
    BRepLib::EncodeRegularity(_result);
#endif // LOFTALGO_FOUND
}

void CMakeLoft::makeLoftWithoutGuides()
{
    BRepOffsetAPI_ThruSections lofter(_makeSolid, Standard_True, _myTolerance);
    for (unsigned int i = 0; i < profiles.size(); ++i) {
        TopoDS_Wire& profile =  profiles[i];
        lofter.AddWire(profile);
    }
    lofter.CheckCompatibility(Standard_False);
    _result = lofter.Shape();
}

namespace
{
    // Creates a face to close a profile
    // Code taken from opencascade, BRepOffsetAPI_ThruSections
    Standard_Boolean CreateSideCap(const TopoDS_Wire& W,
                                   const Standard_Real presPln,
                                   TopoDS_Face& theFace)
    {
        Standard_Boolean isDegen = Standard_True;
        TopoDS_Iterator iter(W);
        for (; iter.More(); iter.Next())
        {
            const TopoDS_Edge& anEdge = TopoDS::Edge(iter.Value());
            if (!BRep_Tool::Degenerated(anEdge))
                isDegen = Standard_False;
        }
        if (isDegen)
            return Standard_True;
        
        Standard_Boolean Ok = Standard_False;
        if (!W.IsNull()) {
            BRepBuilderAPI_FindPlane Searcher( W, presPln );
            if (Searcher.Found()) {
                theFace = BRepBuilderAPI_MakeFace(Searcher.Plane(), W);
                Ok = Standard_True;
            }
            else {
                // try to find another surface
                BRepBuilderAPI_MakeFace MF( W );
                if (MF.IsDone())
                {
                    theFace = MF.Face();
                    Ok = Standard_True;
                }
            }
        }
        
        return Ok;
    }

    // Code adapted from opencascade, BRepOffsetAPI_ThruSections
    TopoDS_Solid MakeSolid(TopoDS_Shape& shell, 
                           const TopoDS_Wire& wire1, const TopoDS_Wire& wire2, 
                           const Standard_Real presPln,
                           TopoDS_Face& face1, TopoDS_Face& face2)
    {
        if (shell.IsNull()) {
            StdFail_NotDone::Raise("Thrusections is not build");
        }
        Standard_Boolean B = shell.Closed();
        
        BRepBuilderAPI_Sewing sewingAlgo;
        sewingAlgo.Add(shell);

        
        if (!B) {
            // It is necessary to close the extremities 
            B =  CreateSideCap(wire1, presPln, face1);
            if (B) {
                B =  CreateSideCap(wire2, presPln, face2);
                if (B) {
                    if (!face1.IsNull()) {
                        sewingAlgo.Add(face1);
                    }
                    if (!face2.IsNull()) {
                        sewingAlgo.Add(face2);
                    }
                }
            }
        }
        
        sewingAlgo.Perform();
        TopoDS_Shape shellClosed  = sewingAlgo.SewedShape();
        shellClosed.Closed(Standard_True);

        // make solid from shell
        TopoDS_Solid solid;
        BRep_Builder solidMaker;
        solidMaker.MakeSolid(solid); 
        solidMaker.Add(solid, shellClosed);
        
        // verify the orientation the solid
        BRepClass3d_SolidClassifier clas3d(solid);
        clas3d.PerformInfinitePoint(Precision::Confusion());
        if (clas3d.State() == TopAbs_IN) {
            solidMaker.MakeSolid(solid); 
            TopoDS_Shape aLocalShape = shellClosed.Reversed();
            solidMaker.Add(solid, TopoDS::Shell(aLocalShape));
        }
        
        solid.Closed(Standard_True);
        return solid;
    }
    
    TopoDS_Shape MakeShells(TopoDS_Shape& shell, const Standard_Real presPln)
    {
        if (shell.IsNull()) {
            StdFail_NotDone::Raise("Thrusections is not build");
        }

        BRepBuilderAPI_Sewing BB(presPln);
        BB.Add(shell);
        BB.Perform();
        
        TopoDS_Shape shellClosed  = BB.SewedShape();
        return shellClosed;
    }

} // namespace
