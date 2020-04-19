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
#include "CPACSPlasticityCurvePoint.h"
#include "CPACSPostFailure.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSPlasticityCurvePoint::CPACSPlasticityCurvePoint(CPACSPostFailure* parent)
        : m_tangentModulus(0)
        , m_trueStress(0)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSPlasticityCurvePoint::~CPACSPlasticityCurvePoint()
    {
    }

    const CPACSPostFailure* CPACSPlasticityCurvePoint::GetParent() const
    {
        return m_parent;
    }

    CPACSPostFailure* CPACSPlasticityCurvePoint::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSPlasticityCurvePoint::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSPlasticityCurvePoint::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    void CPACSPlasticityCurvePoint::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element tangentModulus
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/tangentModulus")) {
            m_tangentModulus = tixi::TixiGetElement<double>(tixiHandle, xpath + "/tangentModulus");
        }
        else {
            LOG(ERROR) << "Required element tangentModulus is missing at xpath " << xpath;
        }

        // read element trueStress
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/trueStress")) {
            m_trueStress = tixi::TixiGetElement<double>(tixiHandle, xpath + "/trueStress");
        }
        else {
            LOG(ERROR) << "Required element trueStress is missing at xpath " << xpath;
        }

    }

    void CPACSPlasticityCurvePoint::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "tangentModulus", "trueStress" };

        // write element tangentModulus
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/tangentModulus", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/tangentModulus", m_tangentModulus);

        // write element trueStress
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/trueStress", childElemOrder);
        tixi::TixiSaveElement(tixiHandle, xpath + "/trueStress", m_trueStress);

    }

    const double& CPACSPlasticityCurvePoint::GetTangentModulus() const
    {
        return m_tangentModulus;
    }

    void CPACSPlasticityCurvePoint::SetTangentModulus(const double& value)
    {
        m_tangentModulus = value;
    }

    const double& CPACSPlasticityCurvePoint::GetTrueStress() const
    {
        return m_trueStress;
    }

    void CPACSPlasticityCurvePoint::SetTrueStress(const double& value)
    {
        m_trueStress = value;
    }

} // namespace generated
} // namespace tigl
