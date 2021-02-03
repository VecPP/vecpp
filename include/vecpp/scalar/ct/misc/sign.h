//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef CSTE_MATH_MISC_SIGN_H_INCLUDED
#define CSTE_MATH_MISC_SIGN_H_INCLUDED

#include "vecpp/cste_math/config.h"

namespace CSTE_MATH_NAMESPACE {
namespace ct{
template <typename T>
constexpr T sign(const T& v) {
  // https://stackoverflow.com/a/4609795/4442671
  return T((T(0) < v) - (v < T(0)));
}
}  // namespace ct
}  // namespace CSTE_MATH_NAMESPACE

#endif