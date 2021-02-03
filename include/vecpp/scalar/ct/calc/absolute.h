//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_CT_BOUNDING_ABSOLUTE_H_INCLUDED
#define VECPP_CT_BOUNDING_ABSOLUTE_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE::ct {

template <typename T>
constexpr T absolute(const T& v) {
  return v < 0 ? -v : v;
}
}  // namespace CSTE_MATH_NAMESPACE

#endif
