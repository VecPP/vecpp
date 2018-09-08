//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
#ifndef VECPP_MATH_SINGLE_INCLUDE_H_
#define VECPP_MATH_SINGLE_INCLUDE_H_
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <type_traits>

#ifdef _MSVC_LANG
#if _MSVC_LANG < 201703L
#error C++17 support is required
#endif
#elif __cplusplus < 201703L
#error C++17 support is required
#endif
#define VECPP_VERSION_MAJOR 0
#define VECPP_VERSION_MINOR 0
#define VECPP_VERSION_PATCH 1
#define VECPP_VERSION 001
#ifndef VECPP_NAMESPACE
#define VECPP_NAMESPACE vecpp
#endif

#ifdef _MSVC_LANG
#if _MSVC_LANG < 201703L
#error C++17 support is required
#endif
#elif __cplusplus < 201703L
#error C++17 support is required
#endif
#ifndef CSTE_MATH_NAMESPACE
#define CSTE_MATH_NAMESPACE cste
#endif

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T pi = T(3.14159265358979323846264338327950288419L);
template <typename T>
constexpr T half_pi = pi<T> / T(2);
template <typename T>
constexpr T quarter_pi = pi<T> / T(4);
template <typename T>
constexpr T two_pi = pi<T>* T(2);
template <typename T>
constexpr T e = T(2.71828182845904523536028747135266249775724709L);
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sign(const T& v);
template <typename T>
constexpr bool is_nan(const T& v);
template <typename T>
constexpr bool is_inf(const T& v);
template <typename T>
constexpr T absolute(const T& v);
template <typename T>
constexpr T fractional(const T& v);
template <typename T>
constexpr T round(const T& v);
template <typename T>
constexpr T round_down(const T& v);
template <typename T>
constexpr T round_up(const T& v);
template <typename T>
constexpr T truncate(const T& v);
template <typename T>
constexpr T sine(const T&);
template <typename T>
constexpr T cosine(const T&);
template <typename T>
constexpr T exponential(const T& v);
template <typename T>
constexpr T modulo(const T& val, const T& div);
template <typename T, typename U>
constexpr T power(const T& v, const U& p);
template <typename T>
constexpr T square_root(const T& v);
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T, typename U>
constexpr T power(const T& v, const U& p) {
  if constexpr (std::is_integral<U>()) {
    T result = 1;
    for (U i = 0; i < p; ++i) {
      result *= v;
    }
    return result;
  } else {
    assert(false);
    return v;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr bool is_nan(const T& v) {
  return !(v == v);
}
template <typename T>
constexpr bool is_inf(const T& v) {
  constexpr T inf = std::numeric_limits<T>::infinity();
  return v == inf || v == -inf;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round_down(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;
  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v > T(0)) {
    return T(x);
  }
  return T(x - 1);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace exp_details {
constexpr long double recur_helper(long double x, long double num,
                                   long double fact, std::size_t i) {
  fact *= i;
  num *= x;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0L;
  }
  return factor + recur_helper(x, num, fact, i + 1);
}
}  // namespace exp_details
template <typename T>
constexpr T exponential(const T& v) {
  long double v_p = v;
  bool neg = v < 0;
  if (neg) {
    v_p = -v_p;
  }
  // separate integral and fractional components
  uint32_t integral = uint32_t(round_down(v));
  long double fract = v_p - integral;
  long double int_val = 1;
  long double e_fact = e<long double>;
  while (integral != 0) {
    if (integral & 1) {
      int_val *= e_fact;
    }
    integral >>= 1;
    e_fact *= e<long double>;
  }
  long double fract_val = exp_details::recur_helper(fract, 1, 1, 1) + 1.0L;
  long double result = fract_val * int_val;
  return T(neg ? 1.0L / result : result);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T modulo(const T& val, const T& div) {
  if constexpr (std::is_integral_v<T>) {
    return val % div;
  } else {
    return val - round_down(val / div) * div;
  }
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T square_root(const T& v) {
  assert(v >= T(0));
  if (v == T(0)) {
    return v;
  }
  T r = v;
  // A simple newton-rhapson for now.
  while (1) {
    T tmp = (r + v / r) / T(2);
    if (tmp == r) {
      break;
    }
    r = tmp;
  }
  return r;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sign(const T& v) {
  // https://stackoverflow.com/a/4609795/4442671
  return T((T(0) < v) - (v < T(0)));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T absolute(const T& v) {
  return v < 0 ? -v : v;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T fractional(const T& val) {
  return val - round_down(val);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round(const T& v) {
  return round_down(v + T(0.5));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T round_up(const T& v) {
  constexpr T range_max = power(T(2), (std::numeric_limits<T>::digits - 1));
  constexpr T range_min = -range_max;
  if (v >= range_max || v <= range_min || is_nan(v)) {
    return v;
  }
  long long int x = static_cast<long long int>(v);
  if (v == T(x) || v < T(0)) {
    return T(x);
  }
  return T(x + 1);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T truncate(const T& v) {
  long long int x = static_cast<long long int>(v);
  return T(x);
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace cosine_detail {
constexpr long double recur_helper(long double r_2, long double num,
                                   long double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}  // namespace cosine_detail
template <typename T>
constexpr T cosine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
  // Promote to long double
  long double r = rad;
  long double r_2 = r * r * -1.0;
  return cosine_detail::recur_helper(r_2, 1, 1.0L, 2) + 1.0L;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace sine_detail {
constexpr long double recur_helper(long double r_2, long double num,
                                   double fact, std::size_t i) {
  fact *= (i - 1);
  fact *= (i);
  num *= r_2;
  long double factor = num / fact;
  if (factor == 0.0L) {
    return 0.0;
  }
  return factor + recur_helper(r_2, num, fact, i + 2);
}
}  // namespace sine_detail
template <typename T>
constexpr T sine_pi4(const T& rad) {
  assert(rad >= -quarter_pi<T> && rad <= quarter_pi<T>);
  // Promote to long double
  long double r = rad;
  return sine_detail::recur_helper(r * r * -1.0L, r, 1.0L, 3) + r;
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T cosine(const T& rad) {
  if (is_nan(rad)) {
    return rad;
  }
  if (is_inf(rad)) {
    return std::numeric_limits<T>::signaling_NaN();
  }
  long double r = rad;
  // Remap into the -PI->PI range.
  if (r > pi<T>) {
    r = modulo(rad, two_pi<T>);
  } else if (r < -pi<T>) {
    r = modulo(rad, -two_pi<T>);
  }
  if (r > pi<long double>) {
    r -= two_pi<long double>;
  } else if (r < -pi<long double>) {
    r += two_pi<long double>;
  }
  // Remap into the -PI/2->PI/2 range.
  long double neg = 1.0L;
  if (r > half_pi<long double>) {
    r -= pi<T>;
    neg = -1.0L;
  } else if (r < -half_pi<long double>) {
    r += pi<T>;
    neg = -1.0L;
  }
  if (r < -quarter_pi<long double>) {
    return T(neg * sine_pi4(r + half_pi<long double>));
  } else if (r > quarter_pi<long double>) {
    return T(neg * -sine_pi4(r - half_pi<long double>));
  }
  return T(neg * cosine_pi4(r));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
template <typename T>
constexpr T sine(const T& rad) {
  if (is_nan(rad)) {
    return rad;
  }
  if (is_inf(rad)) {
    return std::numeric_limits<T>::signaling_NaN();
  }
  long double r = rad;
  // Remap into the -PI->PI range.
  if (r > pi<long double>) {
    r = modulo(r, two_pi<long double>);
  } else if (r < -pi<long double>) {
    r = modulo(r, -two_pi<long double>);
  }
  if (r > pi<long double>) {
    r -= two_pi<long double>;
  } else if (r < -pi<long double>) {
    r += two_pi<long double>;
  }
  // Remap into the -PI/2->PI/2 range.
  if (r > half_pi<long double>) {
    r = pi<T> - r;
  } else if (r < -half_pi<long double>) {
    r = -pi<T> - r;
  }
  if (r < -quarter_pi<long double>) {
    return T(-cosine_pi4(r + half_pi<long double>));
  } else if (r > quarter_pi<long double>) {
    return T(cosine_pi4(r - half_pi<long double>));
  }
  return T(sine_pi4(r));
}
}  // namespace CSTE_MATH_NAMESPACE

namespace CSTE_MATH_NAMESPACE {
namespace stdlib {
  template<typename T>
  constexpr T abs(const T& arg) {
    return absolute(arg);
  }
  template<typename T>
  constexpr T ceil(const T& arg) {
    return round_up(arg);
  }
  template<typename T>
  constexpr T exp(const T& arg) {
    return exponential(arg);
  }
  template<typename T>
  constexpr T floor(const T& arg) {
    return round_down(arg);
  }
  template<typename T>
  constexpr T fmod(const T& v, const T& d) {
    return modulo(v, d);
  }
  template<typename T>
  constexpr T fract(const T& arg) {
    return fractional(arg);
  }
  template<typename T>
  constexpr T pow(const T& v, const T& p) {
    return power(v, p);
  }
  template<typename T>
  constexpr T round(const T& arg) {
    return ::CSTE_MATH_NAMESPACE::round(arg);
  }
  template<typename T>
  constexpr T trunc(const T& arg) {
    return truncate(arg);
  }
  template<typename T>
  constexpr T sqrt(const T& arg) {
    return square_root(arg);
  }
}
}  // namespace CSTE_MATH_NAMESPACE


namespace VECPP_NAMESPACE {
struct Scalar_traits {
  enum { force_constexpr = false };
};
template <typename T>
struct Vec_traits : public Scalar_traits {
  enum {
    align = alignof(T),
  };
};
template <typename T>
struct Mat_traits : public Scalar_traits {
  enum {
    align = alignof(T),
  };
};
template <typename Traits>
constexpr bool is_ct() {
  return Traits::force_constexpr;
}
template<typename Traits>
struct With_constexpr : public Traits {
  enum { force_constexpr = true };
};
template<typename Traits>
using Add_constexpr_t = std::conditional_t<
    is_ct<Traits>(),
    Traits,
    With_constexpr<Traits>
  >;
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
namespace non_cste {
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

namespace VECPP_NAMESPACE {
template <typename T>
constexpr T pi = cste::pi<T>;
template <typename T>
constexpr T half_pi = cste::half_pi<T>;
template <typename T>
constexpr T quarter_pi = cste::quarter_pi<T>;
template <typename T>
constexpr T two_pi = cste::two_pi<T>;
}  // namespace CSTE_MATH_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, typename TraitsT = Scalar_traits>
class Angle {
 public:
  using value_type = T;
  using traits = TraitsT;
  static constexpr Angle from_rad(const value_type&);
  static constexpr Angle from_deg(const value_type&);
  // The argument MUST be in the ]-PI, PI] range.
  static constexpr Angle from_clamped_rad(const value_type&);
  // The argument MUST be in the ]-180, 180] range.
  static constexpr Angle from_clamped_deg(const value_type&);
  constexpr value_type as_deg() const;
  constexpr value_type as_rad() const;
  constexpr const value_type& raw() const;
  template <typename New_traits>
  constexpr operator Angle<T, New_traits>() const;
 private:
  value_type value_;
  // Constructs an angle from a constrained radian value.
  explicit constexpr Angle(const T&);
};
template <typename T, typename traits>
constexpr auto ct(const Angle<T, traits>& v) {
  return Angle<T, Add_constexpr_t<traits>>(v);
}
template <typename T, typename Traits>
template <typename New_traits>
constexpr Angle<T, Traits>::operator Angle<T, New_traits>() const {
  return Angle<T, New_traits>::from_clamped_rad(value_);
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator-(const Angle<T, Traits>& rhs) {
  T value = rhs.as_rad();
  // Special case, we keep positive pi.
  if (value != pi<T>) {
    value = -value;
  }
  return Angle<T, Traits>::from_clamped_rad(value);
}
template <typename T, typename Traits>
constexpr Angle<T, Traits>& operator+=(Angle<T, Traits>& lhs,
                                       const Angle<T, Traits>& rhs) {
  T val = lhs.as_rad() + rhs.as_rad();
  // Since both lhs and rhs are in the ]-PI,PI] range, the sum is in the
  // ]-2PI-1,2PI] range, so we can make assumptions in the constraining process.
  if (val > pi<T>) {
    val -= two_pi<T>;
  } else if (val <= -pi<T>) {
    val += two_pi<T>;
  }
  lhs = Angle<T, Traits>::from_clamped_rad(val);
  return lhs;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator+(const Angle<T, Traits>& lhs,
                                     const Angle<T, Traits>& rhs) {
  auto result = lhs;
  result += rhs;
  return result;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits>& operator-=(Angle<T, Traits>& lhs,
                                       const Angle<T, Traits>& rhs) {
  T val = lhs.as_rad() - rhs.as_rad();
  // Since both lhs and rhs are in the ]-PI,PI] range, the difference is in the
  // ]-2PI,2PI[ range, so we can make assumptions in the constraining process.
  if (val > pi<T>) {
    val -= two_pi<T>;
  } else if (val <= -pi<T>) {
    val += two_pi<T>;
  }
  lhs = Angle<T, Traits>::from_clamped_rad(val);
  return lhs;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator-(const Angle<T, Traits>& lhs,
                                     const Angle<T, Traits>& rhs) {
  auto result = lhs;
  result -= rhs;
  return result;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits>& operator*=(Angle<T, Traits>& lhs, const T& rhs) {
  lhs = Angle<T, Traits>::from_rad(lhs.as_rad() * rhs);
  return lhs;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator*(const Angle<T, Traits>& lhs,
                                     const T& rhs) {
  auto result = lhs;
  result *= rhs;
  return result;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator*(const T& lhs,
                                     const Angle<T, Traits>& rhs) {
  return rhs * lhs;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits>& operator/=(Angle<T, Traits>& lhs, const T& rhs) {
  lhs = Angle<T, Traits>::from_rad(lhs.as_rad() / rhs);
  return lhs;
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> operator/(const Angle<T, Traits>& lhs,
                                     const T& rhs) {
  auto result = lhs;
  result /= rhs;
  return result;
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator==(const Angle<T, Traits1>& lhs,
                          const Angle<T, Traits2>& rhs) {
  return lhs.raw() == rhs.raw();
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator!=(const Angle<T, Traits1>& lhs,
                          const Angle<T, Traits2>& rhs) {
  return lhs.raw() != rhs.raw();
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator<(const Angle<T, Traits1>& lhs,
                         const Angle<T, Traits2>& rhs) {
  return lhs.raw() < rhs.raw();
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator>(const Angle<T, Traits1>& lhs,
                         const Angle<T, Traits2>& rhs) {
  return lhs.raw() > rhs.raw();
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator<=(const Angle<T, Traits1>& lhs,
                          const Angle<T, Traits2>& rhs) {
  return lhs.raw() <= rhs.raw();
}
template <typename T, typename Traits1, typename Traits2>
constexpr bool operator>=(const Angle<T, Traits1>& lhs,
                          const Angle<T, Traits2>& rhs) {
  return lhs.raw() >= rhs.raw();
}
template <typename T, typename Traits>
std::ostream& operator<<(std::ostream& stream, const Angle<T, Traits>& v) {
  return stream << v.as_deg() << "°";
}
template <typename T, typename Traits>
constexpr Angle<T, Traits>::Angle(const T& v) : value_(v) {}
template <typename T, typename Traits>
constexpr Angle<T, Traits> Angle<T, Traits>::from_clamped_rad(const T& v) {
  assert(v > -pi<float> && v <= pi<float>);
  return Angle<T, Traits>(v);
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> Angle<T, Traits>::from_clamped_deg(const T& v) {
  return from_clamped_rad(v / T(180) * pi<T>);
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> Angle<T, Traits>::from_rad(const T& v) {
  T constrained = cste::modulo(v + pi<T>, two_pi<T>);
  if (constrained <= T(0)) {
    constrained += two_pi<T>;
  }
  constrained -= pi<T>;
  return from_clamped_rad(constrained);
}
template <typename T, typename Traits>
constexpr Angle<T, Traits> Angle<T, Traits>::from_deg(const T& v) {
  return from_rad(v / T(180) * pi<T>);
}
template <typename T, typename Traits>
constexpr T Angle<T, Traits>::as_deg() const {
  return value_ * T(180) / pi<T>;
}
template <typename T, typename Traits>
constexpr T Angle<T, Traits>::as_rad() const {
  return value_;
}
template <typename T, typename Traits>
constexpr const T& Angle<T, Traits>::raw() const {
  return value_;
}
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, typename Traits>
constexpr T sin(const Angle<T, Traits>& a) {
  if constexpr(is_ct<Traits>()) {
    return cste::sine(a.as_rad());
  }
  else {
    return std::sin(a.as_rad());
  }
}
template <typename T, typename Traits>
constexpr T cos(const Angle<T, Traits>& a) {
  if constexpr(is_ct<Traits>()) {
      return cste::cosine(a.as_rad());
    }
  else {
    return std::cos(a.as_rad());
  }
}
template <typename T, typename Traits>
constexpr T tan(const Angle<T, Traits>& a) {
  if
    constexpr(is_ct<Traits>()) { return sin(a) / cos(a); }
  else {
    return std::tan(a.as_rad());
  }
}
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, std::size_t len, typename Traits = Vec_traits<T>>
struct alignas(Traits::align) Vec {
 public:
  static_assert(len > 0);
  static constexpr std::size_t length = len;
  using value_type = T;
  using traits = Traits;
  constexpr T& at(std::size_t i) {
    if (i >= len) {
      throw std::out_of_range("out of range vector access");
    }
    return data_[i];
  }
  constexpr const T& at(std::size_t i) const {
    if (i >= len) {
      throw std::out_of_range("out of range vector access");
    }
    return data_[i];
  }
  constexpr T& operator[](std::size_t i) {
    assert(i < len);
    return data_[i];
  }
  constexpr const T& operator[](std::size_t i) const {
    assert(i < len);
    return data_[i];
  }
  constexpr T* data() { return data_.data(); }
  constexpr const T* data() const { return data_.data(); }
  // Left public for aggregate initialization.
  std::array<T, len> data_;
  // A vector is implicitely convertible to any vector differing only by flags
  template <typename new_traits>
  constexpr operator Vec<T, len, new_traits>() const {
    Vec<T, len, new_traits> result = {};
    for (std::size_t i = 0; i < length; ++i) {
      result[i] = data_[i];
    }
    return result;
  }
};
template <typename T, std::size_t l, typename traits>
constexpr auto ct(const Vec<T, l, traits>& v) {
  return Vec<T, l, Add_constexpr_t<traits>>(v);
}
template <typename T, std::size_t l, typename traits>
constexpr T* begin(Vec<T, l, traits>& v) {
  return v.data();
}
template <typename T, std::size_t l, typename traits>
constexpr T* end(Vec<T, l, traits>& v) {
  return v.data() + v.length;
}
template <typename T, std::size_t l, typename traits>
constexpr const T* begin(const Vec<T, l, traits>& v) {
  return v.data();
}
template <typename T, std::size_t l, typename traits>
constexpr const T* end(const Vec<T, l, traits>& v) {
  return v.data() + v.length;
}
template <typename T, std::size_t l, typename traits>
std::ostream& operator<<(std::ostream& stream, const Vec<T, l, traits>& vec) {
  stream << "(";
  bool first = true;
  for (const auto& v : vec) {
    if (!first) {
      stream << ", ";
    } else {
      first = false;
    }
    stream << v;
  }
  stream << ")";
  return stream;
}
template <typename T, std::size_t l, typename traits1, typename traits2>
constexpr bool operator==(const Vec<T, l, traits1>& lhs,
                          const Vec<T, l, traits2>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}
template <typename T, std::size_t l, typename traits1, typename traits2>
constexpr bool operator!=(const Vec<T, l, traits1>& lhs,
                          const Vec<T, l, traits2>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator-(const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {};
  for (std::size_t i = 0; i < rhs.length; ++i) {
    result[i] = -rhs[i];
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator+=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator+(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result += rhs;
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator-=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator-(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result -= rhs;
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator*=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs[i];
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result *= rhs;
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator/=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs[i];
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator/(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result /= rhs;
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator*=(Vec<T, l, traits>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs;
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const Vec<T, l, traits>& lhs,
                                      const T& rhs) {
  Vec<T, l, traits> result = lhs;
  result *= rhs;
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const T& lhs,
                                      const Vec<T, l, traits>& rhs) {
  return rhs * lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator/=(Vec<T, l, traits>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs;
  }
  return lhs;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator/(const Vec<T, l, traits>& lhs,
                                      const T& rhs) {
  Vec<T, l, traits> result = lhs;
  result /= rhs;
  return result;
}
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, typename traits>
constexpr Vec<T, 3, traits> cross(const Vec<T, 3, traits>& lhs,
                                  const Vec<T, 3, traits>& rhs) {
  return {lhs[1] * rhs[2] - lhs[2] * rhs[1], lhs[2] * rhs[0] - lhs[0] * rhs[2],
          lhs[0] * rhs[1] - lhs[1] * rhs[0]};
}
template <typename T, std::size_t l, typename traits>
constexpr T dot(const Vec<T, l, traits>& lhs, const Vec<T, l, traits>& rhs) {
  T result = 0;
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result += lhs[i] * rhs[i];
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr T norm(const Vec<T, l, traits>& v) {
  return sqrt<traits>(dot(v, v));
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> normalize(const Vec<T, l, traits>& v) {
  return v / norm(v);
}
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> abs(const Vec<T, l, traits>& vec) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < vec.length; ++i) {
    result[i] = abs<traits>(vec[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> ceil(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = ceil<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> floor(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = floor<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> fract(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = fract<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> round(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = round<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> sign(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = sign<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> trunc(const Vec<T, l, traits>& v) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < v.length; ++i) {
    result[i] = trunc<traits>(v[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> max(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = max(lhs[i], rhs[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> min(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = min(lhs[i], rhs[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> mod(const Vec<T, l, traits>& lhs,
                                const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = mod<traits>(lhs[i], rhs[i]);
  }
  return result;
}
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> step(const Vec<T, l, traits>& lhs,
                                 const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {0};
  for (std::size_t i = 0; i < lhs.length; ++i) {
    result[i] = step<traits>(lhs[i], rhs[i]);
  }
  return result;
}
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
}  // namespace VECPP_NAMESPACE

namespace VECPP_NAMESPACE {
template <typename T, std::size_t C, std::size_t R,
          typename Traits = Mat_traits<T>>
struct Mat {
  static_assert(C > 0 && R > 0);
  static constexpr std::size_t rows = R;
  static constexpr std::size_t cols = C;
  using value_type = T;
  using traits = Traits;
  constexpr value_type& operator()(std::size_t i, std::size_t j) {
    assert(i < cols && j < rows);
    return data_[i * rows + j];
  }
  constexpr const value_type& operator()(std::size_t i, std::size_t j) const {
    assert(i < cols && j < rows);
    return data_[i * rows + j];
  }
  constexpr value_type& at(std::size_t c, std::size_t r) {
    if (c >= cols || r >= rows) {
      throw std::out_of_range("out of range matrix access");
    }
    return (*this)(c, r);
  }
  constexpr const value_type& at(std::size_t c, std::size_t r) const {
    if (c >= cols || r >= rows) {
      throw std::out_of_range("out of range matrix access");
    }
    return (*this)(c, r);
  }
  constexpr value_type* data() { return data_.data(); }
  constexpr const value_type* data() const { return data_.data(); }
  // Left public for aggregate initialization.
  std::array<value_type, cols * rows> data_;
};
template <typename T, std::size_t C, std::size_t R, typename L_traits,
          typename R_traits>
constexpr bool operator==(const Mat<T, C, R, L_traits>& lhs,
                          const Mat<T, C, R, R_traits>& rhs) {
  for (std::size_t i = 0; i < C; ++i) {
    for (std::size_t j = 0; j < R; ++j) {
      if (lhs(i, j) != rhs(i, j)) {
        return false;
      }
    }
  }
  return true;
}
template <typename T, std::size_t C, std::size_t R, typename Traits>
std::ostream& operator<<(std::ostream& stream,
                         const Mat<T, C, R, Traits>& lhs) {
  stream << "[";
  for (std::size_t i = 0; i < R; ++i) {
    stream << " ";
    for (std::size_t j = 0; j < C; ++j) {
      stream << lhs(i, j) << ",";
    }
    stream << "\n";
  }
  stream << "]";
  return stream;
}
template <typename T, std::size_t C, std::size_t R, typename Traits>
constexpr Mat<T, C, R, Traits> operator/(const Mat<T, C, R, Traits>& mat,
                                         const T& v) {
  Mat<T, C, R, Traits> result = {};
  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = mat(i, j) / v;
    }
  }
  return result;
}
template <typename T, std::size_t C, std::size_t R, typename Traits>
constexpr Mat<T, C, R, Traits> operator*(const Mat<T, C, R, Traits>& mat,
                                         const T& v) {
  Mat<T, C, R, Traits> result = {};
  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = mat(i, j) * v;
    }
  }
  return result;
}
template <typename T, std::size_t C, std::size_t R, typename M_traits,
          typename V_traits>
constexpr Vec<T, R, V_traits> operator*(const Mat<T, C, R, M_traits>& mat,
                                        const Vec<T, C, V_traits>& vec) {
  Vec<T, R, V_traits> result = {};
  for (std::size_t i = 0; i < R; ++i) {
    T v = 0;
    for (std::size_t j = 0; j < C; ++j) {
      v += mat(j, i) * vec[j];
    }
    result[i] = v;
  }
  return result;
}
template <typename T, std::size_t C, std::size_t R, typename M_traits,
          typename V_traits>
constexpr Vec<T, C, V_traits> operator*(const Vec<T, R, V_traits>& vec,
                                        const Mat<T, C, R, M_traits>& mat) {
  Vec<T, C, V_traits> result = {};
  for (std::size_t j = 0; j < C; ++j) {
    T v = 0;
    for (std::size_t i = 0; i < R; ++i) {
      v += mat(j, i) * vec[i];
    }
    result[j] = v;
  }
  return result;
}
}

namespace VECPP_NAMESPACE {
template <typename T, std::size_t N, typename Traits>
constexpr auto cofactor(const Mat<T, N, N, Traits>& mat, std::size_t row, std::size_t col) {
  Mat<T, N - 1, N - 1, Traits> cf = {};
  for (std::size_t i = 0; i < N - 1; ++i) {
    for (std::size_t j = 0; j < N - 1; ++j) {
      cf(i, j) = mat(
          i < row ? i : i + 1,
          j < col ? j : j + 1);
    }
  }
  T sign = (row + col) % 2 ? T(-1): T(1);
  return determinant(cf) * sign;
}
template <typename T, std::size_t N, typename Traits>
constexpr const Mat<T, N, N, Traits> cofactor(const Mat<T, N, N, Traits>& mat) {
  Mat<T, N, N, Traits> result = {};
  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      result(i, j) = cofactor(mat, i, j);
    }
  }
  return result;
}
template <typename MatT>
struct Mat_determinant;
template <typename MatT>
constexpr typename MatT::value_type determinant(const MatT& mat) {
  return Mat_determinant<MatT>::calc_determinant(mat);
}
template <typename T, typename Traits>
struct Mat_determinant<Mat<T, 1, 1, Traits>> {
  using MatT = Mat<T, 1, 1, Traits>;
  static constexpr T calc_determinant(const MatT& mat) { return mat(0, 0); }
};
template <typename T, typename Traits>
struct Mat_determinant<Mat<T, 2, 2, Traits>> {
  using MatT = Mat<T, 2, 2, Traits>;
  static constexpr T calc_determinant(const MatT& mat) {
    return mat(0, 0) * mat(1, 1) - mat(1, 0) * mat(0, 1);
  }
};
template <typename T, std::size_t N, typename Traits>
struct Mat_determinant<Mat<T, N, N, Traits>> {
  using MatT = Mat<T, N, N, Traits>;
  static constexpr T calc_determinant(const MatT& A) {
    T result = T(0);
    for (std::size_t i = 0; i < N; ++i) {
      result += cofactor(A, i, 0) * A(i, 0);
    }
    return result;
  }
};
template <typename T, std::size_t C, std::size_t R, typename Traits>
constexpr Mat<T, R, C, Traits> transpose(const Mat<T, C, R, Traits>& m) {
  Mat<T, R, C, Traits> result = {};
  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = m(j, i);
    }
  }
  return result;
}
}

namespace VECPP_NAMESPACE {
template <typename Mat_t>
struct Matrix_inversion {
  static constexpr bool is_invertible(const Mat_t& m) {
    return determinant(m) != 0;
  }
  static constexpr Mat_t invert(const Mat_t& m) {
    return transpose(cofactor(m)) / determinant(m);
  }
};
template <typename T, typename traits>
struct Matrix_inversion<Mat<T, 1, 1, traits>> {
  static constexpr bool is_invertible(const Mat<T, 1, 1, traits>& m) {
    return m(0, 0) != T(0);
  }
  static constexpr Mat<T, 1, 1, traits> invert(const Mat<T, 1, 1, traits>& m) {
    return Mat<T, 1, 1, traits>{m(0, 0)};
  }
};
template <typename T, typename traits>
struct Matrix_inversion<Mat<T, 2, 2, traits>> {
  static constexpr bool is_invertible(const Mat<T, 2, 2, traits>& m) {
    return determinant(m) != T(0);
  }
  static constexpr Mat<T, 2, 2, traits> invert(const Mat<T, 2, 2, traits>& m) {
    return Mat<T, 2, 2, traits>{m(1, 1), -m(0, 1), -m(1, 0), m(0, 0)} /
           determinant(m);
  }
};
template <typename T, std::size_t N, typename traits>
constexpr Mat<T, N, N, traits> inverse(const Mat<T, N, N, traits>& m) {
  return Matrix_inversion<Mat<T, N, N, traits>>::invert(m);
}
template <typename T, std::size_t N, typename traits>
constexpr bool is_invertible(const Mat<T, N, N, traits>& m) {
  return Matrix_inversion<Mat<T, N, N, traits>>::is_invertible(m);
}
}

namespace VECPP_NAMESPACE {
template <typename T, std::size_t N, std::size_t M, std::size_t P,
          typename traits>
constexpr Mat<T, N, P, traits> operator*(const Mat<T, N, M, traits>& lhs,
                                         const Mat<T, M, P, traits>& rhs) {
  Mat<T, N, P, traits> result = {};
  for(std::size_t i = 0; i < N; ++i) {
    for(std::size_t j = 0; j < P; ++j) {
      T v = T(0);
      for(std::size_t k = 0; k < M; ++k) {
        v += lhs(i, k) * rhs(k, j);
      }
      result(i, j) = v;
    }
  }
  return result;
}
}

namespace VECPP_NAMESPACE {
template <typename T>
struct Quat {
  using value_type = T;
  template <typename A_traits>
  static constexpr Quat angle_axis(const Angle<T, A_traits>& angle,
                                   const Vec<T, 3>& axis);
  // Left public for aggregate initialization.
  T w;
  T x;
  T y;
  T z;
};
template <typename T>
template <typename A_traits>
constexpr Quat<T> Quat<T>::angle_axis(const Angle<T, A_traits>& angle,
                                      const Vec<T, 3>& axis) {
  const T s = sin(angle * T(0.5));
  const T c = cos(angle * T(0.5));
  return {c, axis[0] * s, axis[1] * s, axis[2] * s};
}
template <typename T>
constexpr Quat<T>& operator*=(Quat<T>& lhs, const Quat<T>& rhs) {
  const Quat<T> p(lhs);
  const Quat<T> q(rhs);
  lhs.w = p.w * q.w - p.x * q.x - p.y * q.y - p.z * q.z;
  lhs.x = p.w * q.x + p.x * q.w + p.y * q.z - p.z * q.y;
  lhs.y = p.w * q.y + p.y * q.w + p.z * q.x - p.x * q.z;
  lhs.z = p.w * q.z + p.z * q.w + p.x * q.y - p.y * q.x;
  return lhs;
}
template <typename T>
constexpr Quat<T> operator*(const Quat<T>& lhs, const Quat<T>& rhs) {
  Quat<T> result(lhs);
  result *= rhs;
  return result;
}
template <typename T, typename V_traits>
constexpr Vec<T, 3, V_traits> operator*(const Quat<T>& lhs,
                                        const Vec<T, 3, V_traits>& rhs) {
  const Vec<T, 3, V_traits> q_v = {lhs.x, lhs.y, lhs.z};
  const Vec<T, 3, V_traits> uv = cross(q_v, rhs);
  const Vec<T, 3, V_traits> uuv = cross(q_v, uv);
  return rhs + ((uv * lhs.w) + uuv) * T(2);
}
}  // namespace VECPP_NAMESPACE


#endif
