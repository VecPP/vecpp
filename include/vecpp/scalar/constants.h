//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_CONSTANTS_H_INCLUDED
#define VECPP_SCALAR_CONSTANTS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/cste_math/constants.h"

namespace VECPP_NAMESPACE {

// Constants are defined with enough precision for a Quadruple precision float
// which means at least 36 decimal digits.

template <typename T>
constexpr T pi = cste::pi<T>;

template <typename T>
constexpr T half_pi = cste::half_pi<T>;

template <typename T>
constexpr T quarter_pi = cste::quarter_pi<T>;

template <typename T>
constexpr T two_pi = cste::two_pi<T>;

}  // namespace CSTE_MATH_NAMESPACE
#endif