#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

namespace angle_literals_float {
constexpr vecpp::Angle<float> operator""_deg(long double v) {
  return vecpp::Angle<float>::from_deg(float(v));
}

constexpr vecpp::Angle<float> operator""_rad(long double v) {
  return vecpp::Angle<float>::from_rad(float(v));
}
}

namespace angle_literals_double {
constexpr vecpp::Angle<double> operator""_deg(long double v) {
  return vecpp::Angle<double>::from_deg(double(v));
}

constexpr vecpp::Angle<double> operator""_rad(long double v) {
  return vecpp::Angle<double>::from_rad(double(v));
}
}

using vecpp::pi;
using Catch::Matchers::WithinAbs;

using Angle = vecpp::Angle<float>;

TEST_CASE("create from radians or degrees", "[angle]") {
  using namespace angle_literals_float;

  auto a = 0.0_rad;
  auto b = 0.0_deg;

  static_assert(std::is_same_v<decltype(a)::value_type, float>);
  static_assert(sizeof(a) == sizeof(float));

  auto c = Angle::from_rad(pi<float>);
  auto d = 180.0_deg;

  REQUIRE(a == b);
  REQUIRE(c == d);
  REQUIRE(a != c);
  REQUIRE(a != d);
}

TEST_CASE("create from double", "[angle]") {
  using namespace angle_literals_double;

  auto a = 0.0_rad;
  static_assert(std::is_same_v<decltype(a)::value_type, double>);
  static_assert(sizeof(a) == sizeof(double));
}

TEST_CASE("copy_and_reassign", "[angle]") {
  using namespace angle_literals_float;
  auto a = 10.0_deg;

  auto b = a;
  auto c = 20.0_deg;

  c = a;

  REQUIRE(b == a);
  REQUIRE(c == a);
}

TEST_CASE("simple constraining", "[angle]") {
  using namespace angle_literals_float;
  auto a = 90.0_deg;
  auto b = 450.0_deg;
  auto c = 810.0_deg;

  REQUIRE_THAT(a.as_deg(), WithinAbs(90.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(90.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(90.0f, 0.0001f));
}

TEST_CASE("negative constraining", "[angle]") {
  using namespace angle_literals_float;
  auto a = -90.0_deg;
  auto b = -180.0_deg;
  auto c = -200.0_deg;
  auto d = -375.0_deg;

  REQUIRE_THAT(a.as_deg(), WithinAbs(-90.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(180.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(160.0f, 0.0001f));
  REQUIRE_THAT(d.as_deg(), WithinAbs(-15.0f, 0.0001f));
}

TEST_CASE("negate", "[angle]") {
  auto a = -Angle::from_deg(0.0f);
  auto b = -Angle::from_deg(10.0f);
  auto c = -Angle::from_deg(-10.0f);
  auto d = -Angle::from_deg(180.0f);

  REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(-10.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(10.0f, 0.0001f));
  REQUIRE_THAT(d.as_deg(), WithinAbs(180.0f, 0.0001f));
}

TEST_CASE("add", "[angle]") {
  using namespace angle_literals_float;

  auto a = 0.0_deg + 10.0_deg;
  auto b = 180.0_deg + 20.0_deg;
  auto c = -10.0_deg + 30.0_deg;
  auto d = 45.0_deg + 725.0_deg;

  REQUIRE_THAT(a.as_deg(), WithinAbs(10.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(-160.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(20.0f, 0.0001f));
  REQUIRE_THAT(d.as_deg(), WithinAbs(50.0f, 0.0001f));
}

TEST_CASE("sub", "[angle]") {
  using namespace angle_literals_float;

  auto a = 0.0_deg - 10.0_deg;
  auto b = 180.0_deg - 20.0_deg;
  auto c = -10.0_deg - 30.0_deg;
  auto d = 45.0_deg - 725.0_deg;

  REQUIRE_THAT(a.as_deg(), WithinAbs(-10.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(160.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(-40.0f, 0.0001f));
  REQUIRE_THAT(d.as_deg(), WithinAbs(40.0f, 0.0001f));
}

TEST_CASE("scale_mul", "[angle]") {
  using namespace angle_literals_float;

  auto a = 0.0_deg * 10.0f;
  auto b = 10.0_deg * 5.0f;
  auto c = 90.0_deg * 3.0f;

  REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(50.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(-90.0f, 0.0001f));
}

TEST_CASE("scale_div", "[angle]") {
  using namespace angle_literals_float;

  auto a = 0.0_deg * 10.0f;
  auto b = 10.0_deg * 5.0f;
  auto c = 90.0_deg * 3.0f;

  REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
  REQUIRE_THAT(b.as_deg(), WithinAbs(50.0f, 0.0001f));
  REQUIRE_THAT(c.as_deg(), WithinAbs(-90.0f, 0.0001f));
}

TEST_CASE("minmax", "[angle]") {
  using namespace angle_literals_float;

  auto a = 10.0_deg;
  auto b = -10.0_deg;

  auto c = std::min(a, b);
  auto d = std::max(a, b);

  REQUIRE_THAT(c.as_deg(), WithinAbs(-10.0f, 0.0001f));
  REQUIRE_THAT(d.as_deg(), WithinAbs(10.0f, 0.0001f));
}

TEST_CASE("constexpr usage", "[angle]") {
  using namespace angle_literals_float;

  constexpr Angle a = 30.0_deg;
  constexpr Angle b = 90.0_deg;

  static_assert((3.0f * a - b).as_deg() < 0.0001f);
}