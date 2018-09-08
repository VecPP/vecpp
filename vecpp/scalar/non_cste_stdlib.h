//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_NON_CSTE_STDLIB_H_INCLUDED
#define VECPP_SCALAR_NON_CSTE_STDLIB_H_INCLUDED

#include "vecpp/config.h"

#include <cmath>

namespace VECPP_NAMESPACE {
namespace non_cste {

// Some STL vendors have made some functions constexpr that are not required
// so by the standard. We wrap them in forcibly non-constexpr functions
// so that we can be confident that code will be portable.

// cste_math will provide us with truly portable constexpr alternatives of
// all these functions, so losing the "constexpr-ness" of these functions will
// not hurt us in the long run.

template <typename T>
T ceil(const T& v) {
  return std::ceil(v);
}

template <typename T>
T exp(const T& v) {
  return std::exp(v);
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
T fmod(const T& v, const T& d) {
  return std::fmod(v, d);
}

template <typename T>
T pow(const T& x, const T& n) {
  return std::pow(x, n);
}

template <typename T>
T round(const T& v) {
  return std::round(v);
}

template <typename T>
T sqrt(const T& v) {
  return std::sqrt(v);
}

template <typename T>
T trunc(const T& v) {
  return std::trunc(v);
}

}  // namespace non_cste
}  // namespace VECPP_NAMESPACE
#endif