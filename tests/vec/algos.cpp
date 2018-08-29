#include "catch.hpp"

#include "vecpp/vecpp.h"

using Catch::Matchers::WithinAbs;

TEST_CASE("min", "[vec_algos]") {
  vecpp::Vec<float, 4> a = {1.0f, 1.0f, 1.0f, 4.0f};
  vecpp::Vec<float, 4> b = {2.0f, 0.0f, 3.0f, 0.0f};

  auto c = min(a, b);

  REQUIRE(c[0] == a[0]);
  REQUIRE(c[1] == b[1]);
  REQUIRE(c[2] == a[2]);
  REQUIRE(c[3] == b[3]);
}

TEST_CASE("max", "[vec_algos]") {
  vecpp::Vec<float, 4> a = {1.0f, 1.0f, 1.0f, 4.0f};
  vecpp::Vec<float, 4> b = {2.0f, 0.0f, 3.0f, 0.0f};

  auto c = max(a, b);

  REQUIRE(c[0] == b[0]);
  REQUIRE(c[1] == a[1]);
  REQUIRE(c[2] == b[2]);
  REQUIRE(c[3] == a[3]);
}

TEST_CASE("abs", "[vec_algos]") {
  vecpp::Vec<float, 4> a = {1.0f, -1.0f, 0.0f, -4.0f};

  auto c = abs(a);

  REQUIRE(c[0] == 1.0f);
  REQUIRE(c[1] == 1.0f);
  REQUIRE(c[2] == 0.0f);
  REQUIRE(c[3] == 4.0f);
}

TEST_CASE("length", "[vec_algos]") {
  vecpp::Vec<float, 4> a = {0.0f, 0.0f, 0.0f, 0.0f};
  vecpp::Vec<float, 4> b = {1.0f, 0.0f, 0.0f, 0.0f};
  vecpp::Vec<float, 4> c = {1.0f, 1.0f, 0.0f, 0.0f};

  REQUIRE_THAT(length(a), WithinAbs(0.0f, 0.00001f));
  REQUIRE_THAT(length(b), WithinAbs(1.0f, 0.00001f));
  REQUIRE_THAT(length(c), WithinAbs(std::sqrt(2.0f), 0.00001f));
}

TEST_CASE("cross", "[vec_algos]") {
  vecpp::Vec<float, 3> unit_x = {1.0f, 0.0f, 0.0f};
  vecpp::Vec<float, 3> unit_y = {0.0f, 1.0f, 0.0f};
  vecpp::Vec<float, 3> unit_z = {0.0f, 0.0f, 1.0f};

  REQUIRE_THAT(length(cross(unit_x, unit_y) - unit_z),
               WithinAbs(0.0f, 0.00001f));
  REQUIRE_THAT(length(cross(unit_z, unit_x) - unit_y),
               WithinAbs(0.0f, 0.00001f));
  REQUIRE_THAT(length(cross(unit_y, unit_z) - unit_x),
               WithinAbs(0.0f, 0.00001f));
}
