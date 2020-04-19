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
#include "CCPACSTrailingEdgeDevice.h"
#include "CPACSControlSurfaceWingCutOut.h"
#include "CTiglError.h"
#include "CTiglLogging.h"
#include "CTiglUIDManager.h"
#include "CTiglUIDObject.h"
#include "TixiHelper.h"

namespace tigl
{
namespace generated
{
    CPACSControlSurfaceWingCutOut::CPACSControlSurfaceWingCutOut(CCPACSTrailingEdgeDevice* parent, CTiglUIDManager* uidMgr)
        : m_uidMgr(uidMgr)
        , m_upperSkin(this, m_uidMgr)
        , m_lowerSkin(this, m_uidMgr)
    {
        //assert(parent != NULL);
        m_parent = parent;
    }

    CPACSControlSurfaceWingCutOut::~CPACSControlSurfaceWingCutOut()
    {
    }

    const CCPACSTrailingEdgeDevice* CPACSControlSurfaceWingCutOut::GetParent() const
    {
        return m_parent;
    }

    CCPACSTrailingEdgeDevice* CPACSControlSurfaceWingCutOut::GetParent()
    {
        return m_parent;
    }

    const CTiglUIDObject* CPACSControlSurfaceWingCutOut::GetNextUIDParent() const
    {
        return m_parent;
    }

    CTiglUIDObject* CPACSControlSurfaceWingCutOut::GetNextUIDParent()
    {
        return m_parent;
    }

    CTiglUIDManager& CPACSControlSurfaceWingCutOut::GetUIDManager()
    {
        return *m_uidMgr;
    }

    const CTiglUIDManager& CPACSControlSurfaceWingCutOut::GetUIDManager() const
    {
        return *m_uidMgr;
    }

    void CPACSControlSurfaceWingCutOut::ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath)
    {
        // read element upperSkin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/upperSkin")) {
            m_upperSkin.ReadCPACS(tixiHandle, xpath + "/upperSkin");
        }
        else {
            LOG(ERROR) << "Required element upperSkin is missing at xpath " << xpath;
        }

        // read element lowerSkin
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/lowerSkin")) {
            m_lowerSkin.ReadCPACS(tixiHandle, xpath + "/lowerSkin");
        }
        else {
            LOG(ERROR) << "Required element lowerSkin is missing at xpath " << xpath;
        }

        // read element cutOutProfileControlPoint
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cutOutProfileControlPoint")) {
            m_cutOutProfileControlPoint = boost::in_place(this);
            try {
                m_cutOutProfileControlPoint->ReadCPACS(tixiHandle, xpath + "/cutOutProfileControlPoint");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cutOutProfileControlPoint at xpath " << xpath << ": " << e.what();
                m_cutOutProfileControlPoint = boost::none;
            }
        }

        // read element cutOutProfiles
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/cutOutProfiles")) {
            m_cutOutProfiles = boost::in_place(this, m_uidMgr);
            try {
                m_cutOutProfiles->ReadCPACS(tixiHandle, xpath + "/cutOutProfiles");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read cutOutProfiles at xpath " << xpath << ": " << e.what();
                m_cutOutProfiles = boost::none;
            }
        }

        // read element innerBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerBorder")) {
            m_innerBorder = boost::in_place(this, m_uidMgr);
            try {
                m_innerBorder->ReadCPACS(tixiHandle, xpath + "/innerBorder");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read innerBorder at xpath " << xpath << ": " << e.what();
                m_innerBorder = boost::none;
            }
        }

        // read element outerBorder
        if (tixi::TixiCheckElement(tixiHandle, xpath + "/outerBorder")) {
            m_outerBorder = boost::in_place(this, m_uidMgr);
            try {
                m_outerBorder->ReadCPACS(tixiHandle, xpath + "/outerBorder");
            } catch(const std::exception& e) {
                LOG(ERROR) << "Failed to read outerBorder at xpath " << xpath << ": " << e.what();
                m_outerBorder = boost::none;
            }
        }

    }

    void CPACSControlSurfaceWingCutOut::WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const
    {
        const std::vector<std::string> childElemOrder = { "upperSkin", "lowerSkin", "cutOutProfileControlPoint", "cutOutProfiles", "innerBorder", "outerBorder" };

        // write element upperSkin
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/upperSkin", childElemOrder);
        m_upperSkin.WriteCPACS(tixiHandle, xpath + "/upperSkin");

        // write element lowerSkin
        tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/lowerSkin", childElemOrder);
        m_lowerSkin.WriteCPACS(tixiHandle, xpath + "/lowerSkin");

        // write element cutOutProfileControlPoint
        if (m_cutOutProfileControlPoint) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/cutOutProfileControlPoint", childElemOrder);
            m_cutOutProfileControlPoint->WriteCPACS(tixiHandle, xpath + "/cutOutProfileControlPoint");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cutOutProfileControlPoint")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cutOutProfileControlPoint");
            }
        }

        // write element cutOutProfiles
        if (m_cutOutProfiles) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/cutOutProfiles", childElemOrder);
            m_cutOutProfiles->WriteCPACS(tixiHandle, xpath + "/cutOutProfiles");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/cutOutProfiles")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/cutOutProfiles");
            }
        }

        // write element innerBorder
        if (m_innerBorder) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/innerBorder", childElemOrder);
            m_innerBorder->WriteCPACS(tixiHandle, xpath + "/innerBorder");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/innerBorder")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/innerBorder");
            }
        }

        // write element outerBorder
        if (m_outerBorder) {
            tixi::TixiCreateSequenceElementIfNotExists(tixiHandle, xpath + "/outerBorder", childElemOrder);
            m_outerBorder->WriteCPACS(tixiHandle, xpath + "/outerBorder");
        }
        else {
            if (tixi::TixiCheckElement(tixiHandle, xpath + "/outerBorder")) {
                tixi::TixiRemoveElement(tixiHandle, xpath + "/outerBorder");
            }
        }

    }

    const CCPACSControlSurfaceSkinCutout& CPACSControlSurfaceWingCutOut::GetUpperSkin() const
    {
        return m_upperSkin;
    }

    CCPACSControlSurfaceSkinCutout& CPACSControlSurfaceWingCutOut::GetUpperSkin()
    {
        return m_upperSkin;
    }

    const CCPACSControlSurfaceSkinCutout& CPACSControlSurfaceWingCutOut::GetLowerSkin() const
    {
        return m_lowerSkin;
    }

    CCPACSControlSurfaceSkinCutout& CPACSControlSurfaceWingCutOut::GetLowerSkin()
    {
        return m_lowerSkin;
    }

    const boost::optional<CPACSCutOutControlPoints>& CPACSControlSurfaceWingCutOut::GetCutOutProfileControlPoint() const
    {
        return m_cutOutProfileControlPoint;
    }

    boost::optional<CPACSCutOutControlPoints>& CPACSControlSurfaceWingCutOut::GetCutOutProfileControlPoint()
    {
        return m_cutOutProfileControlPoint;
    }

    const boost::optional<CPACSCutOutProfiles>& CPACSControlSurfaceWingCutOut::GetCutOutProfiles() const
    {
        return m_cutOutProfiles;
    }

    boost::optional<CPACSCutOutProfiles>& CPACSControlSurfaceWingCutOut::GetCutOutProfiles()
    {
        return m_cutOutProfiles;
    }

    const boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& CPACSControlSurfaceWingCutOut::GetInnerBorder() const
    {
        return m_innerBorder;
    }

    boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& CPACSControlSurfaceWingCutOut::GetInnerBorder()
    {
        return m_innerBorder;
    }

    const boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& CPACSControlSurfaceWingCutOut::GetOuterBorder() const
    {
        return m_outerBorder;
    }

    boost::optional<CCPACSControlSurfaceSkinCutOutBorder>& CPACSControlSurfaceWingCutOut::GetOuterBorder()
    {
        return m_outerBorder;
    }

    CPACSCutOutControlPoints& CPACSControlSurfaceWingCutOut::GetCutOutProfileControlPoint(CreateIfNotExistsTag)
    {
        if (!m_cutOutProfileControlPoint)
            m_cutOutProfileControlPoint = boost::in_place(this);
        return *m_cutOutProfileControlPoint;
    }

    void CPACSControlSurfaceWingCutOut::RemoveCutOutProfileControlPoint()
    {
        m_cutOutProfileControlPoint = boost::none;
    }

    CPACSCutOutProfiles& CPACSControlSurfaceWingCutOut::GetCutOutProfiles(CreateIfNotExistsTag)
    {
        if (!m_cutOutProfiles)
            m_cutOutProfiles = boost::in_place(this, m_uidMgr);
        return *m_cutOutProfiles;
    }

    void CPACSControlSurfaceWingCutOut::RemoveCutOutProfiles()
    {
        m_cutOutProfiles = boost::none;
    }

    CCPACSControlSurfaceSkinCutOutBorder& CPACSControlSurfaceWingCutOut::GetInnerBorder(CreateIfNotExistsTag)
    {
        if (!m_innerBorder)
            m_innerBorder = boost::in_place(this, m_uidMgr);
        return *m_innerBorder;
    }

    void CPACSControlSurfaceWingCutOut::RemoveInnerBorder()
    {
        m_innerBorder = boost::none;
    }

    CCPACSControlSurfaceSkinCutOutBorder& CPACSControlSurfaceWingCutOut::GetOuterBorder(CreateIfNotExistsTag)
    {
        if (!m_outerBorder)
            m_outerBorder = boost::in_place(this, m_uidMgr);
        return *m_outerBorder;
    }

    void CPACSControlSurfaceWingCutOut::RemoveOuterBorder()
    {
        m_outerBorder = boost::none;
    }

} // namespace generated
} // namespace tigl
