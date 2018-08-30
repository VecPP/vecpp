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

namespace VECPP_NAMESPACE {

template<typename T, std::size_t C, std::size_t R>
constexpr T determinant(const Mat<T,C,R>& m) {
  assert(false);
}

template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T,R,C> transpose(const Mat<T,C,R>& m) {
  assert(false);
}


}
#endif