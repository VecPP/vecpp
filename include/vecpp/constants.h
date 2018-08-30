//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

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