// Copyright (c) 2020 RISC Software GmbH
//
// This file was generated by CPACSGen from CPACS XML Schema (c) German Aerospace Center (DLR/SC).
// Do not edit, all changes are lost when files are re-generated.
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <CCPACSControlSurfaceHingePoint.h>
#include <CCPACSControlSurfaceSteps.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;
class CCPACSTrailingEdgeDevice;

namespace generated
{
    // This class is used in:
    // CPACSTrailingEdgeDevice

    // generated from /xsd:schema/xsd:complexType[185]
    /// @brief Definition of the deflection path of the control
    /// surface.
    /// 
    /// The deflection path of a control surface is described
    /// with respect to two hinge points - one at the inner border of
    /// the control surface and one at the outer border of the control
    /// surface. Those two points are defined using the xsi and relative
    /// height coordinates of the parent. Therefore those points can also
    /// lay outbound of the control surface. Those two points defined
    /// the hinge line, which is a straight line between the two points.
    /// The deflection path of the control surface is defined
    /// within the hinge line coordinat system. This is defined as
    /// follows: The x-hinge coordinate equals the wing x-axis. The
    /// y-hinge coordinate equals the hinge line axis (see above;
    /// positive from inner to outer hinge point). The z-hinge line is
    /// perpendicular on the x-hinge and y-hinge coordinate according to
    /// the right hand rule. The rotation of the control surface is
    /// defined as rotation around the positive y-hinge line.
    /// The deflection of the is defined in any number of
    /// steps. The deflection of the control surface is done as follows:
    /// First the x-deflection at the inner and outer border; afterwards
    /// the z-deflection of the inner and outer border; last the
    /// y-deflection of the inner border. The y-deflection is only
    /// defined at the inner border, as it is identical to the outer
    /// border. If no values for the outer border deflection are given,
    /// they default to the values of the inner border.
    /// An example can be found below:
    /// @see path
    /// 
    class CPACSControlSurfacePath
    {
    public:
        TIGL_EXPORT CPACSControlSurfacePath(CCPACSTrailingEdgeDevice* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSControlSurfacePath();

        TIGL_EXPORT CCPACSTrailingEdgeDevice* GetParent();

        TIGL_EXPORT const CCPACSTrailingEdgeDevice* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSControlSurfaceHingePoint& GetInnerHingePoint() const;
        TIGL_EXPORT virtual CCPACSControlSurfaceHingePoint& GetInnerHingePoint();

        TIGL_EXPORT virtual const CCPACSControlSurfaceHingePoint& GetOuterHingePoint() const;
        TIGL_EXPORT virtual CCPACSControlSurfaceHingePoint& GetOuterHingePoint();

        TIGL_EXPORT virtual const CCPACSControlSurfaceSteps& GetSteps() const;
        TIGL_EXPORT virtual CCPACSControlSurfaceSteps& GetSteps();

    protected:
        CCPACSTrailingEdgeDevice* m_parent;

        CTiglUIDManager* m_uidMgr;

        CCPACSControlSurfaceHingePoint m_innerHingePoint;
        CCPACSControlSurfaceHingePoint m_outerHingePoint;
        CCPACSControlSurfaceSteps      m_steps;

    private:
        CPACSControlSurfacePath(const CPACSControlSurfacePath&) = delete;
        CPACSControlSurfacePath& operator=(const CPACSControlSurfacePath&) = delete;

        CPACSControlSurfacePath(CPACSControlSurfacePath&&) = delete;
        CPACSControlSurfacePath& operator=(CPACSControlSurfacePath&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSControlSurfacePath = generated::CPACSControlSurfacePath;
} // namespace tigl
