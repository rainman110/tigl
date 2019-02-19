// Copyright (c) 2018 RISC Software GmbH
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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceStep
    // CPACSPointList
    // CPACSSeatModule
    // CPACSTransformation

    // generated from /xsd:schema/xsd:complexType[728]
    /// @brief pointType
    /// 
    /// Point type, containing an xyz data triplet.
    /// 
    class CPACSPoint
    {
    public:
        TIGL_EXPORT CPACSPoint(CTiglUIDManager* uidMgr);
        TIGL_EXPORT virtual ~CPACSPoint();

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetX() const;
        TIGL_EXPORT virtual void SetX(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetY() const;
        TIGL_EXPORT virtual void SetY(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetZ() const;
        TIGL_EXPORT virtual void SetZ(const boost::optional<double>& value);

    protected:
        CTiglUIDManager* m_uidMgr;

        std::string             m_uID;

        /// X-Component
        boost::optional<double> m_x;

        /// Y-Component
        boost::optional<double> m_y;

        /// Z-Component
        boost::optional<double> m_z;

    private:
#ifdef HAVE_CPP11
        CPACSPoint(const CPACSPoint&) = delete;
        CPACSPoint& operator=(const CPACSPoint&) = delete;

        CPACSPoint(CPACSPoint&&) = delete;
        CPACSPoint& operator=(CPACSPoint&&) = delete;
#else
        CPACSPoint(const CPACSPoint&);
        CPACSPoint& operator=(const CPACSPoint&);
#endif
    };
} // namespace generated

// CPACSPoint is customized, use type CCPACSPoint directly
} // namespace tigl
