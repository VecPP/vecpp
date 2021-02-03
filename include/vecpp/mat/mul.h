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

template <typename T, std::size_t N, std::size_t M, std::size_t P>
constexpr Mat<T, N, P> operator*(const Mat<T, N, M>& lhs,
                                         const Mat<T, M, P>& rhs) {
  Mat<T, N, P> result = {};

  for(std::size_t i = 0; i < N; ++i) {
    for(std::size_t j = 0; j < P; ++j) {
      T v = T(0);

      for(std::size_t k = 0; k < M; ++k) {        
        v += lhs(i, k) * rhs(k, j); 
      }

      result(i, j) = v;
    }
  }

  return result;
}

}

#endif