#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

// These tests are known to be failing in the current build, and are confirmed
// to represent desired behavior.

// They are only built when the VECPP_BUILD_FAILING_TESTS flag is passed to 
// cmake.
namespace angle_literals_float {
constexpr vecpp::Angle<float> operator""_deg(long double v) {
  return vecpp::Angle<float>::from_deg(float(v));
}
}


using Catch::Matchers::WithinAbs;

template<typename T>
constexpr bool close_vals(const T& lhs, const T& rhs) {
  return vecpp::abs(lhs - rhs) < 0.0001f;
}


TEST_CASE("basic trig", "[angle]") {
  using namespace angle_literals_float;

  {
    REQUIRE_THAT(sin(0.0_deg), WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(sin(90.0_deg), WithinAbs(1.0f, 0.0001f));
    REQUIRE_THAT(cos(0.0_deg), WithinAbs(1.0f, 0.0001f));
    REQUIRE_THAT(cos(90.0_deg), WithinAbs(0.0f, 0.0001f));
  }

  {
    static_assert(close_vals(sin(ct(0.0_deg)), 0.0f));
    static_assert(close_vals(sin(ct(90.0_deg)), 1.0f));
    static_assert(close_vals(cos(ct(0.0_deg)), 1.0f));

    // This fails: the current implementation of the constexpr sin/cos functions 
    // are not precise enough, which is silly since we can take our time
    // to acheive as precise a value as possible.
   // static_assert(close_vals(cos(ct(90.0_deg)), 0.0f));
  }
}
