#ifndef VECPP_MAT_GEN_H_INCLUDED
#define VECPP_MAT_GEN_H_INCLUDED

#include "vecpp/config.h"
#include "vecpp/mat.h"

namespace VECPP_NAMESPACE {

// Creates an orthographic 2d projection matrix.
template <typename T>
constexpr Mat<T, 4, 4> make_ortho(T l, T r, T b, T t) {
  Mat<T, 4, 4> result = Mat<T, 4, 4>::identity;

  result[0][0] = T(2) / (r - l);
  result[1][1] = T(2) / (t - b);
  result[3][0] = (r + l) / (r - l);
  result[3][1] = (t + b) / (t - b);

  return result;
}
}
#endif