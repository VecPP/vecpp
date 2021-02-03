//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)


#ifndef CSTE_CONSTANTS_H_INCLUDED
#define CSTE_CONSTANTS_H_INCLUDED

#include "vecpp/cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {

// Constants are defined with enough precision for a Quadruple precision float
// which means at least 36 decimal digits.

template <typename T>
constexpr T pi = T(3.14159265358979323846264338327950288419L);

template <typename T>
constexpr T half_pi = pi<T> / T(2);

template <typename T>
constexpr T quarter_pi = pi<T> / T(4);

template <typename T>
constexpr T two_pi = pi<T>* T(2);

template <typename T>
constexpr T e = T(2.71828182845904523536028747135266249775724709L);

}  // namespace CSTE_MATH_NAMESPACE
#endif