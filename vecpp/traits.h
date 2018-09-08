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

struct Scalar_traits {
  enum { force_constexpr = false };
};

template <typename T>
struct Vec_traits : public Scalar_traits {
  enum {
    align = alignof(T),
  };
};

template <typename T>
struct Mat_traits : public Scalar_traits {
  enum {
    align = alignof(T),
  };
};

template <typename Traits>
constexpr bool is_ct() {
  return Traits::force_constexpr;
}

template<typename Traits>
struct With_constexpr : public Traits {
  enum { force_constexpr = true };
};

template<typename Traits>
using Add_constexpr_t = std::conditional_t<
    is_ct<Traits>(),
    Traits,
    With_constexpr<Traits>
  >;

}  // namespace VECPP_NAMESPACE
#endif