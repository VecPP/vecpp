#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

using Catch::Matchers::WithinAbs;

TEST_CASE("Matrix transpose", "[mat]") {
  using Mat2 = vecpp::Mat<int, 2, 2>;

  REQUIRE(transpose(Mat2{1, 2, 3, 4}) == Mat2{1, 3, 2, 4});

  static_assert(transpose(Mat2{1, 2, 3, 4}) == Mat2{1, 3, 2, 4});
}

TEST_CASE("Large matrix determinant", "[mat]") {
  using Mat3 = vecpp::Mat<float, 3, 3>;
  using Mat4 = vecpp::Mat<float, 4, 4>;
  using Mat5 = vecpp::Mat<float, 5, 5>;

  // clang-format off
  Mat3 mat3 = {
    1.0f, 5.0f, 1.0f, 
    4.0f, 0.0f, 0.0f, 
    3.0f, 1.0f, 2.0f 
  };
  
  Mat4 mat4 = {
     0.0f, 3.0f, 5.0f, 1.0f,
     1.0f, 5.0f, 1.0f, 0.0f,
     4.0f, 0.0f, 0.0f, 2.0f,
     3.0f, 1.0f, 2.0f, 0.0f
  };

  Mat5 mat5 = {
    1.0f, 0.0f, 3.0f, 5.0f, 1.0f, 
    0.0f, 1.0f, 5.0f, 1.0f, 0.0f, 
    0.0f, 4.0f, 0.0f, 0.0f, 2.0f, 
    2.0f, 3.0f, 1.0f, 2.0f, 0.0f, 
    1.0f, 0.0f, 0.0f, 1.0f, 1.0f};
  // clang-format on

  REQUIRE_THAT(determinant(mat3), WithinAbs(-36.0f, 0.001f));
  REQUIRE_THAT(determinant(mat4), WithinAbs(170.0f, 0.001f));
  REQUIRE_THAT(determinant(mat5), WithinAbs(230.0f, 0.001f));
}
