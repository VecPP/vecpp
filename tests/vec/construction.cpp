#include "catch.hpp"

#include "vecpp/vecpp.h"

#include <sstream>

TEST_CASE("Default construction compiles without warning", "[vec_construct]") {
  using Vec = vecpp::Vec<float, 2>;

  {
    Vec a;
    (void)a;
  }

  {
    // This isn't supposed to workn in constexpr
    // constexpr Vec a;
    // (void)a;
    }
}

TEST_CASE("Build vec2 from aggregate initialization", "[vec_construct]") {
  using Vec = vecpp::Vec<float, 2>;
  
  {
    Vec a = {1.0f, 2.0f};
    Vec b{1.0f, 2.0f};

    REQUIRE(a[0] == 1.0f);
    REQUIRE(a[1] == 2.0f);

    REQUIRE(a == b);
  }

  {
    constexpr Vec a = {1.0f, 2.0f};
    constexpr Vec b = {1.0f, 2.0f};

    static_assert(a[0] == 1.0f);
    static_assert(a[1] == 2.0f);
    static_assert(a == b);
  }
}

TEST_CASE("use vec in range-based for", "[vec_iterate]") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    for (auto& v : a) {
      v += 1.0f;
    }

    REQUIRE(a[0] == 1.0f + 1.0f);
    REQUIRE(a[1] == 2.0f + 1.0f);
    REQUIRE(a[2] == 3.0f + 1.0f);
    REQUIRE(a[3] == 4.0f + 1.0f);
  }

  // No constexpr equivalent
}

TEST_CASE("use const vec in range-based for", "[vec_iterate]") {
  using Vec = vecpp::Vec<float, 4>;

  {
    const Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    for (auto v : a) {
      (void)v;
    }
  }

  {
    constexpr Vec a = {1.0f, 2.0f, 3.0f, 4.0f};
    constexpr float b = [](){
      float total = 0.0f;
      for (auto v : a) {
        total += v;
      }
      return total;
    }();
    static_assert(b == (1.0f + 2.0f + 3.0f + 4.0f));
  }
}


TEST_CASE("Vec::at() performs bounds-checking", "[vec_access]") {
  using Vec = vecpp::Vec<float, 4>;
  {
    const Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    REQUIRE(a.at(0) == 1.0f);
    REQUIRE_THROWS(a.at(4));
    REQUIRE_THROWS(a.at(5));
  }

  {
    constexpr Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    static_assert(a.at(0) == 1.0f);

    // Intentionally does not compile:
    // static_assert(a.at(5)); 

    REQUIRE_THROWS(a.at(5));
  }
}


TEST_CASE("Outputs to iostream", "[vec_format]") {
  const vecpp::Vec<int, 4> a = {0, 1 , 2, 3};

  std::ostringstream stream;

  stream << a;

  REQUIRE(stream.str() == "(0, 1, 2, 3)");

  // No constexpr equivalent
}
