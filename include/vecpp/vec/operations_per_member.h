//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_OPERATIONS_PER_MEMBER_H_INCLUDED
#define VECPP_VEC_OPERATIONS_PER_MEMBER_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/scalar/operations.h"
#include "vecpp/vec/vec.h"

#include <algorithm>

namespace VECPP_NAMESPACE {
// abs
template <typename T, std::size_t L>
constexpr Vec<T, L> abs(const Vec<T, L>& vec) {
  Vec<T, L> result = {0};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = abs(vec[i]);
  }
  return result;
}

// max
template <typename T, std::size_t L>
constexpr Vec<T, L> max(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = {0};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = std::max(lhs[i], rhs[i]);
  }
  return result;
}

// min
template <typename T, std::size_t L>
constexpr Vec<T, L> min(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = {0};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = std::min(lhs[i], rhs[i]);
  }
  return result;
}
}
#endif