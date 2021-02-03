#include "doctest.h"

#include "vecpp/quat/quat.h"
#include "vecpp/vec/operations.h"
#include <sstream>

using fQuat = vecpp::Quat<float>;
using fVec3 = vecpp::Vec<float, 3>;
using fAngle = vecpp::Angle<float>;


TEST_CASE("simple vector rotate") {
  fVec3 u_x = {1.0f, 0.0f, 0.0f};
  fVec3 u_y = {0.0f, 1.0f, 0.0f};
  fVec3 u_z = {0.0f, 0.0f, 1.0f};

  fQuat r_x = fQuat::angle_axis(fAngle::from_deg(90.0f), u_x);

  CHECK(norm(r_x * u_y - u_z) == doctest::Approx(0.0f));
}

TEST_CASE("angle_axis_constexp") {
  using fQuat = vecpp::Quat<float>;
  constexpr fQuat r_x =
      fQuat::angle_axis(fAngle::from_deg(90.0f), {1.0f, 0.0f, 0.0f});

  (void)r_x;
}