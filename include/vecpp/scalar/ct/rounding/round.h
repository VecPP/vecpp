//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_ROUND_H_INCLUDED
#define CSTE_MATH_ROUND_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/ct/rounding/round_down.h"

namespace CSTE_MATH_NAMESPACE {
namespace ct {
template <typename T>
constexpr T round(const T& v) {
  return round_down(v + T(0.5));
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif