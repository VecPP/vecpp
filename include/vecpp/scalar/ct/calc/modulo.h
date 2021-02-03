//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_MODULO_H_INCLUDED
#define CSTE_MATH_MODULO_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/ct/rounding/round_down.h"

#include <type_traits>

namespace CSTE_MATH_NAMESPACE {
namespace ct {
template <typename T>
constexpr T modulo(const T& val, const T& div) {
  if constexpr (std::is_integral_v<T>) {
    return val % div;
  } else {
    return val - round_down(val / div) * div;
  }
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif