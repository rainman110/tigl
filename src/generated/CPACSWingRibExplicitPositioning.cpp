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
#include "CCPACSWingRibsDefinition.h"
#include "CPACSWingRibExplicitPositioning.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSWingRibExplicitPositioning::CPACSWingRibExplicitPositioning(CCPACSWingRibsDefinition* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSWingRibExplicitPositioning::~CPACSWingRibExplicitPositioning()
    {
        if (m_uidMgr) {
            if (m_startSparPositionUID_choice3 && !m_startSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_startSparPositionUID_choice3, *this);
            if (m_endSparPositionUID_choice3 && !m_endSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_endSparPositionUID_choice3, *this);
        }
    }

    const CCPACSWingRibsDefinition* CPACSWingRibExplicitPositioning::GetParent() const
    {
        return m_parent;
    }

    CCPACSWingRibsDefinition* CPACSWingRibExplicitPositioning::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSWingRibExplicitPositioning::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSWingRibExplicitPositioning::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSWingRibExplicitPositioning::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSWingRibExplicitPositioning::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSWingRibExplicitPositioning::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element startEtaXsiPoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startEtaXsiPoint")) {
            m_startEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
            try {
                m_startEtaXsiPoint_choice1->ReadCPACS(tixiHandle, xpath + "/startEtaXsiPoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read startEtaXsiPoint at xpath " << xpath << ": " << e.what();
                m_startEtaXsiPoint_choice1 = boost::none;
            }
        }

        // read element startCurvePoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startCurvePoint")) {
            m_startCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
            try {
                m_startCurvePoint_choice2->ReadCPACS(tixiHandle, xpath + "/startCurvePoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read startCurvePoint at xpath " << xpath << ": " << e.what();
                m_startCurvePoint_choice2 = boost::none;
            }
        }

        // read element startSparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/startSparPositionUID")) {
            m_startSparPositionUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/startSparPositionUID");
            if (m_startSparPositionUID_choice3->empty()) {
                LOG(WARNING) << "Optional element startSparPositionUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_startSparPositionUID_choice3->empty()) m_uidMgr->RegisterReference(*m_startSparPositionUID_choice3, *this);
        }

        // read element endEtaXsiPoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endEtaXsiPoint")) {
            m_endEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
            try {
                m_endEtaXsiPoint_choice1->ReadCPACS(tixiHandle, xpath + "/endEtaXsiPoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read endEtaXsiPoint at xpath " << xpath << ": " << e.what();
                m_endEtaXsiPoint_choice1 = boost::none;
            }
        }

        // read element endCurvePoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endCurvePoint")) {
            m_endCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
            try {
                m_endCurvePoint_choice2->ReadCPACS(tixiHandle, xpath + "/endCurvePoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read endCurvePoint at xpath " << xpath << ": " << e.what();
                m_endCurvePoint_choice2 = boost::none;
            }
        }

        // read element endSparPositionUID
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/endSparPositionUID")) {
            m_endSparPositionUID_choice3 = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/endSparPositionUID");
            if (m_endSparPositionUID_choice3->empty()) {
                LOG(WARNING) << "Optional element endSparPositionUID is present but empty at xpath " << xpath;
            }
            if (m_uidMgr && !m_endSparPositionUID_choice3->empty()) m_uidMgr->RegisterReference(*m_endSparPositionUID_choice3, *this);
        }

        // read element ribStart
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribStart")) {
            m_ribStart = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribStart");
            if (m_ribStart.empty()) {
                LOG(WARNING) << "Required element ribStart is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribStart is missing at xpath " << xpath;
        }

        // read element ribEnd
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/ribEnd")) {
            m_ribEnd = tixi::TixiGetElement<std::string>(tixiHandle, xpath + "/ribEnd");
            if (m_ribEnd.empty()) {
                LOG(WARNING) << "Required element ribEnd is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required element ribEnd is missing at xpath " << xpath;
        }

        if (!ValidateChoices()) {
            LOG(ERROR) << "Invalid choice configuration at xpath " << xpath;
        }
    }

    void CPACSWingRibExplicitPositioning::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "startEtaXsiPoint", "startCurvePoint", "startSparPositionUID", "endEtaXsiPoint", "endCurvePoint", "endSparPositionUID", "ribStart", "ribEnd" };

        // write element startEtaXsiPoint
        if (m_startEtaXsiPoint_choice1) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startEtaXsiPoint", childElemOrder);
            m_startEtaXsiPoint_choice1->WriteCPACS(tixiHandle, xpath + "/startEtaXsiPoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startEtaXsiPoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startEtaXsiPoint");
            }
        }

        // write element startCurvePoint
        if (m_startCurvePoint_choice2) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startCurvePoint", childElemOrder);
            m_startCurvePoint_choice2->WriteCPACS(tixiHandle, xpath + "/startCurvePoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startCurvePoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startCurvePoint");
            }
        }

        // write element startSparPositionUID
        if (m_startSparPositionUID_choice3) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/startSparPositionUID", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/startSparPositionUID", *m_startSparPositionUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/startSparPositionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/startSparPositionUID");
            }
        }

        // write element endEtaXsiPoint
        if (m_endEtaXsiPoint_choice1) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endEtaXsiPoint", childElemOrder);
            m_endEtaXsiPoint_choice1->WriteCPACS(tixiHandle, xpath + "/endEtaXsiPoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endEtaXsiPoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endEtaXsiPoint");
            }
        }

        // write element endCurvePoint
        if (m_endCurvePoint_choice2) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endCurvePoint", childElemOrder);
            m_endCurvePoint_choice2->WriteCPACS(tixiHandle, xpath + "/endCurvePoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endCurvePoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endCurvePoint");
            }
        }

        // write element endSparPositionUID
        if (m_endSparPositionUID_choice3) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/endSparPositionUID", childElemOrder);
            tixi::TixiSaveElement(tixiHandle, xpath + "/endSparPositionUID", *m_endSparPositionUID_choice3);
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/endSparPositionUID")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/endSparPositionUID");
            }
        }

        // write element ribStart
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribStart", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribStart", m_ribStart);

        // write element ribEnd
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/ribEnd", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/ribEnd", m_ribEnd);

    }

    bool CPACSWingRibExplicitPositioning::ValidateChoices() const
    {
        return
        (
            (
                (
                    // mandatory elements of this choice must be there
                    m_startEtaXsiPoint_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startCurvePoint_choice2.is_initialized()
                        ||
                        m_startSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_startCurvePoint_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_startSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_startSparPositionUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_startEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_startCurvePoint_choice2.is_initialized()
                    )
                )
                == 1
            )
            &&
            (
                (
                    // mandatory elements of this choice must be there
                    m_endEtaXsiPoint_choice1.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endCurvePoint_choice2.is_initialized()
                        ||
                        m_endSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_endCurvePoint_choice2.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_endSparPositionUID_choice3.is_initialized()
                    )
                )
                +
                (
                    // mandatory elements of this choice must be there
                    m_endSparPositionUID_choice3.is_initialized()
                    &&
                    // elements of other choices must not be there
                    !(
                        m_endEtaXsiPoint_choice1.is_initialized()
                        ||
                        m_endCurvePoint_choice2.is_initialized()
                    )
                )
                == 1
            )
        )
        ;
    }

    const boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibExplicitPositioning::GetStartEtaXsiPoint_choice1() const
    {
        return m_startEtaXsiPoint_choice1;
    }

    boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibExplicitPositioning::GetStartEtaXsiPoint_choice1()
    {
        return m_startEtaXsiPoint_choice1;
    }

    const boost::optional<CCPACSCurvePoint>& CPACSWingRibExplicitPositioning::GetStartCurvePoint_choice2() const
    {
        return m_startCurvePoint_choice2;
    }

    boost::optional<CCPACSCurvePoint>& CPACSWingRibExplicitPositioning::GetStartCurvePoint_choice2()
    {
        return m_startCurvePoint_choice2;
    }

    const boost::optional<std::string>& CPACSWingRibExplicitPositioning::GetStartSparPositionUID_choice3() const
    {
        return m_startSparPositionUID_choice3;
    }

    void CPACSWingRibExplicitPositioning::SetStartSparPositionUID_choice3(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_startSparPositionUID_choice3 && !m_startSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_startSparPositionUID_choice3, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_startSparPositionUID_choice3 = value;
    }

    const boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibExplicitPositioning::GetEndEtaXsiPoint_choice1() const
    {
        return m_endEtaXsiPoint_choice1;
    }

    boost::optional<CCPACSEtaXsiPoint>& CPACSWingRibExplicitPositioning::GetEndEtaXsiPoint_choice1()
    {
        return m_endEtaXsiPoint_choice1;
    }

    const boost::optional<CCPACSCurvePoint>& CPACSWingRibExplicitPositioning::GetEndCurvePoint_choice2() const
    {
        return m_endCurvePoint_choice2;
    }

    boost::optional<CCPACSCurvePoint>& CPACSWingRibExplicitPositioning::GetEndCurvePoint_choice2()
    {
        return m_endCurvePoint_choice2;
    }

    const boost::optional<std::string>& CPACSWingRibExplicitPositioning::GetEndSparPositionUID_choice3() const
    {
        return m_endSparPositionUID_choice3;
    }

    void CPACSWingRibExplicitPositioning::SetEndSparPositionUID_choice3(const boost::optional<std::string>& value)
    {
        if (m_uidMgr) {
            if (m_endSparPositionUID_choice3 && !m_endSparPositionUID_choice3->empty()) m_uidMgr->TryUnregisterReference(*m_endSparPositionUID_choice3, *this);
            if (value && !value->empty()) m_uidMgr->RegisterReference(*value, *this);
        }
        m_endSparPositionUID_choice3 = value;
    }

    const std::string& CPACSWingRibExplicitPositioning::GetRibStart() const
    {
        return m_ribStart;
    }

    void CPACSWingRibExplicitPositioning::SetRibStart(const std::string& value)
    {
        m_ribStart = value;
    }

    const std::string& CPACSWingRibExplicitPositioning::GetRibEnd() const
    {
        return m_ribEnd;
    }

    void CPACSWingRibExplicitPositioning::SetRibEnd(const std::string& value)
    {
        m_ribEnd = value;
    }

    CCPACSEtaXsiPoint& CPACSWingRibExplicitPositioning::GetStartEtaXsiPoint_choice1(CreateIfNotExistsTag)
    {
        if (!m_startEtaXsiPoint_choice1)
            m_startEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
        return *m_startEtaXsiPoint_choice1;
    }

    void CPACSWingRibExplicitPositioning::RemoveStartEtaXsiPoint_choice1()
    {
        m_startEtaXsiPoint_choice1 = boost::none;
    }

    CCPACSCurvePoint& CPACSWingRibExplicitPositioning::GetStartCurvePoint_choice2(CreateIfNotExistsTag)
    {
        if (!m_startCurvePoint_choice2)
            m_startCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
        return *m_startCurvePoint_choice2;
    }

    void CPACSWingRibExplicitPositioning::RemoveStartCurvePoint_choice2()
    {
        m_startCurvePoint_choice2 = boost::none;
    }

    CCPACSEtaXsiPoint& CPACSWingRibExplicitPositioning::GetEndEtaXsiPoint_choice1(CreateIfNotExistsTag)
    {
        if (!m_endEtaXsiPoint_choice1)
            m_endEtaXsiPoint_choice1 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
        return *m_endEtaXsiPoint_choice1;
    }

    void CPACSWingRibExplicitPositioning::RemoveEndEtaXsiPoint_choice1()
    {
        m_endEtaXsiPoint_choice1 = boost::none;
    }

    CCPACSCurvePoint& CPACSWingRibExplicitPositioning::GetEndCurvePoint_choice2(CreateIfNotExistsTag)
    {
        if (!m_endCurvePoint_choice2)
            m_endCurvePoint_choice2 = boost::in_place(reinterpret_cast<CCPACSWingRibExplicitPositioning*>(this), m_uidMgr);
        return *m_endCurvePoint_choice2;
    }

    void CPACSWingRibExplicitPositioning::RemoveEndCurvePoint_choice2()
    {
        m_endCurvePoint_choice2 = boost::none;
    }

    const CTiglUIDObject* CPACSWingRibExplicitPositioning::GetNextUIDObject() const
    {
        return GetNextUIDParent();
    }

    void CPACSWingRibExplicitPositioning::NotifyUIDChange(const std::string& oldUid, const std::string& newUid)
    {
        if (m_startSparPositionUID_choice3 && *m_startSparPositionUID_choice3 == oldUid) {
            m_startSparPositionUID_choice3 = newUid;
        }
        if (m_endSparPositionUID_choice3 && *m_endSparPositionUID_choice3 == oldUid) {
            m_endSparPositionUID_choice3 = newUid;
        }
    }

} // namespace generated
} // namespace tigl
