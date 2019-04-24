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
#include <string>
#include <tixi.h>
#include "CPACSDoorAssemblyPosition_doorType.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;

namespace generated
{
    class CPACSCargoDoorsAssembly;

    // This class is used in:
    // CPACSCargoDoorsAssembly

    // generated from /xsd:schema/xsd:complexType[289]
    /// @brief doorAssemblyPositionType
    /// 
    /// DoorAssemblyPosition type, containing the position of a door
    /// assembly
    /// 
    class CPACSDoorAssemblyPosition
    {
    public:
        TIGL_EXPORT CPACSDoorAssemblyPosition(CPACSCargoDoorsAssembly* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSDoorAssemblyPosition();

        TIGL_EXPORT CPACSCargoDoorsAssembly* GetParent();

        TIGL_EXPORT const CPACSCargoDoorsAssembly* GetParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetName() const;
        TIGL_EXPORT virtual void SetName(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const boost::optional<CPACSDoorAssemblyPosition_doorType>& GetDoorType() const;
        TIGL_EXPORT virtual void SetDoorType(const boost::optional<CPACSDoorAssemblyPosition_doorType>& value);

        TIGL_EXPORT virtual const std::string& GetDoorElementUID() const;
        TIGL_EXPORT virtual void SetDoorElementUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStartFrameUID() const;
        TIGL_EXPORT virtual void SetStartFrameUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetEndFrameUID() const;
        TIGL_EXPORT virtual void SetEndFrameUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetStartStringerUID() const;
        TIGL_EXPORT virtual void SetStartStringerUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetEndStringerUID() const;
        TIGL_EXPORT virtual void SetEndStringerUID(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetZBase() const;
        TIGL_EXPORT virtual void SetZBase(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetMinWidth() const;
        TIGL_EXPORT virtual void SetMinWidth(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<double>& GetMinHeight() const;
        TIGL_EXPORT virtual void SetMinHeight(const boost::optional<double>& value);

        TIGL_EXPORT virtual const boost::optional<int>& GetYSign() const;
        TIGL_EXPORT virtual void SetYSign(const boost::optional<int>& value);

    protected:
        CPACSCargoDoorsAssembly* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                                         m_uID;

        boost::optional<std::string>                        m_name;

        boost::optional<std::string>                        m_description;

        /// optional definition of door type (restricted to pax,
        /// service, emergency, cargo)
        boost::optional<CPACSDoorAssemblyPosition_doorType> m_doorType;

        /// UID of the door element
        /// description
        std::string                                         m_doorElementUID;

        /// UID of the forward door frame
        std::string                                         m_startFrameUID;

        /// UID of the backward door frame
        std::string                                         m_endFrameUID;

        /// UID of the stringer at the upper door
        /// edge
        std::string                                         m_startStringerUID;

        /// UID of the stringer at the lower door
        /// edge
        std::string                                         m_endStringerUID;

        /// Lower height of the door with respect to the floor.
        /// (Information necessary for boarding and evacuation analysis not
        /// necessarily linked to structures)
        boost::optional<double>                             m_zBase;

        /// Minimum widh of the door element. (Information
        /// necessary for boarding and evacuation analysis not necessarily
        /// linked to structures)
        boost::optional<double>                             m_minWidth;

        /// Minimum height of the door element. (Information
        /// necessary for boarding and evacuation analysis not necessarily
        /// linked to structures)
        boost::optional<double>                             m_minHeight;

        /// Door on right side of the fuselage = 1; on the left =
        /// -1. (Information necessary for boarding and evacuation analysis not
        /// necessarily linked to structures)
        boost::optional<int>                                m_ySign;

    private:
        CPACSDoorAssemblyPosition(const CPACSDoorAssemblyPosition&) = delete;
        CPACSDoorAssemblyPosition& operator=(const CPACSDoorAssemblyPosition&) = delete;

        CPACSDoorAssemblyPosition(CPACSDoorAssemblyPosition&&) = delete;
        CPACSDoorAssemblyPosition& operator=(CPACSDoorAssemblyPosition&&) = delete;
    };
} // namespace generated

// CPACSDoorAssemblyPosition is customized, use type CCPACSDoorAssemblyPosition directly

// Aliases in tigl namespace
using CCPACSCargoDoorsAssembly = generated::CPACSCargoDoorsAssembly;
} // namespace tigl
