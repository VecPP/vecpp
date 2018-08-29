#ifndef VECPP_CONFIG_H_INCLUDED
#define VECPP_CONFIG_H_INCLUDED

#if __cplusplus < 201703L
#error "vecpp requires c++17"
#endif

#define VECPP_VERSION_MAJOR 0
#define VECPP_VERSION_MINOR 0
#define VECPP_VERSION_PATCH 1

#define VECPP_VERSION 001

#ifndef VECPP_NAMESPACE
#define VECPP_NAMESPACE vecpp
#endif

#endif