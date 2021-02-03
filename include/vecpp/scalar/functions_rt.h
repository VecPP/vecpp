//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)


#ifndef CSTE_RT_H_INCLUDED
#define CSTE_RT_H_INCLUDED

#include "vecpp/cste_math/config.h"
#include "vecpp/cste_math/functions_ct.h"

#include <cmath>


// Runtime implementation of all functions defined in the library, these 
// will default to the standard library whenever appropriate.

// It's unlikely that you would use thse directly. Vecpp/cste_math/functions.h contains
// the same functionallity with a compile-time switch for constant expression evaluation.

namespace CSTE_MATH_NAMESPACE::rt {
// ************************** Misc Functions ************************** //
template <typename T>
T sign(const T& v) {
  return ct::sign(v);
}

template <typename T>
bool is_nan(const T& v) {
  return std::isnan(v);
}

template <typename T>
bool is_inf(const T& v) {
  return std::isinf(v);
}

// ************************** Rounding Functions ************************** //
template <typename T>
T absolute(const T& v) {
  return std::abs(v);
}

template <typename T>
T fractional(const T& v) {
  T _ = T(0);
  
  return modf(v, &_);
}

template <typename T>
T round(const T& v) {
  return std::round(v);
}

template <typename T>
T round_down(const T& v) {
  return std::floor(v);
}

template <typename T>
T round_up(const T& v) {
  return std::ceil(v);
}

template <typename T>
T truncate(const T& v) {
  return std::trunc(v);
}

// ************************ Trigonometry Functions ************************ //
template <typename T>
T sine(const T& v) {
  return std::sin(v);
}

template <typename T>
T cosine(const T& v) {
  return std::cos(v);
}

template <typename T>
T tangent(const T& v) {
  return std::tan(v);
}

// ************************** Calculus Functions ************************** //
template <typename T>
constexpr T exponential(const T& v) {
  return std::exp(v);
}

template <typename T>
constexpr T modulo(const T& val, const T& div) {
  return (T)std::fmod(val, div);
}
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  return std::pow(v, p);
}

template <typename T>
constexpr T square_root(const T& v) {
  return std::sqrt(v);
}

}  // namespace CSTE_MATH_NAMESPACE::rt

#endif