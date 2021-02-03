//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_ROUND_UP_H_INCLUDED
#define CSTE_MATH_ROUND_UP_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/ct/calc/power.h"
#include "vecpp/cste_math/ct/misc/inf_nan.h"

#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {
namespace ct {
template <typename T>
constexpr T round_up(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;

  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }

  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v < T(0)) {
    return T(x);
  }
  return T(x + 1);
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif
