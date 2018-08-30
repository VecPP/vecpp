#ifndef VECPP_ANGLE_OPERATIONS_H_INCLUDED
#define VECPP_ANGLE_OPERATIONS_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/angle/angle.h"

namespace VECPP_NAMESPACE {

// Trigonometry

// TODO: These placeholder taylor series expansion implementation
// are temporary, and need to be replaced with something better! 
template <typename T>
constexpr T sin(const Angle<T>& a) {
  constexpr std::array<T, 5> taylor_factors = {
    -6, 120, -5040, 362880, -39916800
  };

  T r = a.as_rad();
  T r_2 = r*r;

  T result = r;

  for(auto f : taylor_factors) {
    r *= r_2;
    result += r / f;
  }

  return result;
}

template <typename T>
constexpr T cos(const Angle<T>& a) {
  return sin(a + Angle<T>::from_rad(half_pi<T>)); 
}

template <typename T>
constexpr T tan(const Angle<T>& a) {
  return sin(a) / cos(a); 
}

}

#endif
