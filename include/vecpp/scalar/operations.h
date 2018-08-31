//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_OPERATIONS_H_INCLUDED
#define VECPP_SCALAR_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {
  
  template<typename ScalarT>
  constexpr ScalarT abs(const ScalarT& v) {
    return v < ScalarT(0) ? -v : v;
  }

  template<typename ScalarT>
  constexpr ScalarT ceil(const ScalarT& v) {
    assert(false);
  }

  template<typename ScalarT>
  constexpr ScalarT exp(const ScalarT& v) {
    assert(false);
  }

  template<typename ScalarT>
  constexpr ScalarT floor(const ScalarT& v) {
    assert(false);
  }

  template<typename ScalarT>
  constexpr ScalarT fmod(const ScalarT& v, const ScalarT& d) {
    return v - floor(v / d) * div;
  }

  template<typename ScalarT>
  constexpr ScalarT pow(const ScalarT& x, const ScalarT& n) {
    assert(false);
  }  

  template<typename T>
  constexpr T sqrt(const T& v) {
    if(v == T(0)) {
      return v;
    }

    T r = v;
    // A lazy newton-rhapson for now.
    for(int i = 0 ; i < 100; ++i) {
      r -= (r*r - v) / (r * T(2));
    }

    return r;
  }
}
#endif