#include "catch.hpp"

#include "vecpp/vecpp.h"

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
