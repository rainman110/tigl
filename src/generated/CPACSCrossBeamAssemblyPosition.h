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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "CPACSAlignmentCrossBeam.h"
#include "CreateIfNotExists.h"
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSCargoCrossBeamsAssembly;

namespace generated
{
    // This class is used in:
    // CPACSCargoCrossBeamsAssembly

    // generated from /xsd:schema/xsd:complexType[235]
    /// @brief crossBeamAssemblyPositionType
    /// 
    /// CrossBeamAssemblyPosition type, containing the position
    /// of a crossBeam assembly
    /// 
    class CPACSCrossBeamAssemblyPosition : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSCrossBeamAssemblyPosition(CCPACSCargoCrossBeamsAssembly* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSCrossBeamAssemblyPosition();

        TIGL_EXPORT CCPACSCargoCrossBeamsAssembly* GetParent();

        TIGL_EXPORT const CCPACSCargoCrossBeamsAssembly* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStructuralElementUID() const;
        TIGL_EXPORT virtual void SetStructuralElementUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetFrameUID() const;
        TIGL_EXPORT virtual void SetFrameUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetPositionZ() const;
        TIGL_EXPORT virtual void SetPositionZ(const double& value);

        TIGL_EXPORT virtual const boost::optional<CPACSAlignmentCrossBeam>& GetAlignment() const;
        TIGL_EXPORT virtual boost::optional<CPACSAlignmentCrossBeam>& GetAlignment();

        TIGL_EXPORT virtual CPACSAlignmentCrossBeam& GetAlignment(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveAlignment();

    protected:
        CCPACSCargoCrossBeamsAssembly* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                              m_uID;

        /// UID of profile based structural element to be
        /// used as crossbeam
        std::string                              m_structuralElementUID;

        /// UID of the frame to which the crossbeam is
        /// attached
        std::string                              m_frameUID;

        /// Referenze z position of the crossbeam
        double                                   m_positionZ;

        boost::optional<CPACSAlignmentCrossBeam> m_alignment;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSCrossBeamAssemblyPosition(const CPACSCrossBeamAssemblyPosition&) = delete;
        CPACSCrossBeamAssemblyPosition& operator=(const CPACSCrossBeamAssemblyPosition&) = delete;

        CPACSCrossBeamAssemblyPosition(CPACSCrossBeamAssemblyPosition&&) = delete;
        CPACSCrossBeamAssemblyPosition& operator=(CPACSCrossBeamAssemblyPosition&&) = delete;
    };
} // namespace generated

// CPACSCrossBeamAssemblyPosition is customized, use type CCPACSCrossBeamAssemblyPosition directly
} // namespace tigl
