#ifndef VECPP_TRANSFORM_H_INCLUDED
#define VECPP_TRANSFORM_H_INCLUDED

#include "vecpp/config.h"
#include "vecpp/mat.h"

#include <array>
#include <cstddef>

namespace VECPP_NAMESPACE {

// The main idea is to keep transformations as specific as possible for as long as possible.
// so that scale(2.0f) * translate({1.0f, 0.0f, 0.0f} * vec; can be made as efficiently as 
// possible.


// Pure Scale transformation
template <typename T>
struct Scale {
  constexpr Scale(T const& s) : scale_({s, s, s}) {}

  constexpr Scale(Vec<T, 3> const& s) : scale_(s) {}

  Vec<T, 3> scale_;

  explicit constexpr operator Mat<T, 4, 4>() {
    Mat<T, 4, 4> result = Mat<T, 4, 4>::identity;
    result[0][0] = scale_[0];
    result[1][1] = scale_[1];
    result[2][2] = scale_[2];
    return result;
  }

  constexpr Mat<T, 4, 4> right_mul(const Mat<T, 4, 4>& m) const {
    Mat<T, 4, 4> result = {};
    result[0] = m[0] * scale_[0];
    result[1] = m[1] * scale_[1];
    result[2] = m[2] * scale_[2];
    result[3] = m[3];

    return result;
  }
};

template <typename T>
constexpr Scale<T> scale(const T& s) {
  return {s};
}

template <typename T>
constexpr Scale<T> scale(const Vec<T, 3>& s) {
  return {s};
}

template <typename T>
constexpr Mat<T, 4, 4> operator*(const Mat<T, 4, 4>& m, const Scale<T>& s) {
  return s.right_mul(m);
}

template <typename T>
constexpr Vec<T, 3> operator*(const Scale<T>& s, const Vec<T, 3>& v) {
  return {v[0] * s.scale_[0], v[1] * s.scale_[1], v[2] * s.scale_[2]};
}
}
#endif