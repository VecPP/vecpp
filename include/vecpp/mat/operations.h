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


// ***************** COFACTOR ***************** //
template <typename T, std::size_t N>
constexpr auto cofactor(const Mat<T, N, N>& mat, std::size_t row, std::size_t col) {
  Mat<T, N - 1, N - 1> cf = {};

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

// ***************** COFACTOR MATRIX ***************** //
template <typename T, std::size_t N>
constexpr const Mat<T, N, N> cofactor(const Mat<T, N, N>& mat) {
  Mat<T, N, N> result = {};

  for (std::size_t i = 0; i < N; ++i) {
    for (std::size_t j = 0; j < N; ++j) {
      result(i, j) = cofactor(mat, i, j);
    }
  }
  return result;
}

// ***************** DETERMINANT ***************** //
template <typename MatT>
struct Mat_determinant;

template <typename MatT>
constexpr typename MatT::value_type determinant(const MatT& mat) {
  return Mat_determinant<MatT>::calc_determinant(mat);
}

// SPECIALIZATIONS:
template <typename T>
struct Mat_determinant<Mat<T, 1, 1>> {
  using MatT = Mat<T, 1, 1>;

  static constexpr T calc_determinant(const MatT& mat) { return mat(0, 0); }
};

template <typename T>
struct Mat_determinant<Mat<T, 2, 2>> {
  using MatT = Mat<T, 2, 2>;

  static constexpr T calc_determinant(const MatT& mat) {
    return mat(0, 0) * mat(1, 1) - mat(1, 0) * mat(0, 1);
  }
};

// General case
template <typename T, std::size_t N>
struct Mat_determinant<Mat<T, N, N>> {
  using MatT = Mat<T, N, N>;
  static constexpr T calc_determinant(const MatT& A) {
    T result = T(0);
    for (std::size_t i = 0; i < N; ++i) {
      result += cofactor(A, i, 0) * A(i, 0);
    }

    return result;
  }
};

// ***************** TRANSPOSE ***************** //
template <typename T, std::size_t C, std::size_t R>
constexpr Mat<T, R, C> transpose(const Mat<T, C, R>& m) {
  Mat<T, R, C> result = {};

  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = m(j, i);
    }
  }
  return result;
}
}

#endif