#include "doctest.h"

#include "vecpp/vec/vec.h"
#include <sstream>

TEST_CASE("Static members assignment") {
  using Vec = vecpp::Vec<float, 2>;

  static_assert(std::is_same_v<Vec::value_type, float>);
  static_assert(Vec::length == 2);
}

TEST_CASE("Default construction compiles without warning") {
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

TEST_CASE("Build vec2 from aggregate initialization") {
  using Vec = vecpp::Vec<float, 2>;

  {
    Vec a = {1.0f, 2.0f};
    Vec b{1.0f, 2.0f};

    CHECK(a[0] == 1.0f);
    CHECK(a[1] == 2.0f);

    CHECK(a == b);
  }

  {
    constexpr Vec a = {1.0f, 2.0f};
    constexpr Vec b{1.0f, 2.0f};

    static_assert(a[0] == 1.0f);
    static_assert(a[1] == 2.0f);
    static_assert(a == b);
  }
}

TEST_CASE("use vec in range-based for") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    for (auto& v : a) {
      v += 1.0f;
    }

    CHECK(a[0] == 1.0f + 1.0f);
    CHECK(a[1] == 2.0f + 1.0f);
    CHECK(a[2] == 3.0f + 1.0f);
    CHECK(a[3] == 4.0f + 1.0f);
  }

  constexpr float total = []() {
    constexpr Vec b = {1.0f, 2.0f, 3.0f, 4.0f};
    float t = 0.0f;
    for (auto& v : b) {
      t += v;
    }
    return t;
  }();

  static_assert(total == 1.0f + 2.0f + 3.0f + 4.0f);

}

TEST_CASE("use const vec in range-based for") {
  using Vec = vecpp::Vec<float, 4>;

  {
    const Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    for (auto v : a) {
      (void)v;
    }
  }
}

TEST_CASE("Vec::at() usable to access reference") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    a.at(2) = 10.0f;

    CHECK(a[2] == 10.0f);
  }

  {
    constexpr Vec a = {1.0f, 2.0f, 3.0f, 4.0f};
    constexpr Vec b = [=]() {
      Vec c = a;
      c.at(2) = 10.0f;
      return c;
    }();
    static_assert(b[2] == 10.0f);
  }
}

TEST_CASE("Vec::at() performs bounds-checking") {
  using Vec = vecpp::Vec<float, 4>;
  {
    const Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    CHECK(a.at(0) == 1.0f);
    CHECK_THROWS(a.at(4));
    CHECK_THROWS(a.at(5));
  }

  {
    constexpr Vec a = {1.0f, 2.0f, 3.0f, 4.0f};

    static_assert(a.at(0) == 1.0f);

    // Intentionally does not compile:
    // static_assert(a.at(5));

    CHECK_THROWS(a.at(5));
  }
}

TEST_CASE("Outputs to iostream") {
  const vecpp::Vec<int, 4> a = {0, 1, 2, 3};

  std::ostringstream stream;

  stream << a;

  CHECK(stream.str() == "(0, 1, 2, 3)");

  // No constexpr equivalent
}
