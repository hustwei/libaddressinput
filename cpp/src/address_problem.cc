// Copyright (C) 2014 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <libaddressinput/address_problem.h>

#include <libaddressinput/util/basictypes.h>

#include <cstddef>
#include <ostream>

using i18n::addressinput::AddressProblem;
using i18n::addressinput::UNEXPECTED_FIELD;
using i18n::addressinput::USES_P_O_BOX;

std::ostream& operator<<(std::ostream& o, AddressProblem problem) {
  static const char* const kProblemNames[] = {
    "UNEXPECTED_FIELD",
    "MISSING_REQUIRED_FIELD",
    "UNKNOWN_VALUE",
    "INVALID_FORMAT",
    "MISMATCHING_VALUE",
    "USES_P_O_BOX"
  };
  COMPILE_ASSERT(UNEXPECTED_FIELD == 0, bad_base);
  COMPILE_ASSERT(USES_P_O_BOX == arraysize(kProblemNames) - 1, bad_length);

  if (problem < 0 || static_cast<size_t>(problem) >= arraysize(kProblemNames)) {
    o << "[INVALID ENUM VALUE " << static_cast<int>(problem) << "]";
  } else {
    o << kProblemNames[problem];
  }
  return o;
}
