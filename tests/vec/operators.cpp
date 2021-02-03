#include "doctest.h"

#include <sstream>
#include "vecpp/vec/vec.h"

using Vec = vecpp::Vec<int, 2>;

TEST_CASE("vecs compare") {
  CHECK(Vec{1, 1} == Vec{1, 1});
  CHECK(Vec{1, 1} != Vec{1, 2});

  static_assert(Vec{1, 1} == Vec{1, 1});
  static_assert(Vec{1, 1} != Vec{1, 2});
}

TEST_CASE("vecs add") {
  CHECK(Vec{1, 2} + Vec{3, 4} == Vec{4, 6});
  static_assert(Vec{1, 2} + Vec{3, 4} == Vec{4, 6});

  {
    Vec a = {2, 2};
    a += {2, 3};

    CHECK(a == Vec{4, 5});
  }

  {
    constexpr Vec a = {2, 2};
    constexpr Vec b = [=]() {
      Vec c = a;
      c += {2, 3};
      return c;
    }();

    static_assert(b == Vec{4, 5});
  }
}

TEST_CASE("vecs sub") {
  CHECK(Vec{1, 2} - Vec{3, 4} == Vec{-2, -2});
  static_assert(Vec{1, 2} - Vec{3, 4} == Vec{-2, -2});

  {
    Vec a = {2, 2};
    a -= {2, 3};

    CHECK(a == Vec{0, -1});
  }

  {
    constexpr Vec a = {2, 2};
    constexpr Vec b = [=]() {
      Vec c = a;
      c -= {2, 3};
      return c;
    }();

    static_assert(b == Vec{0, -1});
  }
}

TEST_CASE("vecs per-member mul") {
  CHECK(Vec{1, 2} * Vec{3, 4} == Vec{3, 8});
  static_assert(Vec{1, 2} * Vec{3, 4} == Vec{3, 8});
  {
    Vec a = {2, 2};
    a *= {2, 3};

    CHECK(a == Vec{4, 6});
  }

  {
    constexpr Vec a = {2, 2};
    constexpr Vec b = [=]() {
      Vec c = a;
      c *= {2, 3};
      return c;
    }();

    static_assert(b == Vec{4, 6});
  }
}

TEST_CASE("vecs per-member div") {
  CHECK(Vec{10, 9} / Vec{4, 3} == Vec{2, 3});
  static_assert(Vec{10, 9} / Vec{4, 3} == Vec{2, 3});

  {
    Vec a = {2, 3};
    a /= {2, 3};

    CHECK(a == Vec{1, 1});
  }
  {
    constexpr Vec a = {2, 3};
    constexpr Vec b = [=]() {
      Vec c = a;
      c /= {2, 3};
      return c;
    }();

    static_assert(b == Vec{1, 1});
  }
}

TEST_CASE("vecs negate") {
  CHECK(-Vec{10, 9} == Vec{-10, -9});
  static_assert(-Vec{10, 9} == Vec{-10, -9});
}
