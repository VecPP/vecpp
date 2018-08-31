#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

namespace angle_literals_float {
constexpr vecpp::Angle<float> operator""_deg(long double v) {
  return vecpp::Angle<float>::from_deg(float(v));
}

constexpr vecpp::Angle<float> operator""_rad(long double v) {
  return vecpp::Angle<float>::from_rad(float(v));
}
}

namespace angle_literals_double {
constexpr vecpp::Angle<double> operator""_deg(long double v) {
  return vecpp::Angle<double>::from_deg(double(v));
}

constexpr vecpp::Angle<double> operator""_rad(long double v) {
  return vecpp::Angle<double>::from_rad(double(v));
}
}

using vecpp::pi;
using Catch::Matchers::WithinAbs;

using Angle = vecpp::Angle<float>;


template<typename T>
constexpr bool close_vals(const T& lhs, const T& rhs) {
  return vecpp::abs(lhs - rhs) < 0.0001f;
}

TEST_CASE("create from radians or degrees", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 0.0_rad;
    auto b = 0.0_deg;

    static_assert(std::is_same_v<decltype(a)::value_type, float>);
    static_assert(sizeof(a) == sizeof(float));

    auto c = Angle::from_rad(pi<float>);
    auto d = 180.0_deg;

    REQUIRE(a == b);
    REQUIRE(c == d);
    REQUIRE(a != c);
    REQUIRE(a != d);
  }

  {
    constexpr auto a = 0.0_rad;
    constexpr auto b = 0.0_deg;
    constexpr auto c = Angle::from_rad(pi<float>);
    constexpr auto d = 180.0_deg;

    static_assert(a == b);
    static_assert(c == d);
    static_assert(a != c);
    static_assert(a != d);
  }
}

TEST_CASE("create from double", "[angle]") {
  using namespace angle_literals_double;

  auto a = 0.0_rad;
  constexpr auto a_c = 0.0_rad;
  (void)a_c;
  static_assert(std::is_same_v<decltype(a)::value_type, double>);
  static_assert(sizeof(a) == sizeof(double));
}

TEST_CASE("copy_and_reassign", "[angle]") {
  using namespace angle_literals_float;
  {
    auto a = 10.0_deg;

    auto b = a;
    auto c = 20.0_deg;

    c = a;

    REQUIRE(b == a);
    REQUIRE(c == a);
  }

  {
    constexpr auto a = 10.0_deg;
    constexpr auto b = a;
    constexpr auto c = []() {
      auto tmp = 20.0_deg;
      tmp = a;
      return tmp;
    }();
    static_assert(b == a);
    static_assert(c == a);
  }
}

TEST_CASE("simple constraining", "[angle]") {
  using namespace angle_literals_float;
  {
    auto a = 90.0_deg;
    auto b = 450.0_deg;
    auto c = 810.0_deg;

    REQUIRE_THAT(a.as_deg(), WithinAbs(90.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(90.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(90.0f, 0.0001f));
  }

  {
    constexpr auto a = 90.0_deg;
    constexpr auto b = 450.0_deg;
    constexpr auto c = 810.0_deg;

    static_assert(vecpp::abs(a.as_deg() - 90.0f) < 0.0001f);
    static_assert(vecpp::abs(a.as_deg() - b.as_deg()) < 0.0001f);
    static_assert(vecpp::abs(a.as_deg() - c.as_deg()) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - c.as_deg()) < 0.0001f);
  }
}

TEST_CASE("negative constraining", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = -90.0_deg;
    auto b = -180.0_deg;
    auto c = -200.0_deg;
    auto d = -375.0_deg;

    REQUIRE_THAT(a.as_deg(), WithinAbs(-90.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(180.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(160.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(-15.0f, 0.0001f));
  }

  {
    constexpr auto a = -90.0_deg;
    constexpr auto b = -180.0_deg;
    constexpr auto c = -200.0_deg;
    constexpr auto d = -375.0_deg;

    static_assert(vecpp::abs(a.as_deg() - -90.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - 180.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - 160.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - -15.0f) < 0.0001f);
  }
}

TEST_CASE("negate", "[angle]") {
  {
    auto a = -Angle::from_deg(0.0f);
    auto b = -Angle::from_deg(10.0f);
    auto c = -Angle::from_deg(-10.0f);
    auto d = -Angle::from_deg(180.0f);

    REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(-10.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(10.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(180.0f, 0.0001f));
  }
  {
    constexpr auto a = -Angle::from_deg(0.0f);
    constexpr auto b = -Angle::from_deg(10.0f);
    constexpr auto c = -Angle::from_deg(-10.0f);
    constexpr auto d = -Angle::from_deg(180.0f);

    static_assert(vecpp::abs(a.as_deg() - 0.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - -10.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - 10.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - 180.0f) < 0.0001f);
  }
}

TEST_CASE("add", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 0.0_deg + 10.0_deg;
    auto b = 180.0_deg + 20.0_deg;
    auto c = -10.0_deg + 30.0_deg;
    auto d = 45.0_deg + 725.0_deg;

    REQUIRE_THAT(a.as_deg(), WithinAbs(10.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(-160.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(20.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(50.0f, 0.0001f));
  }
  {
    constexpr auto a = 0.0_deg + 10.0_deg;
    constexpr auto b = 180.0_deg + 20.0_deg;
    constexpr auto c = -10.0_deg + 30.0_deg;
    constexpr auto d = 45.0_deg + 725.0_deg;

    static_assert(vecpp::abs(a.as_deg() - 10.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - -160.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - 20.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - 50.0f) < 0.0001f);
  }
}

TEST_CASE("sub", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 0.0_deg - 10.0_deg;
    auto b = 180.0_deg - 20.0_deg;
    auto c = -10.0_deg - 30.0_deg;
    auto d = 45.0_deg - 725.0_deg;

    REQUIRE_THAT(a.as_deg(), WithinAbs(-10.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(160.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(-40.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(40.0f, 0.0001f));
  }

  {
    constexpr auto a = 0.0_deg - 10.0_deg;
    constexpr auto b = 180.0_deg - 20.0_deg;
    constexpr auto c = -10.0_deg - 30.0_deg;
    constexpr auto d = 45.0_deg - 725.0_deg;

    static_assert(vecpp::abs(a.as_deg() - -10.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - 160.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - -40.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - 40.0f) < 0.0001f);
  }
}

TEST_CASE("scale_mul", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 0.0_deg * 10.0f;
    auto b = 10.0_deg * 5.0f;
    auto c = 3.0f * 90.0_deg;

    REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(50.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(-90.0f, 0.0001f));
  }

  {
    constexpr auto a = 0.0_deg * 10.0f;
    constexpr auto b = 10.0_deg * 5.0f;
    constexpr auto c = 3.0f * 90.0_deg;

    static_assert(vecpp::abs(a.as_deg() - 0.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - 50.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - -90.0f) < 0.0001f);
  }
}

TEST_CASE("scale_div", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 0.0_deg / 10.0f;
    auto b = 10.0_deg / 5.0f;
    auto c = 90.0_deg / 3.0f;
    auto d = 125.0_deg / 0.5f;

    REQUIRE_THAT(a.as_deg(), WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(b.as_deg(), WithinAbs(2.0f, 0.0001f));
    REQUIRE_THAT(c.as_deg(), WithinAbs(30.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(-110.0f, 0.0001f));
  }
  {
    constexpr auto a = 0.0_deg / 10.0f;
    constexpr auto b = 10.0_deg / 5.0f;
    constexpr auto c = 90.0_deg / 3.0f;
    constexpr auto d = 125.0_deg / 0.5f;

    static_assert(vecpp::abs(a.as_deg() - 0.0f) < 0.0001f);
    static_assert(vecpp::abs(b.as_deg() - 2.0f) < 0.0001f);
    static_assert(vecpp::abs(c.as_deg() - 30.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - -110.0f) < 0.0001f);
  }
}

TEST_CASE("minmax", "[angle]") {
  using namespace angle_literals_float;

  {
    auto a = 10.0_deg;
    auto b = -10.0_deg;

    auto c = std::min(a, b);
    auto d = std::max(a, b);

    REQUIRE_THAT(c.as_deg(), WithinAbs(-10.0f, 0.0001f));
    REQUIRE_THAT(d.as_deg(), WithinAbs(10.0f, 0.0001f));
  }

  {
    constexpr auto a = 10.0_deg;
    constexpr auto b = -10.0_deg;

    constexpr auto c = std::min(a, b);
    constexpr auto d = std::max(a, b);

    static_assert(vecpp::abs(c.as_deg() - -10.0f) < 0.0001f);
    static_assert(vecpp::abs(d.as_deg() - 10.0f) < 0.0001f);
  }
}

TEST_CASE("basic trig", "[angle]") {
  using namespace angle_literals_float;

  {
    REQUIRE_THAT(sin(0.0_deg), WithinAbs(0.0f, 0.0001f));
    REQUIRE_THAT(sin(90.0_deg), WithinAbs(1.0f, 0.0001f));
    REQUIRE_THAT(cos(0.0_deg), WithinAbs(1.0f, 0.0001f));
    REQUIRE_THAT(cos(90.0_deg), WithinAbs(0.0f, 0.0001f));
  }

  {
    static_assert(close_vals(sin(ct(0.0_deg)), 0.0f));
    static_assert(close_vals(sin(ct(90.0_deg)), 1.0f));
    static_assert(close_vals(cos(ct(0.0_deg)), 1.0f));
  }
}
