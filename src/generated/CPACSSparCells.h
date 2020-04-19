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

#pragma once

#include <string>
#include <tixi.h>
#include <vector>
#include "tigl_internal.h"
#include "UniquePtr.h"

namespace tigl
{
class CTiglUIDManager;
class CTiglUIDObject;

namespace generated
{
    class CPACSSparCell;
    class CPACSSparCrossSection;

    // This class is used in:
    // CPACSSparCrossSection

    // generated from /xsd:schema/xsd:complexType[823]
    /// @brief SparCells of current spar.
    /// 
    /// sparCells are an optional Element. They are defined via
    /// the etaCoordinates and define a region of special cross section
    /// and material properties.
    /// 
    class CPACSSparCells
    {
    public:
        TIGL_EXPORT CPACSSparCells(CPACSSparCrossSection* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSSparCells();

        TIGL_EXPORT CPACSSparCrossSection* GetParent();

        TIGL_EXPORT const CPACSSparCrossSection* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::vector<std::unique_ptr<CPACSSparCell>>& GetSparCells() const;
        TIGL_EXPORT virtual std::vector<std::unique_ptr<CPACSSparCell>>& GetSparCells();

        TIGL_EXPORT virtual CPACSSparCell& AddSparCell();
        TIGL_EXPORT virtual void RemoveSparCell(CPACSSparCell& ref);

    protected:
        CPACSSparCrossSection* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::vector<std::unique_ptr<CPACSSparCell>> m_sparCells;

    private:
        CPACSSparCells(const CPACSSparCells&) = delete;
        CPACSSparCells& operator=(const CPACSSparCells&) = delete;

        CPACSSparCells(CPACSSparCells&&) = delete;
        CPACSSparCells& operator=(CPACSSparCells&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSSparCells = generated::CPACSSparCells;
using CCPACSSparCell = generated::CPACSSparCell;
using CCPACSSparCrossSection = generated::CPACSSparCrossSection;
} // namespace tigl
