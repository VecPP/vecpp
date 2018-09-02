#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

using Catch::Matchers::WithinAbs;

constexpr vecpp::Flags ctf = vecpp::flags::compile_time;

template <typename V>
constexpr bool vec_close(const V& l, const V& r) {
  for (std::size_t i = 0; i < V::size(); ++i) {
    if (vecpp::abs<ctf>(l[i] - r[i]) > 0.0001) {
      return false;
    }
  }
  return true;
}

TEST_CASE("abs", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    auto c = abs(a);

    REQUIRE(c[0] == 1.0f);
    REQUIRE(c[1] == 1.0f);
    REQUIRE(c[2] == 0.0f);
    REQUIRE(c[3] == 4.0f);
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    constexpr auto c = abs(a);

    static_assert(c[0] == 1.0f);
    static_assert(c[1] == 1.0f);
    static_assert(c[2] == 0.0f);
    static_assert(c[3] == 4.0f);
  }
}

TEST_CASE("ceil", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = ceil(a);

    REQUIRE(c[0] == 1.0f);
    REQUIRE(c[1] == -1.0f);
    REQUIRE(c[2] == 2.0f);
    REQUIRE(c[3] == -1.0f);
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = ceil(ct(a));

    static_assert(c[0] == 1.0f);
    static_assert(c[1] == -1.0f);
    static_assert(c[2] == 2.0f);
    static_assert(c[3] == -1.0f);
  }
}

TEST_CASE("floor", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = floor(a);

    REQUIRE(c == Vec{1.0f, -1.0f, 1.0f, -2.0f});
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = floor(ct(a));

    static_assert(c == Vec{1.0f, -1.0f, 1.0f, -2.0f});
  }
}

TEST_CASE("fract", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = fract(a);

    REQUIRE(vec_close(c, Vec{0.0f, 0.0f, .3f, .5f}));
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = fract(ct(a));

    static_assert(vec_close(c, Vec{0.0f, 0.0f, .3f, .5f}));
  }
}

TEST_CASE("round", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    Vec c = round(a);
    Vec d = round(b);

    REQUIRE(vec_close(c, Vec{0.0f, 1.0f, 1.0f, 2.0f}));
    REQUIRE(vec_close(d, Vec{0.0f, -1.0f, -1.0f, -2.0f}));
  }

  SECTION("constexpr") {
    constexpr Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    constexpr Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    constexpr Vec c = round(ct(a));
    constexpr Vec d = round(ct(b));

    static_assert(vec_close(c, Vec{0.0f, 1.0f, 1.0f, 2.0f}));
    static_assert(vec_close(d, Vec{0.0f, -1.0f, -1.0f, -2.0f}));
  }
}

TEST_CASE("sign", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {0.0f, 1.0f, -1.0f, -0.0f};

    REQUIRE(sign(a) == Vec{1.0f, 1.0f, -1.0f, 1.0f});
  }

  SECTION("constexpr") {
    constexpr Vec a = {0.0f, 1.0f, -1.0f, -0.0f};

    static_assert(sign(ct(a)) == Vec{1.0f, 1.0f, -1.0f, 1.0f});
  }
}

TEST_CASE("trunc", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    Vec c = trunc(a);
    Vec d = trunc(b);

    REQUIRE(vec_close(c, Vec{0.0f, 0.0f, 1.0f, 1.0f}));
    REQUIRE(vec_close(d, Vec{0.0f, 0.0f, -1.0f, -1.0f}));
  }

  SECTION("constexpr") {
    constexpr Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    constexpr Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    constexpr Vec c = trunc(ct(a));
    constexpr Vec d = trunc(ct(b));

    static_assert(vec_close(c, Vec{0.0f, 0.0f, 1.0f, 1.0f}));
    static_assert(vec_close(d, Vec{0.0f, 0.0f, -1.0f, -1.0f}));
  }
}

TEST_CASE("min", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = min(a, b);

    REQUIRE(c[0] == a[0]);
    REQUIRE(c[1] == b[1]);
    REQUIRE(c[2] == a[2]);
    REQUIRE(c[3] == b[3]);
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = min(a, b);

    static_assert(c[0] == a[0]);
    static_assert(c[1] == b[1]);
    static_assert(c[2] == a[2]);
    static_assert(c[3] == b[3]);
  }
}

TEST_CASE("max", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = max(a, b);

    REQUIRE(c[0] == b[0]);
    REQUIRE(c[1] == a[1]);
    REQUIRE(c[2] == b[2]);
    REQUIRE(c[3] == a[3]);
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = max(a, b);

    static_assert(c[0] == b[0]);
    static_assert(c[1] == a[1]);
    static_assert(c[2] == b[2]);
    static_assert(c[3] == a[3]);
  }
}

TEST_CASE("mod", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;
  using iVec = vecpp::Vec<int, 4>;

  SECTION("runtime") {
    Vec a = {1.3f, 2.3f, 3.3f, 4.3f};
    Vec b = {3.0f, 3.0f, 3.0f, 3.0f};

    Vec c = mod(a, b);

    iVec ia = {1, 2, 3, 4};
    iVec ib = {3, 3, 3, 3};

    iVec ic = mod(ia, ib);

    REQUIRE(vec_close(c, Vec{1.3f, 2.3f, 0.3f, 1.3f}));
    REQUIRE(ic == iVec{1, 2, 0, 1});
  }

  SECTION("constexpr") {
    constexpr Vec a = {1.3f, 2.3f, 3.3f, 4.3f};
    constexpr Vec b = {3.0f, 3.0f, 3.0f, 3.0f};

    constexpr Vec c = mod(ct(a), ct(b));

    constexpr iVec ia = {1, 2, 3, 4};
    constexpr iVec ib = {3, 3, 3, 3};

    constexpr iVec ic = mod(ct(ia), ct(ib));

    static_assert(vec_close(c, Vec{1.3f, 2.3f, 0.3f, 1.3f}));
    static_assert(ic == iVec{1, 2, 0, 1});
  }
}

TEST_CASE("length", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 4>;

  SECTION("runtime") {
    Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    REQUIRE_THAT(length(a), WithinAbs(0.0f, 0.00001f));
    REQUIRE_THAT(length(b), WithinAbs(1.0f, 0.00001f));
    REQUIRE_THAT(length(c), WithinAbs(std::sqrt(2.0f), 0.00001f));
  }

  SECTION("constexpr") {
    constexpr Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    static_assert(vecpp::abs(length(ct(a)) - 0.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(b)) - 1.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(c)) - vecpp::sqrt<ctf>(2.0f)) <
                  0.00001f);
  }
}

TEST_CASE("cross", "[vec][algo]") {
  using Vec = vecpp::Vec<float, 3>;

  SECTION("runtime") {
    Vec unit_x = {1.0f, 0.0f, 0.0f};
    Vec unit_y = {0.0f, 1.0f, 0.0f};
    Vec unit_z = {0.0f, 0.0f, 1.0f};

    REQUIRE_THAT(length(cross(unit_x, unit_y) - unit_z),
                 WithinAbs(0.0f, 0.00001f));
    REQUIRE_THAT(length(cross(unit_z, unit_x) - unit_y),
                 WithinAbs(0.0f, 0.00001f));
    REQUIRE_THAT(length(cross(unit_y, unit_z) - unit_x),
                 WithinAbs(0.0f, 0.00001f));
  }

  SECTION("constexpr") {
    constexpr Vec unit_x = {1.0f, 0.0f, 0.0f};
    constexpr Vec unit_y = {0.0f, 1.0f, 0.0f};
    constexpr Vec unit_z = {0.0f, 0.0f, 1.0f};

    constexpr auto x_c_y = cross(unit_x, unit_y);
    constexpr auto z_c_x = cross(unit_z, unit_x);
    constexpr auto y_c_z = cross(unit_y, unit_z);

    static_assert(vecpp::abs(length(ct(x_c_y - unit_z)) - 0.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(z_c_x - unit_y)) - 0.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(y_c_z - unit_x)) - 0.0f) < 0.00001f);
  }
}
