#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

TEST_CASE("Default construction compiles without warning", "[mat_construct]") {
  vecpp::Mat<float, 4, 4> a;
  (void)a;
}

TEST_CASE("Can create zero matrix", "[mat_construct]") {
  using Mat = vecpp::Mat<float, 4, 4>;
  auto a = vecpp::zero<Mat>;

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      REQUIRE(a[i][j] == 0.0f);
    }
  }
}

TEST_CASE("Can create identity matrix", "[mat_construct]") {
  using Mat = vecpp::Mat<float, 4, 4>;

  auto a = vecpp::identity<Mat>;

  REQUIRE(a * a == a);
}
