//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)


#ifndef CSTE_FUNCTIONS_H_INCLUDED
#define CSTE_FUNCTIONS_H_INCLUDED

#include "vecpp/cste_math/config.h"

#include "vecpp/cste_math/functions_ct.h"
#include "vecpp/cste_math/functions_rt.h"

namespace CSTE_MATH_NAMESPACE {

// ************************** Misc Functions ************************** //
template <typename T>
constexpr T sign(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::sign(v);
  } else {
    return rt::sign(v);
  }
}

template <typename T>
constexpr bool is_nan(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::is_nan(v);
  } else {
    return rt::is_nan(v);
  }
}

template <typename T>
constexpr bool is_inf(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::is_inf(v);
  } else {
    return rt::is_inf(v);
  }
}

// ************************** Rounding Functions ************************** //
template <typename T>
constexpr T absolute(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::absolute(v);
  } else {
    return rt::absolute(v);
  }
}

template <typename T>
constexpr T fractional(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::fractional(v);
  } else {
    return rt::fractional(v);
  }
}

template <typename T>
constexpr T round(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::round(v);
  } else {
    return rt::round(v);
  }
}

template <typename T>
constexpr T round_down(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::round_down(v);
  } else {
    return rt::round_down(v);
  }
}

template <typename T>
constexpr T round_up(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::round_up(v);
  } else {
    return rt::round_up(v);
  }
}

template <typename T>
constexpr T truncate(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::truncate(v);
  } else {
    return rt::truncate(v);
  }
}

// ************************ Trigonometry Functions ************************ //
template <typename T>
constexpr T sine(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::sine(v);
  } else {
    return rt::sine(v);
  }
}

template <typename T>
constexpr T cosine(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::cosine(v);
  } else {
    return rt::cosine(v);
  }
}
template <typename T>
constexpr T tangent(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::tangent(v);
  } else {
    return rt::tangent(v);
  }
}
// ************************** Calculus Functions ************************** //
template <typename T>
constexpr T exponential(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::exponential(v);
  } else {
    return rt::exponential(v);
  }
}
template <typename T>
constexpr T modulo(const T& val, const T& div) {
  if (std::is_constant_evaluated()) {
    return ct::modulo(val, div);
  } else {
    return rt::modulo(val, div);
  }
}
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  if (std::is_constant_evaluated()) {
    return ct::power(v, p);
  } else {
    return rt::power(v, p);
  }
}

template <typename T>
constexpr T square_root(const T& v) {
  if (std::is_constant_evaluated()) {
    return ct::square_root(v);
  } else {
    return rt::square_root(v);
  }
}
}  // namespace CSTE_MATH_NAMESPACE
#endif