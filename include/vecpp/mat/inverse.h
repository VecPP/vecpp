//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_MAT_INVERSE_H_INCLUDED
#define VECPP_MAT_INVERSE_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/mat/mat.h"
#include "vecpp/mat/operations.h"

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

template <typename T>
struct Matrix_inversion<Mat<T, 1, 1>> {
  static constexpr bool is_invertible(const Mat<T, 1, 1>& m) {
    return m(0, 0) != T(0);
  }

  static constexpr Mat<T, 1, 1> invert(const Mat<T, 1, 1>& m) {
    return Mat<T, 1, 1>{m(0, 0)};
  }
};

template <typename T>
struct Matrix_inversion<Mat<T, 2, 2>> {
  static constexpr bool is_invertible(const Mat<T, 2, 2>& m) {
    return determinant(m) != T(0);
  }

  static constexpr Mat<T, 2, 2> invert(const Mat<T, 2, 2>& m) {
    return Mat<T, 2, 2>{m(1, 1), -m(0, 1), -m(1, 0), m(0, 0)} /
           determinant(m);
  }
};

template <typename T, std::size_t N>
constexpr Mat<T, N, N> inverse(const Mat<T, N, N>& m) {
  return Matrix_inversion<Mat<T, N, N>>::invert(m);
}

template <typename T, std::size_t N>
constexpr bool is_invertible(const Mat<T, N, N>& m) {
  return Matrix_inversion<Mat<T, N, N>>::is_invertible(m);
}
}

#endif