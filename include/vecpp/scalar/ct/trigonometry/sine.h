//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_TRIGNOMETRY_SINE_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_SINE_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/ct/calc/modulo.h"
#include "vecpp/cste_math/constants.h"
#include "vecpp/cste_math/ct/misc/inf_nan.h"
#include "vecpp/cste_math/ct/trigonometry/bound/cosine_pi4.h"
#include "vecpp/cste_math/ct/trigonometry/bound/sine_pi4.h"

#include <iomanip>
#include <iostream>
#include <limits>

namespace CSTE_MATH_NAMESPACE {
namespace ct {
//
template <typename T>
constexpr T sine(const T& rad) {
  if (is_nan(rad)) {
    return rad;
  }

  if (is_inf(rad)) {
    return std::numeric_limits<T>::signaling_NaN();
  }

  long double r = rad;

  // Remap into the -PI->PI range.
  if (r > pi<long double>) {
    r = modulo(r, two_pi<long double>);
  } else if (r < -pi<long double>) {
    r = modulo(r, -two_pi<long double>);
  }

  if (r > pi<long double>) {
    r -= two_pi<long double>;
  } else if (r < -pi<long double>) {
    r += two_pi<long double>;
  }

  // Remap into the -PI/2->PI/2 range.
  if (r > half_pi<long double>) {
    r = pi<T> - r;
  } else if (r < -half_pi<long double>) {
    r = -pi<T> - r;
  }

  if (r < -quarter_pi<long double>) {
    return T(-cosine_pi4(r + half_pi<long double>));
  } else if (r > quarter_pi<long double>) {
    return T(cosine_pi4(r - half_pi<long double>));
  }

  return T(sine_pi4(r));
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif