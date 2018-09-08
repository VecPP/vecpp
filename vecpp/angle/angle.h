//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_ANGLE_H_INCLUDED
#define VECPP_ANGLE_H_INCLUDED

#include "vecpp/config.h"

#include "cste_math/stdlib.h"

#include "vecpp/scalar/constants.h"
#include "vecpp/scalar/operations.h"
#include "vecpp/traits.h"

#include <cassert>
#include <iostream>
#include <type_traits>

namespace VECPP_NAMESPACE {

// Angle always represents value within the ]-PI,PI] radians range.
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

// COMPARISONS
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

// IOSTREAM
template <typename T, typename Traits>
std::ostream& operator<<(std::ostream& stream, const Angle<T, Traits>& v) {
  return stream << v.as_deg() << "°";
}

// CONSTRUCTION
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

// CONVERSION
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

#endif
