//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_ANGLE_H_INCLUDED
#define VECPP_ANGLE_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/cste_math/cste_math.h"

#include <cassert>
#include <iostream>
#include <type_traits>

namespace VECPP_NAMESPACE {

// Angle always represents value within the ]-PI,PI] radians range.
template <typename T>
class Angle {
 public:
  using value_type = T;

  static constexpr Angle from_rad(const value_type&);
  static constexpr Angle from_deg(const value_type&);

  // The argument MUST be in the ]-PI, PI] range.
  static constexpr Angle from_clamped_rad(const value_type&);

  // The argument MUST be in the ]-180, 180] range.
  static constexpr Angle from_clamped_deg(const value_type&);

  constexpr value_type as_deg() const;
  constexpr value_type as_rad() const;

  constexpr const value_type& raw() const;

 private:
  value_type value_;

  // Constructs an angle from a constrained radian value.
  explicit constexpr Angle(const T&);
};

template <typename T>
constexpr Angle<T> operator-(const Angle<T>& rhs) {
  T value = rhs.as_rad();

  // Special case, we keep positive pi.
  if (value != pi<T>) {
    value = -value;
  }

  return Angle<T>::from_clamped_rad(value);
}

template <typename T>
constexpr Angle<T>& operator+=(Angle<T>& lhs,
                                       const Angle<T>& rhs) {
  T val = lhs.as_rad() + rhs.as_rad();

  // Since both lhs and rhs are in the ]-PI,PI] range, the sum is in the
  // ]-2PI-1,2PI] range, so we can make assumptions in the constraining process.
  if (val > pi<T>) {
    val -= cste::two_pi<T>;
  } else if (val <= -pi<T>) {
    val += cste::two_pi<T>;
  }

  lhs = Angle<T>::from_clamped_rad(val);

  return lhs;
}

template <typename T>
constexpr Angle<T> operator+(const Angle<T>& lhs,
                                     const Angle<T>& rhs) {
  auto result = lhs;
  result += rhs;
  return result;
}

template <typename T>
constexpr Angle<T>& operator-=(Angle<T>& lhs,
                                       const Angle<T>& rhs) {
  T val = lhs.as_rad() - rhs.as_rad();

  // Since both lhs and rhs are in the ]-PI,PI] range, the difference is in the
  // ]-2PI,2PI[ range, so we can make assumptions in the constraining process.
  if (val > pi<T>) {
    val -= cste::two_pi<T>;
  } else if (val <= -pi<T>) {
    val += cste::two_pi<T>;
  }

  lhs = Angle<T>::from_clamped_rad(val);

  return lhs;
}

template <typename T>
constexpr Angle<T> operator-(const Angle<T>& lhs,
                                     const Angle<T>& rhs) {
  auto result = lhs;
  result -= rhs;
  return result;
}

template <typename T>
constexpr Angle<T>& operator*=(Angle<T>& lhs, const T& rhs) {
  lhs = Angle<T>::from_rad(lhs.as_rad() * rhs);
  return lhs;
}

template <typename T>
constexpr Angle<T> operator*(const Angle<T>& lhs,
                                     const T& rhs) {
  auto result = lhs;
  result *= rhs;
  return result;
}

template <typename T>
constexpr Angle<T> operator*(const T& lhs,
                                     const Angle<T>& rhs) {
  return rhs * lhs;
}

template <typename T>
constexpr Angle<T>& operator/=(Angle<T>& lhs, const T& rhs) {
  lhs = Angle<T>::from_rad(lhs.as_rad() / rhs);
  return lhs;
}

template <typename T>
constexpr Angle<T> operator/(const Angle<T>& lhs,
                                     const T& rhs) {
  auto result = lhs;
  result /= rhs;
  return result;
}

// COMPARISONS
template <typename T1, typename T2>
constexpr bool operator==(const Angle<T1>& lhs,
                          const Angle<T2>& rhs) {
  return lhs.raw() == rhs.raw();
}

template <typename T1, typename T2>
constexpr bool operator!=(const Angle<T1>& lhs,
                          const Angle<T2>& rhs) {
  return lhs.raw() != rhs.raw();
}

template <typename T1, typename T2>
constexpr bool operator<(const Angle<T1>& lhs,
                         const Angle<T2>& rhs) {
  return lhs.raw() < rhs.raw();
}

template <typename T1, typename T2>
constexpr bool operator>(const Angle<T1>& lhs,
                         const Angle<T2>& rhs) {
  return lhs.raw() > rhs.raw();
}

template <typename T1, typename T2>
constexpr bool operator<=(const Angle<T1>& lhs,
                          const Angle<T2>& rhs) {
  return lhs.raw() <= rhs.raw();
}

template <typename T1, typename T2>
constexpr bool operator>=(const Angle<T1>& lhs,
                          const Angle<T2>& rhs) {
  return lhs.raw() >= rhs.raw();
}

// IOSTREAM
template <typename T>
std::ostream& operator<<(std::ostream& stream, const Angle<T>& v) {
  return stream << v.as_deg() << "°";
}

// CONSTRUCTION
template <typename T>
constexpr Angle<T>::Angle(const T& v) : value_(v) {}

template <typename T>
constexpr Angle<T> Angle<T>::from_clamped_rad(const T& v) {
  assert(v > -cste::pi<float> && v <= cste::pi<float>);

  return Angle<T>(v);
}

template <typename T>
constexpr Angle<T> Angle<T>::from_clamped_deg(const T& v) {
  return from_clamped_rad(v / T(180) * cste::pi<T>);
}

template <typename T>
constexpr Angle<T> Angle<T>::from_rad(const T& v) {
  T constrained = cste::modulo(v + cste::pi<T>, cste::two_pi<T>);

  if (constrained <= T(0)) {
    constrained += cste::two_pi<T>;
  }

  constrained -= cste::pi<T>;

  return from_clamped_rad(constrained);
}

template <typename T>
constexpr Angle<T> Angle<T>::from_deg(const T& v) {
  return from_rad(v / T(180) * cste::pi<T>);
}

// CONVERSION
template <typename T>
constexpr T Angle<T>::as_deg() const {
  return value_ * T(180) / cste::pi<T>;
}

template <typename T>
constexpr T Angle<T>::as_rad() const {
  return value_;
}

template <typename T>
constexpr const T& Angle<T>::raw() const {
  return value_;
}
}  // namespace VECPP_NAMESPACE

#endif
