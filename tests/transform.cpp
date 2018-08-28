#include "catch.hpp"

#include "vecpp/vecpp.h"

TEST_CASE("scaling vector", "[transform_scale]") {
  auto trans = vecpp::scale(3.0f);

  vecpp::Vec<float, 3> v = {1.0f, 2.0f, 3.0f};
  auto scaled = trans * v;

  REQUIRE(scaled[0] == 3.0f);
  REQUIRE(scaled[1] == 6.0f);
  REQUIRE(scaled[2] == 9.0f);
}

TEST_CASE("scaling vector per component", "[transform_scale]") {
  auto trans = vecpp::scale(vecpp::Vec<float, 3>{3.0f, 1.0f, 1.0f});

  vecpp::Vec<float, 3> v = {1.0f, 2.0f, 3.0f};
  auto scaled = trans * v;

  REQUIRE(scaled[0] == 3.0f);
  REQUIRE(scaled[1] == 2.0f);
  REQUIRE(scaled[2] == 3.0f);
}
