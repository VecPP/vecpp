//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_CT_CALC_POW_H_INCLUDED
#define VECPP_SCALAR_CT_CALC_POW_H_INCLUDED

#include "vecpp/config.h"

#include <cassert>
#include <cmath>
#include <limits>

namespace VECPP_NAMESPACE::ct {

// Raises v by the operand p
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  if constexpr (std::is_integral<U>()) {
    T result = 1;
    for (U i = 0; i < p; ++i) {
      result *= v;
    }
    return result;
  } else {
    assert(false);
    return v;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

#endif
