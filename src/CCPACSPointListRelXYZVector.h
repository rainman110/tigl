/*
* Copyright (c) 2018 RISC Software GmbH
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/


#pragma once

#include <vector>

#include "generated/CPACSPointListRelXYZVector.h"
#include "CTiglPoint.h"

namespace tigl
{

class CCPACSPointListRelXYZVector : public generated::CPACSPointListRelXYZVector
{
public:
    TIGL_EXPORT CCPACSPointListRelXYZVector(CCPACSGuideCurveProfile* parent);

    TIGL_EXPORT void ReadCPACS(const TixiDocumentHandle& tixiHandle, const std::string& xpath) override;

    TIGL_EXPORT const std::vector<CTiglPoint>& AsVector() const;
    TIGL_EXPORT void SetAsVector(const std::vector<CTiglPoint>& points);

private:
    // cache
    std::vector<CTiglPoint> m_vec;
};

} // namespace tigl
