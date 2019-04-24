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

#include <CCPACSStringVector.h>
#include <string>
#include <tixi.h>
#include "tigl_internal.h"

namespace tigl
{
namespace generated
{
    // This class is used in:
    // CPACSGuideCurveProfileGeometry

    // generated from /xsd:schema/xsd:complexType[718]
    /// @brief List of 3D points, kept in three relative coordinate
    /// vecors (rX, rY, rZ)
    /// 
    /// This set of vectors contains an ordered list of points
    /// for rX, rY, and rZ coordinates in the form of stringBased
    /// Vectors. The x, y and z vector elements with the same index
    /// specify a 3D point relative to a geometric segment.
    /// @see guideProfileWing
    /// @see guideProfileFuselage
    /// @see guideProfileLong
    /// 
    class CPACSPointListRelXYZVector
    {
    public:
        TIGL_EXPORT CPACSPointListRelXYZVector();
        TIGL_EXPORT virtual ~CPACSPointListRelXYZVector();

        TIGL_EXPORT virtual void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath);
        TIGL_EXPORT virtual void WriteCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) const;

        TIGL_EXPORT virtual const CCPACSStringVector& GetRX() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRX();

        TIGL_EXPORT virtual const CCPACSStringVector& GetRY() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRY();

        TIGL_EXPORT virtual const CCPACSStringVector& GetRZ() const;
        TIGL_EXPORT virtual CCPACSStringVector& GetRZ();

    protected:
        /// Vector of rX coordinates. Relative
        /// circumferential coordinate on wing / fuselage profile
        CCPACSStringVector m_rX;

        /// Vector of rY coordinates. Relative span
        /// coordinate along a segment
        CCPACSStringVector m_rY;

        /// Vector of rZ coordinates. Relative coordinate
        /// normal to the linear strake (normalised with chordlength /
        /// diameter c*)
        CCPACSStringVector m_rZ;

    private:
        CPACSPointListRelXYZVector(const CPACSPointListRelXYZVector&) = delete;
        CPACSPointListRelXYZVector& operator=(const CPACSPointListRelXYZVector&) = delete;

        CPACSPointListRelXYZVector(CPACSPointListRelXYZVector&&) = delete;
        CPACSPointListRelXYZVector& operator=(CPACSPointListRelXYZVector&&) = delete;
    };
} // namespace generated

// CPACSPointListRelXYZVector is customized, use type CCPACSPointListRelXYZVector directly
} // namespace tigl
