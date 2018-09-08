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

// *************** Unary functions *************** //

// abs
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> abs(const Vec<T, l, traits>& vec) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < vec.length; ++i) {
    result[i] = abs<traits>(vec[i]);
  }
  return result;
}

// ceil
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> ceil(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = ceil<traits>(v[i]);
  }
  return result;
}

// floor
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> floor(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = floor<traits>(v[i]);
  }
  return result;
}

// fract
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> fract(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = fract<traits>(v[i]);
  }
  return result;
}

// round
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> round(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = round<traits>(v[i]);
  }
  return result;
}

// sign
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> sign(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = sign<traits>(v[i]);
  }
  return result;
}

// trunc
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> trunc(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = trunc<traits>(v[i]);
  }
  return result;
}
// *************** Binary functions *************** //

// max
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> max(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = max(lhs[i], rhs[i]);
  }
  return result;
}

// min
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> min(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = min(lhs[i], rhs[i]);
  }
  return result;
}

// mod
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> mod(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = mod<traits>(lhs[i], rhs[i]);
  }
  return result;
}

// step
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> step(const Vec<T, l, traits>& lhs,
                                 const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = step<traits>(lhs[i], rhs[i]);
  }
  return result;
}

// *************** Other functions *************** //

// clamp
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> clamp(const Vec<T, l, traits>& v,
                                  const Vec<T, l, traits>& low,
                                  const Vec<T, l, traits>& high) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = clamp<traits>(v[i], low[i], high[i]);
  }
  return result;
}

// lerp
// Implicitely handled via the scalar implementation

}  // namespace VECPP_NAMESPACE
#endif