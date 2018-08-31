#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

constexpr vecpp::Flags ct = vecpp::flags::compile_time;

TEST_CASE("constexpr sqrt", "[scalar]") {
  constexpr float x = vecpp::sqrt<ct>(16.0f);
  static_assert(x == 4.0f);
}