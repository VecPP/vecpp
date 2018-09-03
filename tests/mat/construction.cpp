#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

TEST_CASE("Matrix static members sanity check", "[mat_construct]") {
  using Mat = vecpp::Mat<float, 2, 3>;

  static_assert(std::is_same_v<Mat::value_type, float>);
  static_assert(Mat::cols == 2);
  static_assert(Mat::rows == 3);
}

TEST_CASE("Matrix default construction compiles without warning", "[mat_construct]") {
  using Mat = vecpp::Mat<float, 2, 3>;

  {
    Mat a;
    (void)a;
  }

  {
    // This isn't supposed to work in constexpr
    // constexpr Mat a;
    // (void)a;
  }
}

TEST_CASE("Build mat from aggregate initialization", "[mat_construct]") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    Mat a = {1, 2, 3, 4};

    REQUIRE(a(0, 0) == 1);
    REQUIRE(a(0, 1) == 2);
    REQUIRE(a(1, 0) == 3);
    REQUIRE(a(1, 1) == 4);
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a(0, 0) == 1);
    static_assert(a(0, 1) == 2);
    static_assert(a(1, 0) == 3);
    static_assert(a(1, 1) == 4);
  }
}

TEST_CASE("Mat::at() usable to access reference", "[mat_access]") {
  using Mat = vecpp::Mat<int, 2, 2>;

  {
    Mat a = {1, 2, 3, 4};

    a.at(1, 1) = 12;

    REQUIRE(a(1, 1) == 12.0f);
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    constexpr Mat b = [=]() {
      Mat c = a;
      c.at(1, 1) = 12;
      return c;
    }();
    static_assert(b(1, 1) == 12);
  }
}

TEST_CASE("Mat::at() performs bounds-checking", "[mat_access]") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    const Mat a = {1, 2, 3, 4};

    REQUIRE(a.at(0, 0) == 1);
    REQUIRE_THROWS(a.at(4, 0));
    REQUIRE_THROWS(a.at(0, 5));
    REQUIRE_THROWS(a.at(5, 5));
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a.at(0, 0) == 1);

    // Intentionally does not compile:
    // static_assert(a.at(5, 5));

    REQUIRE_THROWS(a.at(5, 5));
  }
}

TEST_CASE("use Mat::data() to access underlying data", "[mat_access]") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    const Mat a = {1, 2, 3, 4};

    REQUIRE(a.data()[0] == 1);
    REQUIRE(a.data()[1] == 2);
    REQUIRE(a.data()[2] == 3);
    REQUIRE(a.data()[3] == 4);
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a.data()[0] == 1);
    static_assert(a.data()[1] == 2);
    static_assert(a.data()[2] == 3);
    static_assert(a.data()[3] == 4);
  }
}
