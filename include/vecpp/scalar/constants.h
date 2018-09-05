//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_SCALAR_CONSTANTS_H_INCLUDED
#define VECPP_SCALAR_CONSTANTS_H_INCLUDED

#include "vecpp/config.h"

namespace VECPP_NAMESPACE {

template <typename Scalar>
constexpr Scalar pi = Scalar(3.1415926535897932385);

template <typename Scalar>
constexpr Scalar half_pi = pi<Scalar> / Scalar(2);

template <typename Scalar>
constexpr Scalar quarter_pi = pi<Scalar> / Scalar(4);

template <typename Scalar>
constexpr Scalar two_pi = pi<Scalar>* Scalar(2);


}  // namespace VECPP_NAMESPACE
#endif