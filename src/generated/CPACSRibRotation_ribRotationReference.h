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

#include <string>
#include <cctype>

#include "CTiglError.h"
#include "to_string.h"

namespace tigl
{
namespace generated
{
    // This enum is used in:
    // CPACSRibRotation

    // generated from /xsd:schema/xsd:complexType[770]/xsd:complexContent/xsd:extension/xsd:sequence/xsd:element[1]/xsd:complexType/xsd:simpleContent
    enum CPACSRibRotation_ribRotationReference
    {
        LeadingEdge,
        TrailingEdge,
        FrontSpar,
        RearSpar,
        globalX,
        globalY,
        globalZ
    };

    inline std::string CPACSRibRotation_ribRotationReferenceToString(const CPACSRibRotation_ribRotationReference& value)
    {
        switch(value) {
        case LeadingEdge: return "LeadingEdge";
        case TrailingEdge: return "TrailingEdge";
        case FrontSpar: return "FrontSpar";
        case RearSpar: return "RearSpar";
        case globalX: return "globalX";
        case globalY: return "globalY";
        case globalZ: return "globalZ";
        default: throw CTiglError("Invalid enum value \"" + std_to_string(static_cast<int>(value)) + "\" for enum type CPACSRibRotation_ribRotationReference");
        }
    }
    inline CPACSRibRotation_ribRotationReference stringToCPACSRibRotation_ribRotationReference(const std::string& value)
    {
        struct ToLower { std::string operator()(std::string str) { for (std::size_t i = 0; i < str.length(); i++) { str[i] = std::tolower(str[i]); } return str; } } toLower;
        if (toLower(value) == "leadingedge") { return LeadingEdge; }
        if (toLower(value) == "trailingedge") { return TrailingEdge; }
        if (toLower(value) == "frontspar") { return FrontSpar; }
        if (toLower(value) == "rearspar") { return RearSpar; }
        if (toLower(value) == "globalx") { return globalX; }
        if (toLower(value) == "globaly") { return globalY; }
        if (toLower(value) == "globalz") { return globalZ; }
        throw CTiglError("Invalid string value \"" + value + "\" for enum type CPACSRibRotation_ribRotationReference");
    }
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using ECPACSRibRotation_ribRotationReference = generated::CPACSRibRotation_ribRotationReference;
#else
typedef generated::CPACSRibRotation_ribRotationReference ECPACSRibRotation_ribRotationReference;
#endif
using generated::LeadingEdge;
using generated::TrailingEdge;
using generated::FrontSpar;
using generated::RearSpar;
using generated::globalX;
using generated::globalY;
using generated::globalZ;
} // namespace tigl
