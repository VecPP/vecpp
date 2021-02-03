//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_OPERATIONS_PER_MEMBER_H_INCLUDED
#define VECPP_VEC_OPERATIONS_PER_MEMBER_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/scalar/functions.h"
#include "vecpp/vec/vec.h"

#include <algorithm>

namespace VECPP_NAMESPACE {

// *************** Unary functions *************** //

// abs
template <typename T, std::size_t l>
constexpr Vec<T, l> absolute(const Vec<T, l>& vec) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < vec.length; ++i) {
    result[i] = absolute(vec[i]);
  }
  return result;
}

// ceil
template <typename T, std::size_t l>
constexpr Vec<T, l> round_up(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = round_up(v[i]);
  }
  return result;
}

// floor
template <typename T, std::size_t l>
constexpr Vec<T, l> round_down(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = round_down(v[i]);
  }
  return result;
}

// fract
template <typename T, std::size_t l>
constexpr Vec<T, l> fractional(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = fractional(v[i]);
  }
  return result;
}

// round
template <typename T, std::size_t l>
constexpr Vec<T, l> round(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = round(v[i]);
  }
  return result;
}

// sign
template <typename T, std::size_t l>
constexpr Vec<T, l> sign(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = sign(v[i]);
  }
  return result;
}

// trunc
template <typename T, std::size_t l>
constexpr Vec<T, l> truncate(const Vec<T, l>& v) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = truncate(v[i]);
  }
  return result;
}
// *************** Binary functions *************** //

// max
template <typename T, std::size_t l>
constexpr Vec<T, l> max(const Vec<T, l>& lhs,
                        const Vec<T, l>& rhs) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = std::max(lhs[i], rhs[i]);
  }
  return result;
}

// min
template <typename T, std::size_t l>
constexpr Vec<T, l> min(const Vec<T, l>& lhs,
                        const Vec<T, l>& rhs) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = std::min(lhs[i], rhs[i]);
  }
  return result;
}

// mod
template <typename T, std::size_t l>
constexpr Vec<T, l> modulo(const Vec<T, l>& lhs,
                                const Vec<T, l>& rhs) {
  Vec<T, l> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = modulo(lhs[i], rhs[i]);
  }
  return result;
}

// lerp
// Implicitely handled via the scalar implementation

}  // namespace VECPP_NAMESPACE
#endif