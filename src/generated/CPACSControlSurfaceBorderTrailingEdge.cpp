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
#include "CCPACSControlSurfaceOuterShapeTrailingEdge.h"
#include "CPACSControlSurfaceBorderTrailingEdge.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSControlSurfaceBorderTrailingEdge::CPACSControlSurfaceBorderTrailingEdge(CCPACSControlSurfaceOuterShapeTrailingEdge* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_etaLE(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr)
        , m_xsiLE(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSControlSurfaceBorderTrailingEdge::~CPACSControlSurfaceBorderTrailingEdge()
    {
    }

    const CCPACSControlSurfaceOuterShapeTrailingEdge* CPACSControlSurfaceBorderTrailingEdge::GetParent() const
    {
        return m_parent;
    }

    CCPACSControlSurfaceOuterShapeTrailingEdge* CPACSControlSurfaceBorderTrailingEdge::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSControlSurfaceBorderTrailingEdge::GetNextUIDParent() const
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDObject* CPACSControlSurfaceBorderTrailingEdge::GetNextUIDParent()
    {
        if (m_parent) {
            return m_parent->GetNextUIDParent();
        }
        return nullptr;
    }

    CTiglUIDManager& CPACSControlSurfaceBorderTrailingEdge::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSControlSurfaceBorderTrailingEdge::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSControlSurfaceBorderTrailingEdge::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element etaLE
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaLE")) {
            m_etaLE.ReadCPACS(tixiHandle, xpath + "/etaLE");
        }
        else {
            LOG(ERROR) << "Required element etaLE is missing at xpath " << xpath;
        }

        // read element etaTE
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaTE")) {
            m_etaTE = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr);
            try {
                m_etaTE->ReadCPACS(tixiHandle, xpath + "/etaTE");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read etaTE at xpath " << xpath << ": " << e.what();
                m_etaTE = boost::none;
            }
        }

        // read element xsiLE
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/xsiLE")) {
            m_xsiLE.ReadCPACS(tixiHandle, xpath + "/xsiLE");
        }
        else {
            LOG(ERROR) << "Required element xsiLE is missing at xpath " << xpath;
        }

        // read element innerShape
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerShape")) {
            m_innerShape = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this));
            try {
                m_innerShape->ReadCPACS(tixiHandle, xpath + "/innerShape");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read innerShape at xpath " << xpath << ": " << e.what();
                m_innerShape = boost::none;
            }
        }

        // read element leadingEdgeShape
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/leadingEdgeShape")) {
            m_leadingEdgeShape = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this));
            try {
                m_leadingEdgeShape->ReadCPACS(tixiHandle, xpath + "/leadingEdgeShape");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read leadingEdgeShape at xpath " << xpath << ": " << e.what();
                m_leadingEdgeShape = boost::none;
            }
        }

        // read element airfoil
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/airfoil")) {
            m_airfoil = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr);
            try {
                m_airfoil->ReadCPACS(tixiHandle, xpath + "/airfoil");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read airfoil at xpath " << xpath << ": " << e.what();
                m_airfoil = boost::none;
            }
        }

    }

    void CPACSControlSurfaceBorderTrailingEdge::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "etaLE", "etaTE", "xsiLE", "innerShape", "leadingEdgeShape", "airfoil" };

        // write element etaLE
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/etaLE", childElemOrder);
        m_etaLE.WriteCPACS(tixiHandle, xpath + "/etaLE");

        // write element etaTE
        if (m_etaTE) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/etaTE", childElemOrder);
            m_etaTE->WriteCPACS(tixiHandle, xpath + "/etaTE");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/etaTE")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/etaTE");
            }
        }

        // write element xsiLE
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/xsiLE", childElemOrder);
        m_xsiLE.WriteCPACS(tixiHandle, xpath + "/xsiLE");

        // write element innerShape
        if (m_innerShape) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/innerShape", childElemOrder);
            m_innerShape->WriteCPACS(tixiHandle, xpath + "/innerShape");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerShape")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/innerShape");
            }
        }

        // write element leadingEdgeShape
        if (m_leadingEdgeShape) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/leadingEdgeShape", childElemOrder);
            m_leadingEdgeShape->WriteCPACS(tixiHandle, xpath + "/leadingEdgeShape");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/leadingEdgeShape")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/leadingEdgeShape");
            }
        }

        // write element airfoil
        if (m_airfoil) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/airfoil", childElemOrder);
            m_airfoil->WriteCPACS(tixiHandle, xpath + "/airfoil");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/airfoil")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/airfoil");
            }
        }

    }

    const CCPACSEtaIsoLine& CPACSControlSurfaceBorderTrailingEdge::GetEtaLE() const
    {
        return m_etaLE;
    }

    CCPACSEtaIsoLine& CPACSControlSurfaceBorderTrailingEdge::GetEtaLE()
    {
        return m_etaLE;
    }

    const boost::optional<CCPACSEtaIsoLine>& CPACSControlSurfaceBorderTrailingEdge::GetEtaTE() const
    {
        return m_etaTE;
    }

    boost::optional<CCPACSEtaIsoLine>& CPACSControlSurfaceBorderTrailingEdge::GetEtaTE()
    {
        return m_etaTE;
    }

    const CCPACSXsiIsoLine& CPACSControlSurfaceBorderTrailingEdge::GetXsiLE() const
    {
        return m_xsiLE;
    }

    CCPACSXsiIsoLine& CPACSControlSurfaceBorderTrailingEdge::GetXsiLE()
    {
        return m_xsiLE;
    }

    const boost::optional<CPACSLeadingEdgeHollow>& CPACSControlSurfaceBorderTrailingEdge::GetInnerShape() const
    {
        return m_innerShape;
    }

    boost::optional<CPACSLeadingEdgeHollow>& CPACSControlSurfaceBorderTrailingEdge::GetInnerShape()
    {
        return m_innerShape;
    }

    const boost::optional<CPACSLeadingEdgeShape>& CPACSControlSurfaceBorderTrailingEdge::GetLeadingEdgeShape() const
    {
        return m_leadingEdgeShape;
    }

    boost::optional<CPACSLeadingEdgeShape>& CPACSControlSurfaceBorderTrailingEdge::GetLeadingEdgeShape()
    {
        return m_leadingEdgeShape;
    }

    const boost::optional<CPACSContourReference>& CPACSControlSurfaceBorderTrailingEdge::GetAirfoil() const
    {
        return m_airfoil;
    }

    boost::optional<CPACSContourReference>& CPACSControlSurfaceBorderTrailingEdge::GetAirfoil()
    {
        return m_airfoil;
    }

    CCPACSEtaIsoLine& CPACSControlSurfaceBorderTrailingEdge::GetEtaTE(CreateIfNotExistsTag)
    {
        if (!m_etaTE)
            m_etaTE = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr);
        return *m_etaTE;
    }

    void CPACSControlSurfaceBorderTrailingEdge::RemoveEtaTE()
    {
        m_etaTE = boost::none;
    }

    CPACSLeadingEdgeHollow& CPACSControlSurfaceBorderTrailingEdge::GetInnerShape(CreateIfNotExistsTag)
    {
        if (!m_innerShape)
            m_innerShape = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this));
        return *m_innerShape;
    }

    void CPACSControlSurfaceBorderTrailingEdge::RemoveInnerShape()
    {
        m_innerShape = boost::none;
    }

    CPACSLeadingEdgeShape& CPACSControlSurfaceBorderTrailingEdge::GetLeadingEdgeShape(CreateIfNotExistsTag)
    {
        if (!m_leadingEdgeShape)
            m_leadingEdgeShape = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this));
        return *m_leadingEdgeShape;
    }

    void CPACSControlSurfaceBorderTrailingEdge::RemoveLeadingEdgeShape()
    {
        m_leadingEdgeShape = boost::none;
    }

    CPACSContourReference& CPACSControlSurfaceBorderTrailingEdge::GetAirfoil(CreateIfNotExistsTag)
    {
        if (!m_airfoil)
            m_airfoil = boost::in_place(reinterpret_cast<CCPACSControlSurfaceBorderTrailingEdge*>(this), m_uidMgr);
        return *m_airfoil;
    }

    void CPACSControlSurfaceBorderTrailingEdge::RemoveAirfoil()
    {
        m_airfoil = boost::none;
    }

} // namespace generated
} // namespace tigl
