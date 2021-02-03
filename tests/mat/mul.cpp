#include "doctest.h"

#include "vecpp/mat/mat.h"
#include "vecpp/mat/mul.h"

TEST_CASE("Simple mat x vec") {
  using Vec2 = vecpp::Vec<int, 2>;
  using Vec3 = vecpp::Vec<int, 3>;

  using Mat22 = vecpp::Mat<int, 2, 2>;
  using Mat23 = vecpp::Mat<int, 2, 3>;

  CHECK(Mat22{1, 0, 0, 1} * Vec2{3, 4} == Vec2{3, 4});
  CHECK(Mat22{1, 2, 0, 1} * Vec2{3, 4} == Vec2{3, 10});
  CHECK(Mat23{1, 2, 0, 0, 0, 0} * Vec2{3, 4} == Vec3{3, 6, 0});
  CHECK(Vec3{3, 4, 1} * Mat23{1, 2, 0, 0, 0, 0} == Vec2{11, 0});

  static_assert(Mat22{1, 0, 0, 1} * Vec2{3, 4} == Vec2{3, 4});
  static_assert(Mat22{1, 2, 0, 1} * Vec2{3, 4} == Vec2{3, 10});
  static_assert(Mat23{1, 2, 0, 0, 0, 0} * Vec2{3, 4} == Vec3{3, 6, 0});
  static_assert(Vec3{3, 4, 1} * Mat23{1, 2, 0, 0, 0, 0} == Vec2{11, 0});
}

TEST_CASE("Simple mat x mat") {
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


  CHECK(a * b == c);
}
