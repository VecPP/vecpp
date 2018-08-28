#include "catch.hpp"

#include "vecpp/vecpp.h"

using Vec = vecpp::Vec<int, 2>;

TEST_CASE("vecs compare", "[vec_operators]") {
  REQUIRE(Vec{1, 1} == Vec{1, 1});
  REQUIRE(Vec{1, 1} != Vec{1, 2});
}

TEST_CASE("vecs add", "[vec_operators]") {
  REQUIRE(Vec{1, 2} + Vec{3, 4} == Vec{4, 6});

  Vec a = {2, 2};
  a += {2, 3};

  REQUIRE(a == Vec{4, 5});
}

TEST_CASE("vecs sub", "[vec_operators]") {
  REQUIRE(Vec{1, 2} - Vec{3, 4} == Vec{-2, -2});

  Vec a = {2, 2};
  a -= {2, 3};

  REQUIRE(a == Vec{0, -1});
}

TEST_CASE("vecs per-member mul", "[vec_operators]") {
  REQUIRE(Vec{1, 2} * Vec{3, 4} == Vec{3, 8});

  Vec a = {2, 2};
  a *= {2, 3};

  REQUIRE(a == Vec{4, 6});
}

TEST_CASE("vecs per-member div", "[vec_operators]") {
  REQUIRE(Vec{10, 9} / Vec{4, 3} == Vec{2, 3});

  Vec a = {2, 3};
  a /= {2, 3};

  REQUIRE(a == Vec{1, 1});
}

TEST_CASE("vecs negate", "[vec_operators]") {
  REQUIRE(-Vec{10, 9} == Vec{-10, -9});
}
