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

#include <CCPACSMaterialDefinition.h>
#include <string>
#include <tixi.h>
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSControlSurfaceTrackType;

namespace generated
{
    // This class is used in:
    // CPACSControlSurfaceTrackType

    // generated from /xsd:schema/xsd:complexType[882]
    /// @brief trackActuatorType
    /// 
    /// 
    /// 
    class CPACSTrackActuator : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSTrackActuator(CCPACSControlSurfaceTrackType* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSTrackActuator();

        TIGL_EXPORT CCPACSControlSurfaceTrackType* GetParent();

        TIGL_EXPORT const CCPACSControlSurfaceTrackType* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetActuatorUID() const;
        TIGL_EXPORT virtual void SetActuatorUID(const std::string& value);

        TIGL_EXPORT virtual const CCPACSMaterialDefinition& GetMaterial() const;
        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetMaterial();

    protected:
        CCPACSControlSurfaceTrackType* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string              m_uID;

        /// Reference to the uID of the actuator of the
        /// track.
        std::string              m_actuatorUID;

        /// Definition of the material properties of the
        /// actuator to track attachment.
        CCPACSMaterialDefinition m_material;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSTrackActuator(const CPACSTrackActuator&) = delete;
        CPACSTrackActuator& operator=(const CPACSTrackActuator&) = delete;

        CPACSTrackActuator(CPACSTrackActuator&&) = delete;
        CPACSTrackActuator& operator=(CPACSTrackActuator&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSTrackActuator = generated::CPACSTrackActuator;
} // namespace tigl
