//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_CALC_EXP_H_INCLUDED
#define CSTE_MATH_CALC_EXP_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/constants.h"
#include "vecpp/cste_math/ct/rounding/round_down.h"

#include <cassert>
#include <cmath>
#include <limits>
#include <cstdint>

namespace CSTE_MATH_NAMESPACE {
namespace ct {
namespace exp_details {
// e^x = 1 + x + x^2/2! + x^3/3! + ...

// But! we add the terms from the smallest to the largest in order
// to maximize precision
constexpr long double recur_helper(long double x, long double num,
                                   long double fact, std::size_t i) {
  fact *= i;
  num *= x;
  long double factor = num / fact;

  if (factor == 0.0L) {
    return 0.0L;
  }

  return factor + recur_helper(x, num, fact, i + 1);
}
}  // namespace exp_details
// Raises e by the operand
template <typename T>
constexpr T exponential(const T& v) {
  long double v_p = v;
  bool neg = v < 0;
  if (neg) {
    v_p = -v_p;
  }

  // separate integral and fractional components
  std::uint64_t integral = std::uint64_t(round_down(v_p));
  long double fract = v_p - integral;

  long double int_val = 1;
  long double e_fact = e<long double>;
  while (integral != 0) {
    if (integral & 1) {
      int_val *= e_fact;
    }

    integral >>= 1;
    e_fact *= e<long double>;
  }

  long double fract_val = exp_details::recur_helper(fract, 1, 1, 1) + 1.0L;

  long double result = fract_val * int_val;
  return T(neg ? 1.0L / result : result);
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif
