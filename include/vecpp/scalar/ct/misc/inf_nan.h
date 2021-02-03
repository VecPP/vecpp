//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_MISC_NAN_H_INCLUDED
#define CSTE_MATH_MISC_NAN_H_INCLUDED

#include "vecpp/cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {
namespace ct {
template <typename T>
constexpr bool is_nan(const T& v) {
  return !(v == v);
}

template <typename T>
constexpr bool is_inf(const T& v) {
  constexpr T inf = std::numeric_limits<T>::infinity();
  return v == inf || v == -inf;
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif