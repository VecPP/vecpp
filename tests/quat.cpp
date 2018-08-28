#include "catch.hpp"

#include "vecpp/vecpp.h"

using fQuat = vecpp::Quat<float>;
using fVec3 = vecpp::Vec<float, 3>;
using fAngle = vecpp::Angle<float>;

using Catch::Matchers::WithinAbs;

TEST_CASE("simple vector rotate", "[quat]") {
  fVec3 u_x = {1.0f, 0.0f, 0.0f};
  fVec3 u_y = {0.0f, 1.0f, 0.0f};
  fVec3 u_z = {0.0f, 0.0f, 1.0f};

  fQuat r_x = fQuat::angle_axis(fAngle::from_deg(90.0f), u_x);

  REQUIRE_THAT(length(r_x * u_y - u_z), WithinAbs(0.0f, 0.0001f));
}
