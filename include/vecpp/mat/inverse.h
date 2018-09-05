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

#endif