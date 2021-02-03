//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_CALC_SQUARE_ROOT_H_INCLUDED
#define CSTE_MATH_CALC_SQUARE_ROOT_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include <cassert>
#include <cmath>
#include <limits>

namespace CSTE_MATH_NAMESPACE {
namespace ct {

template <typename T>
constexpr T square_root(const T& v) {
  assert(v >= T(0));

  if (v == T(0)) {
    return v;
  }

  T r = v;
  // A simple newton-rhapson for now.
  while (1) {
    T tmp = (r + v / r) / T(2);
    if (tmp == r) {
      break;
    }
    r = tmp;
  }

  return r;
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif
