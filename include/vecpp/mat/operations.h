//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_MAT_OPERATIONS_H_INCLUDED
#define VECPP_MAT_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/mat/mat.h"

#include <array>
#include <cassert>
#include <cstddef>

namespace VECPP_NAMESPACE {

// ***************** DETERMINANT ***************** //
template <typename MatT>
struct Mat_determinant;

template <typename MatT>
constexpr typename MatT::value_type determinant(const MatT& mat) {
  return Mat_determinant<MatT>::calc_determinant(mat);
}

// SPECIALIZATIONS:
template <typename T, typename Traits>
struct Mat_determinant<Mat<T, 2, 2, Traits>> {
  using MatT = Mat<T, 2, 2, Traits>;

  static constexpr T calc_determinant(const MatT& mat) {
    return mat(0, 0) * mat(1, 1) - mat(1, 0) * mat(0, 1);
  }
};

template <typename T, typename Traits>
struct Mat_determinant<Mat<T, 3, 3, Traits>> {
  using MatT = Mat<T, 3, 3, Traits>;

  static constexpr T calc_determinant(const MatT& mat) {
    return mat(0, 0) * (mat(1, 1) * mat(2, 2) - mat(2, 1) * mat(1, 2)) -
           mat(1, 0) * (mat(0, 1) * mat(2, 2) - mat(2, 1) * mat(0, 2)) +
           mat(2, 0) * (mat(0, 1) * mat(1, 2) - mat(1, 1) * mat(0, 2));
  }
};

// GENERAL CASE
template <typename T, std::size_t N, typename Traits>
struct Mat_determinant<Mat<T, N, N, Traits>> {
  using MatT = Mat<T, N, N, Traits>;
  static constexpr T calc_determinant(const MatT& A) {
    T result = T(0);
    T sign = T(1);
    for (std::size_t i = 0; i < N; ++i) {
      Mat<T, N - 1, N - 1, Traits> cf = {};

      for (std::size_t j = 0; j < N - 1; ++j) {
        for (std::size_t k = 0; k < N - 1; ++k) {
          cf(j, k) = A(j < i ? j : j + 1, k + 1);
        }
      }
      result += sign * determinant(cf) * A(i, 0);

      sign = sign * T(-1);
    }

    return result;
  }
};

// ***************** TRANSPOSE ***************** //
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

#endif