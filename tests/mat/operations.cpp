#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

TEST_CASE("Matrix transpose", "[mat_ops]") {

  using Mat2 = vecpp::Mat<int, 2, 2>;

  REQUIRE(transpose(Mat2{1, 2, 3, 4}) == Mat2{1, 3, 2, 4});

  static_assert(transpose(Mat2{1, 2, 3, 4}) == Mat2{1, 3, 2, 4});
}
