#ifndef VECPP_CONSTANTS_H_INCLUDED
#define VECPP_CONSTANTS_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {
  // Tyoe-dependant constants
  template<typename T>
  constexpr T identity = T::make_identity();

  template<typename T>
  constexpr T zero = T::make_zero();
}
#endif