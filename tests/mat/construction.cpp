#include "catch.hpp"

#include "vecpp/vecpp.h"

TEST_CASE("Default construction compiles without warning", "[mat_construct]") {
  vecpp::Mat<float, 4, 4> a;
  (void)a;
}

TEST_CASE("Can create zero matrix", "[mat_construct]") {
  auto a = vecpp::Mat<float, 4, 4>::zero;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      REQUIRE(a[i][j] == 0.0f);
    }
  }
}

TEST_CASE("Can create identity matrix", "[mat_construct]") {
  auto a = vecpp::Mat<float, 4, 4>::identity;

  REQUIRE(a * a == a);
}
