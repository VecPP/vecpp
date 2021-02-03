//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_TRUNCATE_H_INCLUDED
#define CSTE_MATH_TRUNCATE_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/ct/calc/power.h"
#include "vecpp/cste_math/ct/misc/inf_nan.h"

#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {
namespace ct {
template <typename T>
constexpr T truncate(const T& v) {
  long long int x = static_cast<long long int>(v);
  return T(x);
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif