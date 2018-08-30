//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_OPERATIONS_H_INCLUDED
#define VECPP_VEC_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/vec/vec.h"

namespace VECPP_NAMESPACE {

// Dot product
template <typename T>
struct Dot_impl;

template <typename T, std::size_t L>
struct Dot_impl<Vec<T, L>> {
  constexpr static T dot(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
    T result = 0;

    for (std::size_t i = 0; i < L; ++i) {
      result += lhs[i] * rhs[i];
    }

    return result;
  }
};

template <typename T>
constexpr auto dot(const T& lhs, const T& rhs) {
  return Dot_impl<T>::dot(lhs, rhs);
}

// Vector legnth
template <typename T>
struct Length_impl;

template <typename T, std::size_t L>
struct Length_impl<Vec<T, L>> {
  constexpr static T length(const Vec<T, L>& v) { return std::sqrt(dot(v, v)); }
};

template <typename T>
constexpr auto length(const T& v) {
  return Length_impl<T>::length(v);
}

// Cross product
template <typename T>
struct Cross_impl;

template <typename T>
struct Cross_impl<Vec<T, 3>> {
  static constexpr Vec<T, 3> cross(const Vec<T, 3>& lhs, const Vec<T, 3>& rhs) {
    return {lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0]};
  }
};

template <typename T>
constexpr auto cross(const T& lhs, const T& rhs) {
  return Cross_impl<T>::cross(lhs, rhs);
}
}
#endif