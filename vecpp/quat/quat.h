//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_QUAT_H_INCLUDED
#define VECPP_QUAT_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/angle/angle.h"
#include "vecpp/vec/vec.h"

#include <array>
#include <cmath>
#include <cstddef>

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

// Rotate a vector by the quaternion
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