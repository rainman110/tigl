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
#include "CCPACSPointListRelXYZVector.h"
#include "CCPACSPointListXYVector.h"
#include "CCPACSPointListXYZVector.h"
#include "CCPACSRotorBladeAttachment.h"
#include "CCPACSWingProfileCST.h"
#include "CPACSEmissivityMap.h"
#include "CPACSSpecificHeatMap.h"
#include "CPACSStringVectorBase.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSStringVectorBase::CPACSStringVectorBase(CCPACSWingProfileCST* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSWingProfileCST);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CPACSEmissivityMap* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSEmissivityMap);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CCPACSPointListRelXYZVector* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSPointListRelXYZVector);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CCPACSPointListXYVector* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSPointListXYVector);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CCPACSPointListXYZVector* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSPointListXYZVector);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CCPACSRotorBladeAttachment* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CCPACSRotorBladeAttachment);
    }

    CPACSStringVectorBase::CPACSStringVectorBase(CPACSSpecificHeatMap* parent)
    {
        //assert(parent != NULL);
        m_parent = parent;
        m_parentType = &typeid(CPACSSpecificHeatMap);
    }

    CPACSStringVectorBase::~CPACSStringVectorBase()
    {
    }

    const CTiglUIDObject* CPACSStringVectorBase::GetNextUIDParent() const
    {
        if (m_parent) {
            if (IsParent<CCPACSWingProfileCST>()) {
                return GetParent<CCPACSWingProfileCST>()->GetNextUIDParent();
            }
            if (IsParent<CPACSEmissivityMap>()) {
                return GetParent<CPACSEmissivityMap>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListRelXYZVector>()) {
                return GetParent<CCPACSPointListRelXYZVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListXYVector>()) {
                return GetParent<CCPACSPointListXYVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListXYZVector>()) {
                return GetParent<CCPACSPointListXYZVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSRotorBladeAttachment>()) {
                return GetParent<CCPACSRotorBladeAttachment>();
            }
            if (IsParent<CPACSSpecificHeatMap>()) {
                return GetParent<CPACSSpecificHeatMap>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSStringVectorBase::GetNextUIDParent()
    {
        if (m_parent) {
            if (IsParent<CCPACSWingProfileCST>()) {
                return GetParent<CCPACSWingProfileCST>()->GetNextUIDParent();
            }
            if (IsParent<CPACSEmissivityMap>()) {
                return GetParent<CPACSEmissivityMap>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListRelXYZVector>()) {
                return GetParent<CCPACSPointListRelXYZVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListXYVector>()) {
                return GetParent<CCPACSPointListXYVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSPointListXYZVector>()) {
                return GetParent<CCPACSPointListXYZVector>()->GetNextUIDParent();
            }
            if (IsParent<CCPACSRotorBladeAttachment>()) {
                return GetParent<CCPACSRotorBladeAttachment>();
            }
            if (IsParent<CPACSSpecificHeatMap>()) {
                return GetParent<CPACSSpecificHeatMap>()->GetNextUIDParent();
            }
        }
        return nullptr;
    }

    void CPACSStringVectorBase::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read attribute mapType
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "mapType")) {
            m_mapType = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "mapType");
            if (m_mapType.empty()) {
                LOG(WARNING) << "Required attribute mapType is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required attribute mapType is missing at xpath " << xpath;
        }

        // read attribute mu
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "mu")) {
            m_mu = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "mu");
            if (m_mu->empty()) {
                LOG(WARNING) << "Optional attribute mu is present but empty at xpath " << xpath;
            }
        }

        // read attribute delta
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "delta")) {
            m_delta = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "delta");
            if (m_delta->empty()) {
                LOG(WARNING) << "Optional attribute delta is present but empty at xpath " << xpath;
            }
        }

        // read attribute a
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "a")) {
            m_a = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "a");
            if (m_a->empty()) {
                LOG(WARNING) << "Optional attribute a is present but empty at xpath " << xpath;
            }
        }

        // read attribute b
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "b")) {
            m_b = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "b");
            if (m_b->empty()) {
                LOG(WARNING) << "Optional attribute b is present but empty at xpath " << xpath;
            }
        }

        // read attribute c
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "c")) {
            m_c = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "c");
            if (m_c->empty()) {
                LOG(WARNING) << "Optional attribute c is present but empty at xpath " << xpath;
            }
        }

        // read attribute v
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "v")) {
            m_v = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "v");
            if (m_v->empty()) {
                LOG(WARNING) << "Optional attribute v is present but empty at xpath " << xpath;
            }
        }

        // read attribute w
        if (tixi::TixiCheckAttribute(tixiHandle, xpath, "w")) {
            m_w = tixi::TixiGetAttribute<std::string>(tixiHandle, xpath, "w");
            if (m_w->empty()) {
                LOG(WARNING) << "Optional attribute w is present but empty at xpath " << xpath;
            }
        }

        // read simpleContent 
        if (tixi::TixiCheckElement(tixiHandle, xpath)) {
            m_simpleContent = tixi::TixiGetElement<std::string>(tixiHandle, xpath);
            if (m_simpleContent.empty()) {
                LOG(WARNING) << "Required element  is empty at xpath " << xpath;
            }
        }
        else {
            LOG(ERROR) << "Required simpleContent  is missing at xpath " << xpath;
        }

    }

    void CPACSStringVectorBase::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        // write attribute mapType
        tixi::TixiSaveAttribute(tixiHandle, xpath, "mapType", m_mapType);

        // write attribute mu
        if (m_mu) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "mu", *m_mu);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "mu")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "mu");
            }
        }

        // write attribute delta
        if (m_delta) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "delta", *m_delta);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "delta")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "delta");
            }
        }

        // write attribute a
        if (m_a) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "a", *m_a);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "a")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "a");
            }
        }

        // write attribute b
        if (m_b) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "b", *m_b);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "b")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "b");
            }
        }

        // write attribute c
        if (m_c) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "c", *m_c);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "c")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "c");
            }
        }

        // write attribute v
        if (m_v) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "v", *m_v);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "v")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "v");
            }
        }

        // write attribute w
        if (m_w) {
            tixi::TixiSaveAttribute(tixiHandle, xpath, "w", *m_w);
        }
        else {
            if (tixi::TixiCheckAttribute(tixiHandle, xpath, "w")) {
                tixi::TixiRemoveAttribute(tixiHandle, xpath, "w");
            }
        }

        // write simpleContent 
        tixi::TixiSaveElement(tixiHandle, xpath, m_simpleContent);

    }

    const std::string& CPACSStringVectorBase::GetMapType() const
    {
        return m_mapType;
    }

    void CPACSStringVectorBase::SetMapType(const std::string& value)
    {
        m_mapType = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetMu() const
    {
        return m_mu;
    }

    void CPACSStringVectorBase::SetMu(const boost::optional<std::string>& value)
    {
        m_mu = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetDelta() const
    {
        return m_delta;
    }

    void CPACSStringVectorBase::SetDelta(const boost::optional<std::string>& value)
    {
        m_delta = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetA() const
    {
        return m_a;
    }

    void CPACSStringVectorBase::SetA(const boost::optional<std::string>& value)
    {
        m_a = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetB() const
    {
        return m_b;
    }

    void CPACSStringVectorBase::SetB(const boost::optional<std::string>& value)
    {
        m_b = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetC() const
    {
        return m_c;
    }

    void CPACSStringVectorBase::SetC(const boost::optional<std::string>& value)
    {
        m_c = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetV() const
    {
        return m_v;
    }

    void CPACSStringVectorBase::SetV(const boost::optional<std::string>& value)
    {
        m_v = value;
    }

    const boost::optional<std::string>& CPACSStringVectorBase::GetW() const
    {
        return m_w;
    }

    void CPACSStringVectorBase::SetW(const boost::optional<std::string>& value)
    {
        m_w = value;
    }

    const std::string& CPACSStringVectorBase::GetSimpleContent() const
    {
        return m_simpleContent;
    }

    void CPACSStringVectorBase::SetSimpleContent(const std::string& value)
    {
        m_simpleContent = value;
    }

} // namespace generated
} // namespace tigl
