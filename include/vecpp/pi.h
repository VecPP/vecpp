#ifndef VECPP_PI_H_INCLUDED
#define VECPP_PI_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {

template <typename T = float>
constexpr T pi = T(3.1415926535897932385);

template <typename T = float>
constexpr T half_pi = pi<T> / T(2);

template <typename T = float>
constexpr T two_pi = pi<T>* T(2);
}

#endif