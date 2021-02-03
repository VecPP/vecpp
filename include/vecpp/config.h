//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_CONFIG_H_INCLUDED
#define VECPP_CONFIG_H_INCLUDED

#include <cassert>

#ifdef _MSVC_LANG
#if _MSVC_LANG < 201703L
#error C++17 support is required
#endif
#elif __cplusplus < 201703L
#error C++17 support is required
#endif

#define VECPP_VERSION_MAJOR 0
#define VECPP_VERSION_MINOR 2
#define VECPP_VERSION_PATCH 0

#define VECPP_VERSION 020

#ifndef VECPP_NAMESPACE
#define VECPP_NAMESPACE vecpp
#endif

#endif