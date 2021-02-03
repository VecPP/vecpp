#include "doctest.h"

#include "vecpp/mat/mat.h"
#include <sstream>

TEST_CASE("Matrix static members sanity check") {
  using Mat = vecpp::Mat<float, 2, 3>;

  static_assert(std::is_same_v<Mat::value_type, float>);
  static_assert(Mat::cols == 2);
  static_assert(Mat::rows == 3);
}

TEST_CASE("Matrix default construction compiles without warning") {
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

TEST_CASE("Build mat from aggregate initialization") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    Mat a = {1, 2, 3, 4};

    CHECK(a(0, 0) == 1);
    CHECK(a(0, 1) == 2);
    CHECK(a(1, 0) == 3);
    CHECK(a(1, 1) == 4);
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a(0, 0) == 1);
    static_assert(a(0, 1) == 2);
    static_assert(a(1, 0) == 3);
    static_assert(a(1, 1) == 4);
  }
}

TEST_CASE("Mat::at() usable to access reference") {
  using Mat = vecpp::Mat<int, 2, 2>;

  {
    Mat a = {1, 2, 3, 4};

    a.at(1, 1) = 12;

    CHECK(a(1, 1) == 12.0f);
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

TEST_CASE("Mat::at() performs bounds-checking") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    const Mat a = {1, 2, 3, 4};

    CHECK(a.at(0, 0) == 1);
    CHECK_THROWS(a.at(4, 0));
    CHECK_THROWS(a.at(0, 5));
    CHECK_THROWS(a.at(5, 5));
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a.at(0, 0) == 1);

    // Intentionally does not compile:
    // static_assert(a.at(5, 5));

    CHECK_THROWS(a.at(5, 5));
  }
}

TEST_CASE("use Mat::data() to access underlying data") {
  using Mat = vecpp::Mat<int, 2, 2>;
  {
    const Mat a = {1, 2, 3, 4};

    CHECK(a.data()[0] == 1);
    CHECK(a.data()[1] == 2);
    CHECK(a.data()[2] == 3);
    CHECK(a.data()[3] == 4);
  }

  {
    constexpr Mat a = {1, 2, 3, 4};

    static_assert(a.data()[0] == 1);
    static_assert(a.data()[1] == 2);
    static_assert(a.data()[2] == 3);
    static_assert(a.data()[3] == 4);
  }
}
