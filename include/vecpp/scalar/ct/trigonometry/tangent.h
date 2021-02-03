//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED
#define CSTE_MATH_TRIGNOMETRY_TANGENT_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/scalar/ct/trigonometry/cosine.h"
#include "vecpp/scalar/ct/trigonometry/sine.h"


namespace VECPP_NAMESPACE {
namespace ct {
//
template <typename T>
constexpr T tangent(const T& rad) {
  return sine(rad) / cosine(rad);
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif