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
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSCFDTool

    // generated from /xsd:schema/xsd:complexType[874]
    /// @brief Tool identification
    /// 
    /// Tool identification, containing name and version of a
    /// tool
    /// 
    class CPACSTool
    {
    public:
        TIGL_EXPORT CPACSTool();
        TIGL_EXPORT virtual ~CPACSTool();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetVersion() const;
        TIGL_EXPORT virtual void SetVersion(const std::string& value);

    protected:
        /// Name of the tool
        std::string m_name;

        /// Version of the tool
        std::string m_version;

    private:
#ifdef HAVE_CPP11
        CPACSTool(const CPACSTool&) = delete;
        CPACSTool& operator=(const CPACSTool&) = delete;

        CPACSTool(CPACSTool&&) = delete;
        CPACSTool& operator=(CPACSTool&&) = delete;
#else
        CPACSTool(const CPACSTool&);
        CPACSTool& operator=(const CPACSTool&);
#endif
    };
} // namespace generated

// Aliases in tigl namespace
#ifdef HAVE_CPP11
using CCPACSTool = generated::CPACSTool;
#else
typedef generated::CPACSTool CCPACSTool;
#endif
} // namespace tigl
