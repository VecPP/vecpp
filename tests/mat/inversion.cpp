#include "doctest.h"

#include "vecpp/mat/mat.h"
#include "vecpp/mat/inverse.h"

TEST_CASE("Simple 2x2 mat inversion") {
  using Mat2 = vecpp::Mat<float, 2, 2>;

  Mat2 m = {
    4, 7,
    2, 6
  };

  CHECK(vecpp::is_invertible(m));
  auto inverted = inverse(m);

  CHECK(inverted(0, 0) == doctest::Approx(0.6f));
  CHECK(inverted(0, 1) == doctest::Approx(-0.7f));
  CHECK(inverted(1, 0) == doctest::Approx(-0.2f));
  CHECK(inverted(1, 1) == doctest::Approx(0.4f));
}


TEST_CASE("Simple 3x3 mat inversion") {
  using Mat3 = vecpp::Mat<float, 3, 3>;

  Mat3 m = {
    3, 0, 2,
    2, 0, -2,
    0, 1, 1
  };

  CHECK(vecpp::is_invertible(m));
  auto inverted = inverse(m);

  Mat3 expected_m = {
    0.2f, 0.2f, 0.0f,
    -0.2f, 0.3f, 1.0f,
    0.2f, -0.3f, 0.0f
  };

  for(int i = 0 ; i < 3; ++i) {
    for(int j = 0 ; j < 3; ++j) {
      CHECK(inverted(i, j) == doctest::Approx(expected_m(i, j)));    
    }
  }
}