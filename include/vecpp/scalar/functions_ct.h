//  Copyright 2020 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)


#ifndef VECPP_SCALAR_FUNCTIONS_CT_H_INCLUDED
#define VECPP_SCALAR_FUNCTIONS_CT_H_INCLUDED

#include "vecpp/config.h"

/*
namespace VECPP_NAMESPACE::ct {
// ************************** Misc Functions ************************** //
template <typename T>
constexpr T sign(const T& v);
template <typename T>
constexpr bool is_nan(const T& v);
template <typename T>
constexpr bool is_inf(const T& v);

// ************************** Rounding Functions ************************** //
template <typename T>
constexpr T absolute(const T& v);
template <typename T>
constexpr T fractional(const T& v);
template <typename T>
constexpr T round(const T& v);
template <typename T>
constexpr T round_down(const T& v);
template <typename T>
constexpr T round_up(const T& v);
template <typename T>
constexpr T truncate(const T& v);

// ************************ Trigonometry Functions ************************ //
template <typename T>
constexpr T sine(const T&);
template <typename T>
constexpr T cosine(const T&);
template <typename T>
constexpr T tangent(const T&);

// ************************** Calculus Functions ************************** //
template <typename T>
constexpr T exponential(const T& v);
template <typename T>
constexpr T modulo(const T& val, const T& div);
template <typename T, typename U>
constexpr T power(const T& v, const U& p);
template <typename T>
constexpr T square_root(const T& v);
}  // namespace VECPP_NAMESPACE::ct

*/
#include "vecpp/scalar/ct/calc/absolute.h"
#include "vecpp/scalar/ct/calc/exponential.h"
#include "vecpp/scalar/ct/calc/modulo.h"
#include "vecpp/scalar/ct/calc/power.h"
#include "vecpp/scalar/ct/calc/square_root.h"

#include "vecpp/scalar/ct/misc/inf_nan.h"
#include "vecpp/scalar/ct/misc/sign.h"

#include "vecpp/scalar/ct/rounding/fractional.h"
#include "vecpp/scalar/ct/rounding/round.h"
#include "vecpp/scalar/ct/rounding/round_down.h"
#include "vecpp/scalar/ct/rounding/round_up.h"
#include "vecpp/scalar/ct/rounding/truncate.h"

#include "vecpp/scalar/ct/trigonometry/cosine.h"
#include "vecpp/scalar/ct/trigonometry/sine.h"
#include "vecpp/scalar/ct/trigonometry/tangent.h"

#endif