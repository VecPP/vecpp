#ifndef VECPP_QUAT_H_INCLUDED
#define VECPP_QUAT_H_INCLUDED

#include "vecpp/config.h"
#include "vecpp/vec.h"

#include <array>
#include <cmath>
#include <cstddef>

namespace VECPP_NAMESPACE {

// We could technically provide sane-ish defaults for most functions,
template <typename T>
struct Quat { 
  using value_type = T;

  constexpr std::size_t size() const { return 4; }

  constexpr T& operator[](std::size_t i) { return data_[i]; }
  constexpr const T& operator[](std::size_t i) const { return data_[i]; }

  constexpr T* data() { return data_; }
  constexpr const T* data() const { return data_; }

  static constexpr Quat angle_axis(const T& angle, const Vec<T, 3>& axis) {
    const T s = std::sin(angle * T(0.5));

    return {std::cos(angle * T(0.5)), axis[0] * s, axis[1] * s, axis[2] * s};
  }

  // Left public for aggregate initialization.
  T data_[4]; //order is implicitely w x y z
};

template <typename T>
constexpr Quat<T>& operator*=(Quat<T>& lhs, const Quat<T>& rhs) {
  const Quat<T> p(lhs);
  const Quat<T> q(rhs);

  lhs[0] = p[0] * q[0] - p[1] * q[1] - p[2] * q[2] - p[3] * q[3];
  lhs[1] = p[0] * q[1] + p[1] * q[0] + p[2] * q[3] - p[3] * q[2];
  lhs[2] = p[0] * q[2] + p[2] * q[0] + p[3] * q[1] - p[1] * q[3];
  lhs[3] = p[0] * q[3] + p[3] * q[0] + p[1] * q[2] - p[2] * q[1];

  return lhs;
}

template <typename T>
constexpr Quat<T> operator*(const Quat<T>& lhs, const Quat<T>& rhs) {
  Quat<T> result(lhs);
  result *= rhs;
  return result;
}

// Rotate a vector by the quaternion
template <typename T>
constexpr Vec<T, 3> operator*(const Quat<T>& lhs, const Vec<T, 3>& rhs) {
  const Vec<T, 3> q_v = {lhs[1], lhs[2], lhs[3]};
  const Vec<T, 3> uv = cross(q_v, rhs);
  const Vec<T, 3> uuv = cross(q_v, uv);

  return rhs + ((uv * lhs[0]) + uuv) * T(2);
}
}
#endif