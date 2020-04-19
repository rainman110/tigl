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

#include <cassert>
#include "CCPACSWingRibCrossSection.h"
#include "CPACSWingRibCell.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingRibCell::CPACSWingRibCell(CCPACSWingRibCrossSection* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_ribRotation(this, m_uidMgr)
        , m_material(this, m_uidMgr)
        , m_upperCap(this, m_uidMgr)
        , m_lowerCap(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingRibCell::~CPACSWingRibCell()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CCPACSWingRibCrossSection* CPACSWingRibCell::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingRibCrossSection* CPACSWingRibCell::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingRibCell::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSWingRibCell::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSWingRibCell::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingRibCell::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingRibCell::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID.empty()) {
                LOG(WARNING) << "Required attribute uID is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute uID is missing at xpath " << xpath;
        }

        // read element fromRib
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/fromRib")) {
            m_fromRib = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/fromRib");
            if (m_fromRib.empty()) {
                LOG(WARNING) << "Required element fromRib is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element fromRib is missing at xpath " << xpath;
        }

        // read element toRib
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/toRib")) {
            m_toRib = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/toRib");
            if (m_toRib.empty()) {
                LOG(WARNING) << "Required element toRib is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element toRib is missing at xpath " << xpath;
        }

        // read element ribRotation
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribRotation")) {
            m_ribRotation.ReadCPACS(tixiHandle, xpath + "/ribRotation");
        }
        else {
            LOG(ERROR) << "Required element ribRotation is missing at xpath " << xpath;
        }

        // read element material
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/material")) {
            m_material.ReadCPACS(tixiHandle, xpath + "/material");
        }
        else {
            LOG(ERROR) << "Required element material is missing at xpath " << xpath;
        }

        // read element upperCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperCap")) {
            m_upperCap.ReadCPACS(tixiHandle, xpath + "/upperCap");
        }
        else {
            LOG(ERROR) << "Required element upperCap is missing at xpath " << xpath;
        }

        // read element lowerCap
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerCap")) {
            m_lowerCap.ReadCPACS(tixiHandle, xpath + "/lowerCap");
        }
        else {
            LOG(ERROR) << "Required element lowerCap is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSWingRibCell::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "fromRib", "toRib", "ribRotation", "material", "upperCap", "lowerCap" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element fromRib
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/fromRib", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/fromRib", m_fromRib);

        // write element toRib
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/toRib", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/toRib", m_toRib);

        // write element ribRotation
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribRotation", childElemOrder);
        m_ribRotation.WriteCPACS(tixiHandle, xpath + "/ribRotation");

        // write element material
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/material", childElemOrder);
        m_material.WriteCPACS(tixiHandle, xpath + "/material");

        // write element upperCap
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/upperCap", childElemOrder);
        m_upperCap.WriteCPACS(tixiHandle, xpath + "/upperCap");

        // write element lowerCap
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/lowerCap", childElemOrder);
        m_lowerCap.WriteCPACS(tixiHandle, xpath + "/lowerCap");

    }

    const std::string& CPACSWingRibCell::GetUID() const
    {
        return m_uID;
    }

    void CPACSWingRibCell::SetUID(const std::string& value)
    {
        if (m_uidMgr && value != m_uID) {
            if (m_uID.empty()) {
                m_uidMgr->RegisterObject(value, *this);
            }
            else {
                m_uidMgr->UpdateObjectUID(m_uID, value);
            }
        }
        m_uID = value;
    }

    const std::string& CPACSWingRibCell::GetFromRib() const
    {
        return m_fromRib;
    }

    void CPACSWingRibCell::SetFromRib(const std::string& value)
    {
        m_fromRib = value;
    }

    const std::string& CPACSWingRibCell::GetToRib() const
    {
        return m_toRib;
    }

    void CPACSWingRibCell::SetToRib(const std::string& value)
    {
        m_toRib = value;
    }

    const CPACSPointX& CPACSWingRibCell::GetRibRotation() const
    {
        return m_ribRotation;
    }

    CPACSPointX& CPACSWingRibCell::GetRibRotation()
    {
        return m_ribRotation;
    }

    const CCPACSMaterialDefinition& CPACSWingRibCell::GetMaterial() const
    {
        return m_material;
    }

    CCPACSMaterialDefinition& CPACSWingRibCell::GetMaterial()
    {
        return m_material;
    }

    const CPACSCap& CPACSWingRibCell::GetUpperCap() const
    {
        return m_upperCap;
    }

    CPACSCap& CPACSWingRibCell::GetUpperCap()
    {
        return m_upperCap;
    }

    const CPACSCap& CPACSWingRibCell::GetLowerCap() const
    {
        return m_lowerCap;
    }

    CPACSCap& CPACSWingRibCell::GetLowerCap()
    {
        return m_lowerCap;
    }

} // namespace generated
} // namespace tigl
