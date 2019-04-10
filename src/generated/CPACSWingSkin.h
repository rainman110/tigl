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

#include <CCPACSMaterialDefinition.h>
#include <string>
#include <tixi.h>
#include <typeinfo>
#include "CTiglError.h"
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSWingCell
    // CPACSWingShell

    // generated from /xsd:schema/xsd:complexType[977]
    /// @brief Material properties of the wing skin.
    /// 
    /// The wingSkinType describes the material properties of
    /// the wing.
    /// For composites materials: the positive z-direction is
    /// from the outer side to the inner side.
    /// For composites materials: the reference axis for the
    /// orthotropyDirection is defined by the two leading edge points of
    /// the 'from'- and the 'to'-element of the componentSegment
    /// definition. The angle between the reference axis and the
    /// orthotropyDirection equals the rotation around the z-reference
    /// axis. For details, please refer to the picture below:
    /// @see wingskinorthotropydir
    /// 
    class CPACSWingSkin
    {
    public:
        TIGL_EXPORT CPACSWingSkin();
        TIGL_EXPORT virtual ~CPACSWingSkin();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSMaterialDefinition& GetMaterial() const;
        TIGL_EXPORT virtual CCPACSMaterialDefinition& GetMaterial();

    protected:
        /// Material properties of the wing skin.
        CCPACSMaterialDefinition m_material;

    private:
        CPACSWingSkin(const CPACSWingSkin&) = delete;
        CPACSWingSkin& operator=(const CPACSWingSkin&) = delete;

        CPACSWingSkin(CPACSWingSkin&&) = delete;
        CPACSWingSkin& operator=(CPACSWingSkin&&) = delete;
    };
} // namespace generated

// Aliases in tigl namespace
using CCPACSWingSkin = generated::CPACSWingSkin;
} // namespace tigl
