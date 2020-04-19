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

#include <boost/optional.hpp>
#include <boost/utility/in_place_factory.hpp>
#include <string>
#include <tixi.h>
#include "CTiglUIDObject.h"
#include "ITiglUIDRefObject.h"
#include "tigl_internal.h"

namespace tigl
{
class CTiglUIDManager;
class CCPACSPositionings;

namespace generated
{
    // This class is used in:
    // CPACSPositionings

    // generated from /xsd:schema/xsd:complexType[736]
    /// @brief Positioning of the wing section
    /// 
    /// The positionings describe an additional translation of
    /// sections. Basically, the positioning is a vector having the
    /// length 'length' and an orientation that is described by the
    /// parameters 'sweepAngle' and 'dihedralAngle'. If the 'sweepAngle'
    /// and the 'dihedralAngle' are set to zero (or left blank) the
    /// positioning vector equals the positive y-axis of the coordinate
    /// system (in case of a positive 'length').
    /// If the parameter 'fromSectionUID' is set, the
    /// positioning describes the translation between the 'from' towards
    /// the 'to' section. If the parameter 'fromSectionUID' is left
    /// blank the orgin of the positioning vector is the origin of the
    /// parent coordinate syste.
    /// The orgin of the section coordinate system is the
    /// position which is described by the positioning vector PLUS the
    /// translation which is described in the section.
    /// Please note: If the orgin of the positioning vector is
    /// defined by using another section, i.e. fromSection is defined,
    /// the orgin of this vector equals the end of the positioning
    /// vector of the previous section. This means that the section
    /// translation of the from-section has no influence on the
    /// positioning of the to-section. Therefore the total translation,
    /// which is described by positionings, is the sum of the current
    /// positioning and all positionings that are defined 'before'.
    /// An example for this is given at positioning 3 and 4 at
    /// the picture below. Please note, that any other combination of
    /// positionings would be possible.
    /// Application of the sweepangle does not lead to a
    /// rotation of the section. Application of the dihedral does not
    /// lead to a rotation of the section.
    /// @see wingpositionings
    /// 
    class CPACSPositioning : public CTiglReqUIDObject, public ITiglUIDRefObject
    {
    public:
        TIGL_EXPORT CPACSPositioning(CCPACSPositionings* parent, CTiglUIDManager* uidMgr);

        TIGL_EXPORT virtual ~CPACSPositioning();

        TIGL_EXPORT CCPACSPositionings* GetParent();

        TIGL_EXPORT const CCPACSPositionings* GetParent() const;

        TIGL_EXPORT virtual CTiglUIDObject* GetNextUIDParent();
        TIGL_EXPORT virtual const CTiglUIDObject* GetNextUIDParent() const;

        TIGL_EXPORT CTiglUIDManager& GetUIDManager();
        TIGL_EXPORT const CTiglUIDManager& GetUIDManager() const;

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const std::string& GetUID() const;
        TIGL_EXPORT virtual void SetUID(const std::string& value);

        TIGL_EXPORT virtual const std::string& GetName() const;
        TIGL_EXPORT virtual void SetName(const std::string& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetDescription() const;
        TIGL_EXPORT virtual void SetDescription(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const double& GetLength() const;
        TIGL_EXPORT virtual void SetLength(const double& value);

        TIGL_EXPORT virtual const double& GetSweepAngle() const;
        TIGL_EXPORT virtual void SetSweepAngle(const double& value);

        TIGL_EXPORT virtual const double& GetDihedralAngle() const;
        TIGL_EXPORT virtual void SetDihedralAngle(const double& value);

        TIGL_EXPORT virtual const boost::optional<std::string>& GetFromSectionUID() const;
        TIGL_EXPORT virtual void SetFromSectionUID(const boost::optional<std::string>& value);

        TIGL_EXPORT virtual const std::string& GetToSectionUID() const;
        TIGL_EXPORT virtual void SetToSectionUID(const std::string& value);

    protected:
        CCPACSPositionings* m_parent;

        CTiglUIDManager* m_uidMgr;

        std::string                  m_uID;

        /// Name of the positioning.
        std::string                  m_name;

        /// Description of the positioning.
        boost::optional<std::string> m_description;

        /// Distance between inner and outer section
        /// (length of the positioning vector).
        double                       m_length;

        /// Sweepangle between inner and outer section.
        /// This angle equals a positive rotation of the positioing vector
        /// around the z-axis of the wing coordinate system.
        double                       m_sweepAngle;

        /// Dihedralangle between inner and outer section.
        /// This angle equals a positive rotation of the positioing vector
        /// around the x-axis of the wing coordinate system
        double                       m_dihedralAngle;

        /// Reference to starting section of the
        /// positioning vector. If missing, the positioning is made from the
        /// orgin of the wing coordinate system.
        boost::optional<std::string> m_fromSectionUID;

        /// Reference to ending section (section to be
        /// positioned) of the positioning vector.
        std::string                  m_toSectionUID;

    private:
        TIGL_EXPORT const CTiglUIDObject* GetNextUIDObject() const final;
        TIGL_EXPORT void NotifyUIDChange(const std::string& oldUid, const std::string& newUid) final;

        CPACSPositioning(const CPACSPositioning&) = delete;
        CPACSPositioning& operator=(const CPACSPositioning&) = delete;

        CPACSPositioning(CPACSPositioning&&) = delete;
        CPACSPositioning& operator=(CPACSPositioning&&) = delete;
    };
} // namespace generated

// CPACSPositioning is customized, use type CCPACSPositioning directly
} // namespace tigl
