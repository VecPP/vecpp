#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

TEST_CASE("Simple mat x vec", "[mat][vec][mul]") {
  using Vec2 = vecpp::Vec<int, 2>;
  using Vec3 = vecpp::Vec<int, 3>;

  using Mat22 = vecpp::Mat<int, 2, 2>;
  using Mat23 = vecpp::Mat<int, 2, 3>;

  REQUIRE(Mat22{1, 0, 0, 1} * Vec2{3, 4} == Vec2{3, 4});
  REQUIRE(Mat22{1, 2, 0, 1} * Vec2{3, 4} == Vec2{3, 10});
  REQUIRE(Mat23{1, 2, 0, 0, 0, 0} * Vec2{3, 4} == Vec3{3, 6, 0});
  REQUIRE(Vec3{3, 4, 1} * Mat23{1, 2, 0, 0, 0, 0} == Vec2{11, 0});

  static_assert(Mat22{1, 0, 0, 1} * Vec2{3, 4} == Vec2{3, 4});
  static_assert(Mat22{1, 2, 0, 1} * Vec2{3, 4} == Vec2{3, 10});
  static_assert(Mat23{1, 2, 0, 0, 0, 0} * Vec2{3, 4} == Vec3{3, 6, 0});
  static_assert(Vec3{3, 4, 1} * Mat23{1, 2, 0, 0, 0, 0} == Vec2{11, 0});
}

TEST_CASE("Simple mat x mat", "[mat][mul]") {
  using Mat22 = vecpp::Mat<int, 2, 2>;

  Mat22 a = {
    0, 1,
    1, 0, 
  };

  Mat22 b = {
    0, 0,
    1, 0, 
  };

  Mat22 c = {
    1, 0,
    0, 0, 
  };


  REQUIRE(a * b == c);
}
