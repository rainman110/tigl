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

#include <string>
#include <tixi.h>
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSNacelleCowl;

namespace generated
{
    // This class is used in:
    // CPACSNacelleCowl

    // generated from /xsd:schema/xsd:complexType[1000]
    class CPACSRotationCurve : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSRotationCurve(CCPACSNacelleCowl* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSRotationCurve();

        TIGL_EXPORT CCPACSNacelleCowl* GetParent();

        TIGL_EXPORT const CCPACSNacelleCowl* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetReferenceSectionUID() const;
        TIGL_EXPORT virtual void SetReferenceSectionUID(const std::string& value);

        TIGL_EXPORT virtual const double& GetStartZeta() const;
        TIGL_EXPORT virtual void SetStartZeta(const double& value);

        TIGL_EXPORT virtual const double& GetEndZeta() const;
        TIGL_EXPORT virtual void SetEndZeta(const double& value);

        TIGL_EXPORT virtual const double& GetStartZetaBlending() const;
        TIGL_EXPORT virtual void SetStartZetaBlending(const double& value);

        TIGL_EXPORT virtual const double& GetEndZetaBlending() const;
        TIGL_EXPORT virtual void SetEndZetaBlending(const double& value);

        TIGL_EXPORT virtual const std::string& GetCurveProfileUID() const;
        TIGL_EXPORT virtual void SetCurveProfileUID(const std::string& value);

    protected:
        CCPACSNacelleCowl* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string m_uID;
        std::string m_referenceSectionUID;
        double      m_startZeta;
        double      m_endZeta;
        double      m_startZetaBlending;
        double      m_endZetaBlending;
        std::string m_curveProfileUID;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSRotationCurve(const CPACSRotationCurve&) = delete;
        CPACSRotationCurve& operator=(const CPACSRotationCurve&) = delete;

        CPACSRotationCurve(CPACSRotationCurve&&) = delete;
        CPACSRotationCurve& operator=(CPACSRotationCurve&&) = delete;
    };
} // namespace generated

// CPACSRotationCurve is customized, use type CCPACSRotationCurve directly
} // namespace tigl
