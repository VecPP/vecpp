//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_OPERATIONS_H_INCLUDED
#define VECPP_SCALAR_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "cste_math/cste_math.h"
#include "vecpp/traits.h"

#include <cmath>

namespace VECPP_NAMESPACE {

namespace non_cste {
// Some STL vendors have made some functions constexpr that are not required
// so by the standard. We wrap them in forcibly non-constexpr functions
// so that we have guaranteed portable code.

template <typename T>
T abs(const T& v) {
  return std::abs(v);
}

template <typename T>
T sqrt(const T& v) {
  return std::sqrt(v);
}

template <typename T>
T pow(const T& x, const T& n) {
  return std::pow(x, n);
}

template <typename T>
T exp(const T& v) {
  return std::exp(v);
}

template <typename T>
T ceil(const T& v) {
  return std::ceil(v);
}

template <typename T>
T floor(const T& v) {
  return std::floor(v);
}

template <typename T>
T fract(const T& v) {
  return v - floor(v);
}

template <typename T>
T round(const T& v) {
  return std::round(v);
}

template <typename T>
T trunc(const T& v) {
  return std::trunc(v);
}

template <typename T>
T fmod(const T& v, const T& d) {
  return std::fmod(v, d); 
}
}  // namespace non_cste

template <typename traits = Scalar_traits, typename T>
constexpr T abs(const T& v) {
  if constexpr(std::is_integral_v<T>) {
    return v >= 0 ? v : -v;
  }
  else if constexpr (is_ct<traits>()) {
    return cste::stdlib::abs(v);
  }
  else {
    return non_cste::abs(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T ceil(const T& v) {
  if constexpr (std::is_integral_v<T>) {
    return v;
  }
  else if constexpr (is_ct<traits>()) {
    return cste::stdlib::ceil(v);
  } else {
    return std::ceil(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T exp(const T& v) {
  if constexpr (is_ct<traits>()) {
    return cste::stdlib::exp(v);
  } else {
    return non_cste::exp(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T floor(const T& v) {
  if constexpr(std::is_integral_v<T>) {
    return v;
  } if constexpr (is_ct<traits>()) {
    return cste::stdlib::floor(v);
  } else {
    return non_cste::floor(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T round(const T& v) {
  if constexpr (std::is_integral_v<T>) {
    return v;
  } else if constexpr (is_ct<traits>()) {
    return cste::stdlib::round(v);
  } else {
    return non_cste::round(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T sign(const T& v) {
  return cste::sign(v);
}

template <typename traits = Scalar_traits, typename T>
constexpr T trunc(const T& v) {
  if constexpr (std::is_integral_v<T>) {
    return v;
  } else if constexpr (is_ct<traits>()) {
    return cste::stdlib::trunc(v);
  } else {
    return non_cste::trunc(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T mod(const T& v, const T& d) {
  if constexpr(std::is_integral_v<T>) {
    return v % d;
  } else if constexpr (is_ct<traits>()) {
    return cste::stdlib::fmod(v, d);
  } else {
    return non_cste::fmod(v, d);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T fract(const T& v) {
  if constexpr (std::is_integral_v<T>) {
    return T(0);
  } else if constexpr (is_ct<traits>()) {
    return cste::stdlib::fract(v);
  } else {
    return non_cste::fract(v);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T step(const T& edge, const T& x) {
  return x < edge ? 0.0f : 1.0f;
}

template <typename traits = Scalar_traits, typename T>
constexpr T min(const T& lhs, const T& rhs) {
  return std::min(lhs, rhs);
}

template <typename traits = Scalar_traits, typename T>
constexpr T max(const T& lhs, const T& rhs) {
  return std::max(lhs, rhs);
}

template <typename traits = Scalar_traits, typename T>
constexpr T clamp(const T& v, const T& low,
                        const T& high) {
  return std::clamp(v, low, high);
}

template <typename traits = Scalar_traits, typename T, typename PctT>
constexpr T lerp(const T& from, const T& to,
                       const PctT& pct) {
  return from + (to - from) * pct;
}

template <typename traits = Scalar_traits, typename T>
constexpr T pow(const T& x, const T& n) {
  if constexpr (is_ct<traits>()) {
    return cste::stdlib::pow(x, n);
  } else {
    return non_cste::pow(x, n);
  }
}

template <typename traits = Scalar_traits, typename T>
constexpr T sqrt(const T& v) {
  if constexpr (is_ct<traits>()) {
    return cste::stdlib::sqrt(v);
  } else {
    return non_cste::sqrt(v);
  }
}
}  // namespace VECPP_NAMESPACE
#endif