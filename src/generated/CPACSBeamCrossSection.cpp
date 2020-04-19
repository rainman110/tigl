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
#include "CPACSBeamCrossSection.h"
#include "CPACSGlobalBeamProperties.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSBeamCrossSection::CPACSBeamCrossSection(CPACSGlobalBeamProperties* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_area(0)
        , m_xMin(0)
        , m_xMax(0)
        , m_yMin(0)
        , m_yMax(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSBeamCrossSection::~CPACSBeamCrossSection()
    {
        if (m_uidMgr) m_uidMgr->TryUnregisterObject(m_uID);
    }

    const CPACSGlobalBeamProperties* CPACSBeamCrossSection::GetParent() const
    {
        return m_parent;
    }

    CPACSGlobalBeamProperties* CPACSBeamCrossSection::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSBeamCrossSection::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSBeamCrossSection::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSBeamCrossSection::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSBeamCrossSection::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSBeamCrossSection::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
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

        // read element area
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/area")) {
            m_area = tixi::TixiGetElement<double>(tixiHandle, xpath + "/area");
        }
        else {
            LOG(ERROR) << "Required element area is missing at xpath " << xpath;
        }

        // read element xMin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xMin")) {
            m_xMin = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xMin");
        }
        else {
            LOG(ERROR) << "Required element xMin is missing at xpath " << xpath;
        }

        // read element xMax
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xMax")) {
            m_xMax = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xMax");
        }
        else {
            LOG(ERROR) << "Required element xMax is missing at xpath " << xpath;
        }

        // read element yMin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/yMin")) {
            m_yMin = tixi::TixiGetElement<double>(tixiHandle, xpath + "/yMin");
        }
        else {
            LOG(ERROR) << "Required element yMin is missing at xpath " << xpath;
        }

        // read element yMax
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/yMax")) {
            m_yMax = tixi::TixiGetElement<double>(tixiHandle, xpath + "/yMax");
        }
        else {
            LOG(ERROR) << "Required element yMax is missing at xpath " << xpath;
        }

        if (m_uidMgr && !m_uID.empty()) m_uidMgr->RegisterObject(m_uID, *this);
    }

    void CPACSBeamCrossSection::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "area", "xMin", "xMax", "yMin", "yMax" };

        // write attribute uID
        tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", m_uID);

        // write element area
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/area", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/area", m_area);

        // write element xMin
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/xMin", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/xMin", m_xMin);

        // write element xMax
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/xMax", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/xMax", m_xMax);

        // write element yMin
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/yMin", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/yMin", m_yMin);

        // write element yMax
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/yMax", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/yMax", m_yMax);

    }

    const std::string& CPACSBeamCrossSection::GetUID() const
    {
        return m_uID;
    }

    void CPACSBeamCrossSection::SetUID(const std::string& value)
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

    const double& CPACSBeamCrossSection::GetArea() const
    {
        return m_area;
    }

    void CPACSBeamCrossSection::SetArea(const double& value)
    {
        m_area = value;
    }

    const double& CPACSBeamCrossSection::GetXMin() const
    {
        return m_xMin;
    }

    void CPACSBeamCrossSection::SetXMin(const double& value)
    {
        m_xMin = value;
    }

    const double& CPACSBeamCrossSection::GetXMax() const
    {
        return m_xMax;
    }

    void CPACSBeamCrossSection::SetXMax(const double& value)
    {
        m_xMax = value;
    }

    const double& CPACSBeamCrossSection::GetYMin() const
    {
        return m_yMin;
    }

    void CPACSBeamCrossSection::SetYMin(const double& value)
    {
        m_yMin = value;
    }

    const double& CPACSBeamCrossSection::GetYMax() const
    {
        return m_yMax;
    }

    void CPACSBeamCrossSection::SetYMax(const double& value)
    {
        m_yMax = value;
    }

} // namespace generated
} // namespace tigl
