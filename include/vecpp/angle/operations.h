//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_ANGLE_OPERATIONS_H_INCLUDED
#define VECPP_ANGLE_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/angle/angle.h"

#include <cmath>

namespace VECPP_NAMESPACE {

// Trigonometry

// TODO: These placeholder taylor series expansion implementation
// are temporary, and need to be replaced with something better!
template <typename T, Flags f>
constexpr T sin(const Angle<T, f>& a) {
  if constexpr (is_ct(f)) {
    double r = a.as_rad();

    bool neg = false;

    if(r < 0.0) {
      r *= -1.0;
      neg = true;
    }

    if(r > half_pi<double>) {
      r = pi<double> - r;
    }

    double r_2 = r*r * -1.0;

    double result = r;

    for (std::size_t i = 3; i < 19; i+=2) {
      r *= r_2;
      result += r / factorial(i);
    }

    if(neg) {
      result *= -1.0;
    }
    return T(result);
  } else {
    return std::sin(a.as_rad());
  }
}

template <typename T, Flags f>
constexpr T cos(const Angle<T, f>& a) {
  if constexpr (is_ct(f)) {
    return sin(a + Angle<T, f>::from_rad(half_pi<T>));
  } else {
    return std::cos(a.as_rad());
  }
}

template <typename T, Flags f>
constexpr T tan(const Angle<T, f>& a) {
  if constexpr (is_ct(f)) {
    return sin(a) / cos(a);
  } else {
    return std::tan(a.as_rad());
  }
}

}  // namespace VECPP_NAMESPACE

#endif
