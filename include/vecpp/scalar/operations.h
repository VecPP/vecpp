//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_OPERATIONS_H_INCLUDED
#define VECPP_SCALAR_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/flags.h"

#include <cmath>

namespace VECPP_NAMESPACE {
  
  namespace non_cste {
    // Some STL vendors have made some functions constexpr that are not required
    // so by the standard.
    template<typename T>
    T sqrt(const T& v) {
      return std::sqrt(v);
    }

    template<typename T>
    T pow(const T& x, const T& n) {
      return std::pow(x, n);
    }

    template<typename T>
    T exp(const T& v) {
      return std::exp(v);
    }

    template<typename T>
    T ceil(const T& v) {
      return std::ceil(v);
    }

    template<typename T>
    T floor(const T& v) {
      return std::floor(v);
    }

    template<typename T>
    T sin(const T& v) {
      return std::sin(v);
    }

    template<typename T>
    T cos(const T& v) {
      return std::cos(v);
    }

    template<typename T>
    T tan(const T& v) {
      return std::tan(v);
    }

    template<typename T>
    constexpr T fmod(const T& v, const T& d) {
      return std::fmod(v, d);
    }
  }

  namespace cste {
    template<typename T>
    constexpr T sqrt(const T& v) {
      if(v == T(0)) {
        return v;
      }

      T r = v;
      // A lazy newton-rhapson for now.
      while(1) {
        T tmp = T(0.5) * (r + v / r); 
        if(tmp == r) {
          break;
        }
        r = tmp;
      }

      return r;
    }

    template<typename T>
    constexpr T pow(const T& x, const T& n) {
      assert(false);
    }

    template<typename T>
    constexpr T exp(const T& v) {
      assert(false);
    }

    template<typename T>
    constexpr T ceil(const T& v) {
      assert(false);
    }

    template<typename T>
    constexpr T floor(const T& v) {
      return static_cast<T>(static_cast<long long>(v));
    }

    template<typename T>
    constexpr T sin(const T& v) {
      assert(false);
    }

    template<typename T>
    constexpr T cos(const T& v) {
      assert(false);
    }

    template<typename T>
    constexpr T tan(const T& v) {
      return sin(v) / cos(v);
    }

    template<typename T>
    constexpr T fmod(const T& v, const T& d) {
      return v - floor(v / d) * d;
    }

  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT abs(const ScalarT& v) {
    return v < ScalarT(0) ? -v : v;
  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT ceil(const ScalarT& v) {
    assert(false);
  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT exp(const ScalarT& v) {
    if constexpr(!is_ct(f)) {
      return non_cste::exp(v);
    }
    else {
      // TODO: find a better algorithm please!
      return cste::exp(v);
    }
  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT floor(const ScalarT& v) {
    if constexpr(!is_ct(f)) {
      return non_cste::floor(v);
    }
    else {
      return cste::floor(v);
    }
  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT fmod(const ScalarT& v, const ScalarT& d) {
    return v - floor<f>(v / d) * d;
  }

  template<Flags f = 0, typename ScalarT>
  constexpr ScalarT pow(const ScalarT& x, const ScalarT& n) {
    if constexpr(!is_ct(f)) {
      return non_cste::pow(x, n);
    }
    else {
      return cste::pow(x, n);
    }
  }  

  template<Flags f = 0, typename T>
  constexpr T sqrt(const T& v) {
    if constexpr(!is_ct(f)) {
      return non_cste::sqrt(v);
    }
    else {
      return cste::sqrt(v);
    }
  }
}
#endif