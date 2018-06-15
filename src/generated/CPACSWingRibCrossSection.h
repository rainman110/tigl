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

#pragma once

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <CCPACSMaterialDefinition.h>
#include <string>
#include <tixi.h>
#include "CPACSCap.h"
#include "CPACSPointX.h"
#include "CPACSWingRibCell.h"
#include "CreateIfNotExists.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSWingRibsDefinition;

namespace generated
{
    // This class is used in:
    // CPACSWingRibsDefinition

    // generated from /xsd:schema/xsd:complexType[945]
    class CPACSWingRibCrossSection
    {
    public:
        TIGL_EXPORT CPACSWingRibCrossSection(CCPACSWingRibsDefinition* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSWingRibCrossSection();

        TIGL_EXPORT CCPACSWingRibsDefinition* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSMaterialDefinition& GetMaterial() const;
        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetMaterial();

        TIGL_EXPORT virtual const boost::optional<CPACSPointX>& GetRibRotation() const;
        TIGL_EXPORT virtual boost::optional<CPACSPointX>& GetRibRotation();

        TIGL_EXPORT virtual const boost::optional<CPACSWingRibCell>& GetRibCell() const;
        TIGL_EXPORT virtual boost::optional<CPACSWingRibCell>& GetRibCell();

        TIGL_EXPORT virtual const boost::optional<CPACSCap>& GetUpperCap() const;
        TIGL_EXPORT virtual boost::optional<CPACSCap>& GetUpperCap();

        TIGL_EXPORT virtual const boost::optional<CPACSCap>& GetLowerCap() const;
        TIGL_EXPORT virtual boost::optional<CPACSCap>& GetLowerCap();

        TIGL_EXPORT virtual CPACSPointX& GetRibRotation(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibRotation();

        TIGL_EXPORT virtual CPACSWingRibCell& GetRibCell(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveRibCell();

        TIGL_EXPORT virtual CPACSCap& GetUpperCap(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveUpperCap();

        TIGL_EXPORT virtual CPACSCap& GetLowerCap(CreateIfNotExistsTag);
        TIGL_EXPORT virtual void RemoveLowerCap();

    protected:
        CCPACSWingRibsDefinition* m_parent;

        CTiglUIDManager* m_uidMgr;

        CCPACSMaterialDefinition          m_material;
        boost::optional<CPACSPointX>      m_ribRotation;
        boost::optional<CPACSWingRibCell> m_ribCell;
        boost::optional<CPACSCap>         m_upperCap;
        boost::optional<CPACSCap>         m_lowerCap;

    private:
#ifdef HAVE_CPP11
        CPACSWingRibCrossSection(const CPACSWingRibCrossSection&) = delete;
        CPACSWingRibCrossSection& operator=(const CPACSWingRibCrossSection&) = delete;

        CPACSWingRibCrossSection(CPACSWingRibCrossSection&&) = delete;
        CPACSWingRibCrossSection& operator=(CPACSWingRibCrossSection&&) = delete;
#else
        CPACSWingRibCrossSection(const CPACSWingRibCrossSection&);
        CPACSWingRibCrossSection& operator=(const CPACSWingRibCrossSection&);
#endif
    };
} // namespace generated

// CPACSWingRibCrossSection is customized, use type CCPACSWingRibCrossSection directly
} // namespace tigl