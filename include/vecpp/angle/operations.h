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
  if constexpr(is_ct(f)) {
    constexpr std::array<T, 5> taylor_factors = {
      -6, 120, -5040, 362880, -39916800
    };

    T r = a.as_rad();
    T r_2 = r*r;

    T result = r;

    for(auto factor : taylor_factors) {
      r *= r_2;
      result += r / factor;
    }

    return result;
  }
  else {
    return non_cste::sin(a.as_rad());
  }
}

template <typename T, Flags f>
constexpr T cos(const Angle<T, f>& a) {
  if constexpr(is_ct(f)) {
    return sin(a + Angle<T, f>::from_rad(half_pi<T>)); 
  }
  else {
    return non_cste::cos(a.as_rad());
  }
}

template <typename T, Flags f>
constexpr T tan(const Angle<T, f>& a) {
  if constexpr(is_ct(f)) {
    return sin(a) / cos(a); 
  }
  else {
    return non_cste::tan(a.as_rad());
  }
}

}

#endif
