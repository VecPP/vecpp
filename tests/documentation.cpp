#include "catch.hpp"

#include <numeric>
#include <sstream>
#include "vecpp/vecpp.h"

// Every code sample present in the documentation must be present
// here. We do not want to have any non-compiling code present in the doc.
//
// The only allowed alteration is void casting ununsed varaiables to squelch
// compiler warnings

TEST_CASE("vec/constructor.md", "[documentation]") {
  // default construction
  vecpp::Vec<float, 3> vec;

  // value-construction
  vecpp::Vec<float, 3> y_axis = {0.0f, 1.0f, 0.0f};

  // copy-construction
  vecpp::Vec<float, 3> y_axis_copy = y_axis;

  (void)vec;
  (void)y_axis_copy;
}

float sum_elements(const vecpp::Vec<float, 3>& v) {
  return std::accumulate(begin(v), end(v), 0.0f);
}

TEST_CASE("vec/begin.md", "[documentation]") {
  REQUIRE(sum_elements(vecpp::Vec<float, 3>{1.0f, 2.0f, 3.0f}) ==
          1.0f + 2.0f + 3.0f);
}

TEST_CASE("vec/op_cmp.md", "[documentation]") {
  constexpr vecpp::Vec<float, 2> a = {1.0f, 1.0f};
  constexpr vecpp::Vec<float, 2> b = {1.0f, 1.0f};
  constexpr vecpp::Vec<float, 2> c = {1.0f, 2.0f};

  static_assert(a == b);
  static_assert(a != c);
}

TEST_CASE("vec/max.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  fVec2 c = max(a, b);
  assert(c[0] == 10.0f);
  assert(c[1] == 6.0f);

  REQUIRE(c[0] == 10.0f);
  REQUIRE(c[1] == 6.0f);
}

TEST_CASE("vec/min.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  fVec2 c = min(a, b);
  assert(c[0] == 5.0f);
  assert(c[1] == 5.0f);

  REQUIRE(c[0] == 5.0f);
  REQUIRE(c[1] == 5.0f);
}

TEST_CASE("vec/op_per_mem.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  fVec2 c = a + b;

  assert(c[0] == a[0] + b[0]);
  assert(c[1] == a[1] + b[1]);

  REQUIRE(c[0] == a[0] + b[0]);
  REQUIRE(c[1] == a[1] + b[1]);
}

TEST_CASE("vec/op_per_mem_compound.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  a += b;

  assert(a[0] == 10.0f + 5.0f);
  assert(a[1] == 5.0f + 6.0f);

  REQUIRE(a[0] == 10.0f + 5.0f);
  REQUIRE(a[1] == 5.0f + 6.0f);
}

TEST_CASE("vec/unary_minus.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, -5.0f};

  fVec2 b = -a;

  assert(b[0] == -10.0f);
  assert(b[1] == 5.0f);

  REQUIRE(b[0] == -10.0f);
  REQUIRE(b[1] == 5.0f);
}

TEST_CASE("vec/scaling_compound.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};

  a *= 3.0f;

  assert(a[0] == 3.0f * 10.0f);
  assert(a[1] == 3.0f * 5.0f);

  REQUIRE(a[0] == 3.0f * 10.0f);
  REQUIRE(a[1] == 3.0f * 5.0f);
}

TEST_CASE("vec/scaling.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = a * 3.0f;

  assert(b[0] == 3.0f * 10.0f);
  assert(b[1] == 3.0f * 5.0f);

  REQUIRE(b[0] == 3.0f * 10.0f);
  REQUIRE(b[1] == 3.0f * 5.0f);
}

TEST_CASE("vec/length.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {3.0f, 0.0f};
  fVec2 b = {1.0f, 1.0f};

  assert(length(a) == 3.0f);
  assert(length(b) == std::sqrt(2.0f));

  REQUIRE(length(a) == 3.0f);
  REQUIRE(length(b) == std::sqrt(2.0f));
}

TEST_CASE("vec/dot.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {3.0f, 0.0f};
  fVec2 b = {1.0f, 1.0f};

  float dot_val = dot(a, b);
  assert(dot_val == 3.0f);
  REQUIRE(dot_val == 3.0f);
}

TEST_CASE("vec/cross.md", "[documentation]") {
  using fVec3 = vecpp::Vec<float, 3>;

  fVec3 x = {1.0f, 0.0f, 0.0f};
  fVec3 y = {0.0f, 1.0f, 0.0f};
  fVec3 z = {0.0f, 0.0f, 1.0f};

  fVec3 cross_val = cross(x, y);

  assert(length(cross_val - z) < 0.0001f);
  REQUIRE(length(cross_val - z) < 0.0001f);
}

TEST_CASE("vec/abs.md", "[documentation]") {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, -5.0f};
  fVec2 b = abs(a);

  assert(b[0] == 10.0f);
  assert(b[1] == 5.0f);

  REQUIRE(b[0] == 10.0f);
  REQUIRE(b[1] == 5.0f);
}

TEST_CASE("angle/from.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(270.0f);

  std::ostringstream stream;
  stream << angle_a << ", " << angle_b << "\n";

  REQUIRE(stream.str() == "90°, -90°\n");
}

TEST_CASE("angle/as.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle = Angle::from_deg(90.0f);

  std::ostringstream stream;
  stream << angle.as_rad() << "\n";

  REQUIRE(stream.str() == "1.5708\n");
}

TEST_CASE("angle/op_cmp.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(91.f);
  auto angle_b = Angle::from_deg(450.0f);

  assert(angle_a > angle_b);
  REQUIRE(angle_a > angle_b);
}

TEST_CASE("angle/arithmetic.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  auto angle_c = angle_a + angle_b;

  std::ostringstream stream;
  stream << angle_c << "\n";

  REQUIRE(stream.str() == "-90°\n");
}

TEST_CASE("angle/arithmetic_inplace.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  angle_a += angle_b;

  std::ostringstream stream;
  stream << angle_a << "\n";

  REQUIRE(stream.str() == "-90°\n");
}

TEST_CASE("angle/unary_minus.md", "[documentation]") {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  std::ostringstream stream;
  stream << -angle_a << " " << -angle_b << "\n";

  REQUIRE(stream.str() == "-90° 180°\n");
}

using Angle = vecpp::Angle<float>;
