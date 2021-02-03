//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_OPERATIONS_H_INCLUDED
#define VECPP_VEC_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/scalar/functions.h"
#include "vecpp/vec/vec.h"

#include <algorithm>

namespace VECPP_NAMESPACE {

// Cross product
template <typename T>
constexpr Vec<T, 3> cross(const Vec<T, 3>& lhs,
                                  const Vec<T, 3>& rhs) {
  return {lhs[1] * rhs[2] - lhs[2] * rhs[1], lhs[2] * rhs[0] - lhs[0] * rhs[2],
          lhs[0] * rhs[1] - lhs[1] * rhs[0]};
}

// Dot product
template <typename T, std::size_t l>
constexpr T dot(const Vec<T, l>& lhs, const Vec<T, l>& rhs) {
  T result = 0;

  for (std::size_t i = 0; i < lhs.length; ++i) {
    result += lhs[i] * rhs[i];
  }

  return result;
}

// Vector legnth
template <typename T, std::size_t l>
constexpr T norm(const Vec<T, l>& v) {
  return square_root(dot(v, v));
}

// Normalize
template <typename T, std::size_t l>
constexpr Vec<T, l> normalize(const Vec<T, l>& v) {
  return v / norm(v);
}

}  // namespace VECPP_NAMESPACE
#endif