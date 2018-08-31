//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_FLAGS_H_INCLUDED
#define VECPP_FLAGS_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {

  using Flags = int;

  namespace flags {
    // Force usage of slower, but constexpr-friendly compile-time algorithms.
    constexpr int compile_time = 1;

    // Has no impact whatsoever, only used in testing
    constexpr int testing = 0x80000000;
  }

  constexpr bool is_ct(Flags f) {
    return f && flags::compile_time != 0;
  }

  
}
#endif