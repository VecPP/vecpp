#include "catch.hpp"

#include "vecpp/vecpp.h"

TEST_CASE("Default construction compiles without warning", "[vec_construct]") {
  vecpp::Vec<float, 2> a;
  (void)a;
}

TEST_CASE("Build vec2 from aggregate initialization", "[vec_construct]") {
  vecpp::Vec<float, 2> a = {1.0f, 2.0f};
  vecpp::Vec<float, 2> b{1.0f, 2.0f};

  REQUIRE(a[0] == 1.0f);
  REQUIRE(a[1] == 2.0f);

  REQUIRE(a == b);
}

TEST_CASE("Build vec3 from aggregate initialization", "[vec_construct]") {
  vecpp::Vec<float, 3> a = {1.0f, 2.0f, 3.0f};
  vecpp::Vec<float, 3> b{1.0f, 2.0f, 3.0f};

  REQUIRE(a[0] == 1.0f);
  REQUIRE(a[1] == 2.0f);
  REQUIRE(a[2] == 3.0f);

  REQUIRE(a == b);
}

TEST_CASE("Build vec4 from aggregate initialization", "[vec_construct]") {
  vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};
  vecpp::Vec<float, 4> b{1.0f, 2.0f, 3.0f, 4.0f};

  REQUIRE(a[0] == 1.0f);
  REQUIRE(a[1] == 2.0f);
  REQUIRE(a[2] == 3.0f);
  REQUIRE(a[3] == 4.0f);

  REQUIRE(a == b);
}

TEST_CASE("use vec in range-based for", "[vec_iterate]") {
  vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};

  for (auto v : a) {
    (void)v;
  }
}

TEST_CASE("use vec in const range-based for", "[vec_iterate]") {
  const vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};

  for (auto v : a) {
    (void)v;
  }
}


TEST_CASE("Vec::at() performs bounds-checking", "[vec_access]") {
  const vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};

  REQUIRE(a.at(0) == 1.0f);
  REQUIRE_THROWS(a.at(4));
  REQUIRE_THROWS(a.at(5));
}
