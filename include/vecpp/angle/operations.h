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
template <typename T>
constexpr T sine(const Angle<T>& a) {
  return cste::sine(a.as_rad());
}

template <typename T>
constexpr T cosine(const Angle<T>& a) {
  return cste::cosine(a.as_rad());
}

template <typename T>
constexpr T tangent(const Angle<T>& a) {
  return cste::tangent(a.as_rad());
}

}  // namespace VECPP_NAMESPACE

#endif
