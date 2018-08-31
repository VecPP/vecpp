#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

using Catch::Matchers::WithinAbs;

constexpr vecpp::Flags ctf = vecpp::flags::compile_time;

TEST_CASE("min", "[vec_algos]") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = min(a, b);

    REQUIRE(c[0] == a[0]);
    REQUIRE(c[1] == b[1]);
    REQUIRE(c[2] == a[2]);
    REQUIRE(c[3] == b[3]);
  }

  {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = min(a, b);

    static_assert(c[0] == a[0]);
    static_assert(c[1] == b[1]);
    static_assert(c[2] == a[2]);
    static_assert(c[3] == b[3]);
  }
}

TEST_CASE("max", "[vec_algos]") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    auto c = max(a, b);

    REQUIRE(c[0] == b[0]);
    REQUIRE(c[1] == a[1]);
    REQUIRE(c[2] == b[2]);
    REQUIRE(c[3] == a[3]);
  }

  {
    constexpr Vec a = {1.0f, 1.0f, 1.0f, 4.0f};
    constexpr Vec b = {2.0f, 0.0f, 3.0f, 0.0f};

    constexpr auto c = max(a, b);

    static_assert(c[0] == b[0]);
    static_assert(c[1] == a[1]);
    static_assert(c[2] == b[2]);
    static_assert(c[3] == a[3]);
  }
}

TEST_CASE("abs", "[vec_algos]") {
  using Vec = vecpp::Vec<float, 4>;

  {
    Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    auto c = abs(a);

    REQUIRE(c[0] == 1.0f);
    REQUIRE(c[1] == 1.0f);
    REQUIRE(c[2] == 0.0f);
    REQUIRE(c[3] == 4.0f);
  }

  {
    constexpr Vec a = {1.0f, -1.0f, 0.0f, -4.0f};

    constexpr auto c = abs(a);

    static_assert(c[0] == 1.0f);
    static_assert(c[1] == 1.0f);
    static_assert(c[2] == 0.0f);
    static_assert(c[3] == 4.0f);
  }
}

TEST_CASE("length", "[vec_algos]") {
  using Vec = vecpp::Vec<float, 4>;
  {
    Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    REQUIRE_THAT(length(a), WithinAbs(0.0f, 0.00001f));
    REQUIRE_THAT(length(b), WithinAbs(1.0f, 0.00001f));
    REQUIRE_THAT(length(c), WithinAbs(std::sqrt(2.0f), 0.00001f));
  }

  {
    constexpr Vec a = {0.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec b = {1.0f, 0.0f, 0.0f, 0.0f};
    constexpr Vec c = {1.0f, -1.0f, 0.0f, 0.0f};

    static_assert(vecpp::abs(length(ct(a)) - 0.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(b)) - 1.0f) < 0.00001f);
    static_assert(vecpp::abs(length(ct(c)) - vecpp::sqrt<ctf>(2.0f)) < 0.00001f);
  }
}

TEST_CASE("cross", "[vec_algos]") {
  using Vec = vecpp::Vec<float, 3>;

  {
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

  {
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
