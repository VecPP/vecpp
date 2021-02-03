#include "doctest.h"

#include <sstream>

#include "vecpp/vec/vec.h"
#include "vecpp/vec/operations.h"
#include "vecpp/vec/operations_per_member.h"


template <typename V>
constexpr bool vec_close(const V& l, const V& r) {
  for (std::size_t i = 0; i < V::length; ++i) {
    if (cste::absolute(l[i] - r[i]) > 0.0001) {
      return false;
    }
  }
  return true;
}

TEST_CASE("abs") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    auto c = absolute(a);

    CHECK(c[0] == 1.0f);
    CHECK(c[1] == 1.0f);
    CHECK(c[2] == 0.0f);
    CHECK(c[3] == 4.0f);
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    constexpr auto c = absolute(a);

    static_assert(c[0] == 1.0f);
    static_assert(c[1] == 1.0f);
    static_assert(c[2] == 0.0f);
    static_assert(c[3] == 4.0f);
  }
}

TEST_CASE("ceil") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = round_up(a);

    CHECK(c[0] == 1.0f);
    CHECK(c[1] == -1.0f);
    CHECK(c[2] == 2.0f);
    CHECK(c[3] == -1.0f);
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = round_up(a);

    static_assert(c[0] == 1.0f);
    static_assert(c[1] == -1.0f);
    static_assert(c[2] == 2.0f);
    static_assert(c[3] == -1.0f);
  }
}

TEST_CASE("floor") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = round_down(a);

    CHECK(c == Vec{1.0f, -1.0f, 1.0f, -2.0f});
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = round_down(a);

    static_assert(c == Vec{1.0f, -1.0f, 1.0f, -2.0f});
  }
}

TEST_CASE("fract") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    auto c = fractional(a);

    CHECK(vec_close(c, Vec{0.0f, 0.0f, .3f, -.5f}));
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, -1.0f, 1.3f, -1.5f};

    constexpr Vec c = fractional(a);

    static_assert(vec_close(c, Vec{0.0f, 0.0f, .3f, .5f}));
  }
}

TEST_CASE("round") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    Vec c = round(a);
    Vec d = round(b);

    CHECK(vec_close(c, Vec{0.0f, 1.0f, 1.0f, 2.0f}));
    CHECK(vec_close(d, Vec{0.0f, -1.0f, -1.0f, -2.0f}));
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    constexpr Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    constexpr Vec c = round(a);
    constexpr Vec d = round(b);

    static_assert(vec_close(c, Vec{0.0f, 1.0f, 1.0f, 2.0f}));
    static_assert(vec_close(d, Vec{0.0f, -1.0f, -1.0f, -2.0f}));
  }
}

TEST_CASE("sign") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {0.0f, 1.0f, -1.0f, -0.0f};

    CHECK(sign(a) == Vec{0.0f, 1.0f, -1.0f, 0.0f});
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {0.0f, 1.0f, -1.0f, -0.0f};

    static_assert(sign(a) == Vec{0.0f, 1.0f, -1.0f, 0.0f});
  }
}

TEST_CASE("trunc") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    Vec c = truncate(a);
    Vec d = truncate(b);

    CHECK(vec_close(c, Vec{0.0f, 0.0f, 1.0f, 1.0f}));
    CHECK(vec_close(d, Vec{0.0f, 0.0f, -1.0f, -1.0f}));
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {0.1f, 0.51f, 1.3f, 1.6f};
    constexpr Vec b = {-0.1f, -0.51f, -1.3f, -1.6f};

    constexpr Vec c = truncate(a);
    constexpr Vec d = truncate(b);

    static_assert(vec_close(c, Vec{0.0f, 0.0f, 1.0f, 1.0f}));
    static_assert(vec_close(d, Vec{0.0f, 0.0f, -1.0f, -1.0f}));
  }
}

TEST_CASE("min") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = min(a, b);

    CHECK(c[0] == a[0]);
    CHECK(c[1] == b[1]);
    CHECK(c[2] == a[2]);
    CHECK(c[3] == b[3]);
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = min(a, b);

    static_assert(c[0] == a[0]);
    static_assert(c[1] == b[1]);
    static_assert(c[2] == a[2]);
    static_assert(c[3] == b[3]);
  }
}

TEST_CASE("max") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = max(a, b);

    CHECK(c[0] == b[0]);
    CHECK(c[1] == a[1]);
    CHECK(c[2] == b[2]);
    CHECK(c[3] == a[3]);
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = max(a, b);

    static_assert(c[0] == b[0]);
    static_assert(c[1] == a[1]);
    static_assert(c[2] == b[2]);
    static_assert(c[3] == a[3]);
  }
}

TEST_CASE("mod") {
  using Vec = vecpp::Vec<float, 4>;
  using iVec = vecpp::Vec<int, 4>;

  SUBCASE("runtime") {
    Vec a = {1.3f, 2.3f, 3.3f, 4.3f};
    Vec b = {3.0f, 3.0f, 3.0f, 3.0f};

    Vec c = modulo(a, b);

    iVec ia = {1, 2, 3, 4};
    iVec ib = {3, 3, 3, 3};

    iVec ic = modulo(ia, ib);

    CHECK(vec_close(c, Vec{1.3f, 2.3f, 0.3f, 1.3f}));
    CHECK(ic == iVec{1, 2, 0, 1});
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.3f, 2.3f, 3.3f, 4.3f};
    constexpr Vec b = {3.0f, 3.0f, 3.0f, 3.0f};

    constexpr Vec c = modulo(a, b);

    constexpr iVec ia = {1, 2, 3, 4};
    constexpr iVec ib = {3, 3, 3, 3};

    constexpr iVec ic = modulo(ia, ib);

    static_assert(vec_close(c, Vec{1.3f, 2.3f, 0.3f, 1.3f}));
    static_assert(ic == iVec{1, 2, 0, 1});
  }
}

/*
TEST_CASE("clamp") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, 1.0f, 5.0f, 4.0f};
    Vec b = {2.0f, -1.0f, -1.0f, 0.0f};
    Vec c = {4.0f, 4.0f, 3.0f, 0.0f};

    auto d = clamp(a, b, c);

    CHECK(d[0] == b[0]);
    CHECK(d[1] == a[1]);
    CHECK(d[2] == c[2]);
    CHECK(d[3] == b[3]);
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, 1.0f, 5.0f, 4.0f};
    constexpr Vec b = {2.0f, -1.0f, -1.0f, 0.0f};
    constexpr Vec c = {4.0f, 4.0f, 3.0f, 0.0f};

    constexpr Vec d = clamp(a, b, c);

    static_assert(d[0] == b[0]);
    static_assert(d[1] == a[1]);
    static_assert(d[2] == c[2]);
    static_assert(d[3] == b[3]);
  }
}

TEST_CASE("lerp") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {1.0f, 0.0f, 10.0f, 0.0f};
    Vec b = {2.0f, 10.0f, 1.0f, 0.0f};
    Vec c = {0.0f, 0.5f, 0.3f, 1.0f};

    auto d = lerp(a, b, c);
    auto e = lerp(a, b, 0.5f);

    CHECK(vec_close(d, Vec{1.0f, 5.0f, 7.3f, 0.0f}));
    CHECK(vec_close(e, Vec{1.5f, 5.0f, 5.5f, 0.0f}));
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {1.0f, 0.0f, 10.0f, 0.0f};
    constexpr Vec b = {2.0f, 10.0f, 1.0f, 0.0f};
    constexpr Vec c = {0.0f, 0.5f, 0.3f, 1.0f};

    constexpr Vec d = lerp(a, b, c);
    constexpr Vec e = lerp(a, b, 0.5f);

    static_assert(vec_close(d, Vec{1.0f, 5.0f, 7.3f, 0.0f}));
    static_assert(vec_close(e, Vec{1.5f, 5.0f, 5.5f, 0.0f}));
  }
}
*/

TEST_CASE("norm") {
  using Vec = vecpp::Vec<float, 4>;

  SUBCASE("runtime") {
    Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    CHECK(norm(a) == doctest::Approx(0.0f));
    CHECK(norm(b) == doctest::Approx(1.0f));
    CHECK(norm(c) == doctest::Approx(std::sqrt(2.0f)));
  }

  SUBCASE("constexpr") {
    constexpr Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    static_assert(cste::absolute(norm(a) - 0.0f) < 0.00001f);
    static_assert(cste::absolute(norm(b) - 1.0f) < 0.00001f);
    static_assert(cste::absolute(norm(c) - cste::square_root(2.0f)) < 0.00001f);
  }
}

TEST_CASE("cross") {
  using Vec = vecpp::Vec<float, 3>;

  SUBCASE("runtime") {
    Vec unit_x = {1.0f, 0.0f, 0.0f};
    Vec unit_y = {0.0f, 1.0f, 0.0f};
    Vec unit_z = {0.0f, 0.0f, 1.0f};

    CHECK(norm(cross(unit_x, unit_y) - unit_z) == doctest::Approx(0.0f));
    CHECK(norm(cross(unit_z, unit_x) - unit_y) == doctest::Approx(0.0f));
    CHECK(norm(cross(unit_y, unit_z) - unit_x) == doctest::Approx(0.0f));
  }

  SUBCASE("constexpr") {
    constexpr Vec unit_x = {1.0f, 0.0f, 0.0f};
    constexpr Vec unit_y = {0.0f, 1.0f, 0.0f};
    constexpr Vec unit_z = {0.0f, 0.0f, 1.0f};

    constexpr auto x_c_y = cross(unit_x, unit_y);
    constexpr auto z_c_x = cross(unit_z, unit_x);
    constexpr auto y_c_z = cross(unit_y, unit_z);

    static_assert(cste::absolute(norm(x_c_y - unit_z) - 0.0f) < 0.00001f);
    static_assert(cste::absolute(norm(z_c_x - unit_y) - 0.0f) < 0.00001f);
    static_assert(cste::absolute(norm(y_c_z - unit_x) - 0.0f) < 0.00001f);
  }
}
