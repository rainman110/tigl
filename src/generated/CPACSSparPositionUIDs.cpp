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
#include "CCPACSWingSparSegment.h"
#include "CPACSSparPositionUIDs.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSparPositionUIDs::CPACSSparPositionUIDs(CCPACSWingSparSegment* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSparPositionUIDs::~CPACSSparPositionUIDs()
    {
        if (m_uidMgr) {
            for (std::vector<std::string>::iterator it = m_sparPositionUIDs.begin(); it != m_sparPositionUIDs.end(); ++it) {
                if (!it->empty()) m_uidMgr->TryUnregisterReference(*it, *this);
            }
        }
    }

    const CCPACSWingSparSegment* CPACSSparPositionUIDs::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingSparSegment* CPACSSparPositionUIDs::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSSparPositionUIDs::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSSparPositionUIDs::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSSparPositionUIDs::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSparPositionUIDs::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSparPositionUIDs::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element sparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/sparPositionUID")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/sparPositionUID", m_sparPositionUIDs, 2, tixi::xsdUnbounded);
            if (m_uidMgr) {
                for (std::vector<std::string>::iterator it = m_sparPositionUIDs.begin(); it != m_sparPositionUIDs.end(); ++it) {
                    if (!it->empty()) m_uidMgr->RegisterReference(*it, *this);
                }
            }
        }

    }

    void CPACSSparPositionUIDs::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element sparPositionUID
        tixi::TixiSaveElements(tixiHandle, xpath + "/sparPositionUID", m_sparPositionUIDs);

    }

    const std::vector<std::string>& CPACSSparPositionUIDs::GetSparPositionUIDs() const
    {
        return m_sparPositionUIDs;
    }

    std::vector<std::string>& CPACSSparPositionUIDs::GetSparPositionUIDs()
    {
        return m_sparPositionUIDs;
    }

    const CTiglUIDObject* CPACSSparPositionUIDs::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSSparPositionUIDs::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        for (auto& entry : m_sparPositionUIDs) {
            if (entry == oldUid) {
                entry = newUid;
            }
        }
    }

} // namespace generated
} // namespace tigl
