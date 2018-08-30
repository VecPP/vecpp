#ifndef VECPP_SCALAR_CONSTANTS_H_INCLUDED
#define VECPP_SCALAR_CONSTANTS_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {
  
  template <typename Scalar>
  constexpr Scalar pi = Scalar(3.1415926535897932385);

  template <typename Scalar>
  constexpr Scalar half_pi = pi<Scalar> / Scalar(2);

  template <typename Scalar>
  constexpr Scalar two_pi = pi<Scalar> * Scalar(2);

}
#endif