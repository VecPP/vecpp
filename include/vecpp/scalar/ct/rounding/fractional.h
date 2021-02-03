//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_CT_FRACTIONAL_H_INCLUDED
#define VECPP_SCALAR_CT_FRACTIONAL_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/scalar/ct/rounding/round_down.h"

#include <type_traits>

namespace VECPP_NAMESPACE::ct {

template <typename T>
constexpr T fractional(const T& val) {
  return val - round_down(val);
}
}  // namespace CSTE_MATH_NAMESPACE

#endif