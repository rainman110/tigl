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

#include <cassert>
#include "CCPACSWingSparPositions.h"
#include "CPACSSparPosition.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSSparPosition::CPACSSparPosition(CCPACSWingSparPositions* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_xsi(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSSparPosition::~CPACSSparPosition()
    {
        if (m_uidMgr && m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
    }

    CCPACSWingSparPositions* CPACSSparPosition::GetParent() const
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSSparPosition::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSSparPosition::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSSparPosition::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute uID
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
            m_uID = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "uID");
            if (m_uID->empty()) {
                LOG(WARNING) << "Optional attribute uID is present but empty at xpath " << xpath;
            }
        }

        // read element xsi
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsi")) {
            m_xsi = tixi::TixiGetElement<double>(tixiHandle, xpath + "/xsi");
        }
        else {
            LOG(ERROR) << "Required element xsi is missing at xpath " << xpath;
        }

        // read element eta
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta")) {
            m_eta_choice1 = tixi::TixiGetElement<double>(tixiHandle, xpath + "/eta");
        }

        // read element elementUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementUID")) {
            m_elementUID_choice2 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/elementUID");
            if (m_elementUID_choice2->empty()) {
                LOG(WARNING) << "Optional element elementUID is present but empty at xpath " << xpath;
            }
        }

        if (m_uidMgr && m_uID) m_uidMgr->RegisterObject(*m_uID, *this);
        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSSparPosition::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute uID
        if (m_uID) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "uID", *m_uID);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "uID")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "uID");
            }
        }

        // write element xsi
        tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/xsi");
        tixi::TixiSaveElement(tixiHandle, xpath + "/xsi", m_xsi);

        // write element eta
        if (m_eta_choice1) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/eta");
            tixi::TixiSaveElement(tixiHandle, xpath + "/eta", *m_eta_choice1);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/eta")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/eta");
            }
        }

        // write element elementUID
        if (m_elementUID_choice2) {
            tixi::TixiCreateElementIfNotExists(tixiHandle, xpath + "/elementUID");
            tixi::TixiSaveElement(tixiHandle, xpath + "/elementUID", *m_elementUID_choice2);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/elementUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/elementUID");
            }
        }

    }

    bool CPACSSparPosition::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_eta_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_elementUID_choice2.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_elementUID_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_eta_choice1.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<std::string>& CPACSSparPosition::GetUID() const
    {
        return m_uID;
    }

    void CPACSSparPosition::SetUID(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_uID) m_uidMgr->TryUnregisterObject(*m_uID);
            if (value) m_uidMgr->RegisterObject(*value, *this);
        }
        m_uID = value;
    }

    const double& CPACSSparPosition::GetXsi() const
    {
        return m_xsi;
    }

    void CPACSSparPosition::SetXsi(const double& value)
    {
        m_xsi = value;
    }

    const boost::optional<double>& CPACSSparPosition::GetEta_choice1() const
    {
        return m_eta_choice1;
    }

    void CPACSSparPosition::SetEta_choice1(const boost::optional<double>& value)
    {
        m_eta_choice1 = value;
    }

    const boost::optional<std::string>& CPACSSparPosition::GetElementUID_choice2() const
    {
        return m_elementUID_choice2;
    }

    void CPACSSparPosition::SetElementUID_choice2(const boost::optional<std::string>& value)
    {
        m_elementUID_choice2 = value;
    }

} // namespace generated
} // namespace tigl