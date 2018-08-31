#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

#include <sstream>

TEST_CASE("Static members assignment", "[vec_construct]") {
  using Vec = vecpp::Vec<float, 2>;

  static_assert(std::is_same_v<Vec::value_type, float>);
  static_assert(Vec::size() == 2);
  static_assert(std::is_same_v<std::remove_cv_t<decltype(Vec::flags)>, vecpp::Flags>);
}

TEST_CASE("Default construction compiles without warning", "[vec_construct]") {
  using Vec = vecpp::Vec<float, 2>;

  {
    Vec a;
    (void)a;
  }

  {
    // This isn't supposed to work in constexpr
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
    constexpr Vec b{1.0f, 2.0f};

    static_assert(a[0] == 1.0f);
    static_assert(a[1] == 2.0f);
    static_assert(a == b);
  }
}

TEST_CASE("Vectos transparently assign accross flags", "[vec_construct]") {
  using Vec = vecpp::Vec<float, 2>;
  using Flagged_vec = vecpp::Vec<float, 2, vecpp::flags::testing>;
  
  {
    Vec a = {1.0f, 2.0f};
    Flagged_vec b = a;

    REQUIRE(b[0] == a[0]);
    REQUIRE(b[1] == a[1]);

    REQUIRE(a == b);
  }

  {
    constexpr Vec a = {1.0f, 2.0f};
    constexpr Flagged_vec b = a;

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

TEST_CASE("Vec::at() usable to access reference", "[vec_access]") {
  using Vec = vecpp::Vec<float, 4>;
  
  {
    Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    a.at(2) = 10.0f;

    REQUIRE(a[2] == 10.0f);
  }

  {
    constexpr Vec a = {1.0f, 2.0f, 3.0f, 4.0f};
    constexpr Vec b = [](){
      Vec c = a;
      c.at(2) = 10.0f;
      return c;
    }();
    static_assert(b[2] == 10.0f);
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
