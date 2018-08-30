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

  template<typename ScalarT>
  constexpr ScalarT sqrt(const ScalarT& v) {
    assert(false);
  }

  
}
#endif