//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_TRIGNOMETRY_COSINE_PI4_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_COSINE_PI4_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/constants.h"

#include <cassert>

namespace CSTE_MATH_NAMESPACE {

namespace cosine_detail {

// We have to do this recursively, because we want to collapse from the end
// to the start.
constexpr long double recur_helper(long double r_2, long double num,
                                   long double fact, std::size_t i) {
  if(i >= 160) {
    return 0;
  }

  fact *= (i - 1);
  fact *= (i);
  num *= r_2;

  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}  // namespace cosine_detail

// Evaluates cos(x) in the [-PI/4, PI/4] range
template <typename T>
constexpr T cosine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
  // Promote to long double
  long double r = rad;
  long double r_2 = r * r * -1.0;

  return cosine_detail::recur_helper(r_2, 1, 1.0L, 2) + 1.0L;
}
}  // namespace CSTE_MATH_NAMESPACE

#endif