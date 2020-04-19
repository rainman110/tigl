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
#include <CCPACSEnginePosition.h>
#include "CCPACSAircraftModel.h"
#include "CCPACSRotorcraftModel.h"
#include "CPACSEnginePositions.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSEnginePositions::CPACSEnginePositions(CCPACSAircraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSAircraftModel);
    }

    CPACSEnginePositions::CPACSEnginePositions(CCPACSRotorcraftModel* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotorcraftModel);
    }

    CPACSEnginePositions::~CPACSEnginePositions()
    {
    }

    const CTiglUIDObject* CPACSEnginePositions::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSAircraftModel>()) {
                return GetParent<CCPACSAircraftModel>();
            }
            if (IsParent<CCPACSRotorcraftModel>()) {
                return GetParent<CCPACSRotorcraftModel>();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSEnginePositions::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSAircraftModel>()) {
                return GetParent<CCPACSAircraftModel>();
            }
            if (IsParent<CCPACSRotorcraftModel>()) {
                return GetParent<CCPACSRotorcraftModel>();
            }
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSEnginePositions::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSEnginePositions::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSEnginePositions::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element engine
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/engine")) {
            tixi::TixiReadElements(tixiHandle, xpath + "/engine", m_engines, 1, tixi::xsdUnbounded, reinterpret_cast<CCPACSEnginePositions*>(this), m_uidMgr);
        }

    }

    void CPACSEnginePositions::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write element engine
        tixi::TixiSaveElements(tixiHandle, xpath + "/engine", m_engines);

    }

    const std::vector<std::unique_ptr<CCPACSEnginePosition>>& CPACSEnginePositions::GetEngines() const
    {
        return m_engines;
    }

    std::vector<std::unique_ptr<CCPACSEnginePosition>>& CPACSEnginePositions::GetEngines()
    {
        return m_engines;
    }

    CCPACSEnginePosition& CPACSEnginePositions::AddEngine()
    {
        m_engines.push_back(make_unique<CCPACSEnginePosition>(reinterpret_cast<CCPACSEnginePositions*>(this), m_uidMgr));
        return *m_engines.back();
    }

    void CPACSEnginePositions::RemoveEngine(CCPACSEnginePosition& ref)
    {
        for (std::size_t i = 0; i < m_engines.size(); i++) {
            if (m_engines[i].get() == &ref) {
                m_engines.erase(m_engines.begin() + i);
                return;
            }
        }
        throw CTiglError("Element not found");
    }

} // namespace generated
} // namespace tigl
