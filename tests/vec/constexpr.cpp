#include "catch.hpp"

#include "vecpp/vecpp.h"

TEST_CASE("constexpr construction", "[vec_constexpr]") {
  constexpr vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};

  static_assert(a[0] == 1.0f);
  static_assert(a[1] == 2.0f);
  static_assert(a[2] == 3.0f);
  static_assert(a[3] == 4.0f);
}

TEST_CASE("constexpr comparison", "[vec_constexpr]") {
  constexpr vecpp::Vec<float, 2> a = {1.0f, 2.0f};
  constexpr vecpp::Vec<float, 2> ab = {1.0f, 2.0f};
  constexpr vecpp::Vec<float, 2> b = {1.0f, 3.0f};

  static_assert(a == ab);
  static_assert(a != b);
}

constexpr float tmp_accum(vecpp::Vec<float, 4> v) {
  float total = 0.0f;
  for (auto x : v) {
    total += x;
  }
  return total;
}

TEST_CASE("constexpr iterator", "[vec_constexpr]") {
  constexpr vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};
  constexpr float total = tmp_accum(a);

  static_assert(total >= 9.9f);
}

TEST_CASE("constexpr bounds-checking", "[vec_access]") {
  constexpr vecpp::Vec<float, 4> a = {1.0f, 2.0f, 3.0f, 4.0f};
  constexpr std::size_t id = 3;

  static_assert(a.at(2) == 3.0f);
  static_assert(a.at(id) == 4.0f);
}
