//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_MAT_MUL_H_INCLUDED
#define VECPP_MAT_MUL_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/mat/mat.h"

namespace VECPP_NAMESPACE {

// General-purpose implementation of matmul. Fallback case.
template <typename T, std::size_t A, std::size_t B, std::size_t C>
struct Matmul_impl {
  constexpr static Mat<T, A, C> mul(const Mat<T, A, B>& lhs,
                                    const Mat<T, B, C>& rhs) {
    Mat<T, A, C> result = {};

    for (std::size_t i = 0; i < A; ++i) {
      for (std::size_t j = 0; j < C; ++j) {
        for (std::size_t k = 0; k < B; ++k) {
          result[i][j] += lhs[i][k] * rhs[k][j];
        }
      }
    }

    return result;
  }
};

template <typename T, std::size_t A, std::size_t B, std::size_t C>
constexpr Mat<T, A, C> operator*(const Mat<T, A, B>& lhs,
                                 const Mat<T, B, C>& rhs) {
  return Matmul_impl<T, A, B, C>::mul(lhs, rhs);
}
}
#endif