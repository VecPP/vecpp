#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/single_header.h"
#else
#include "vecpp/vecpp.h"
#endif

TEST_CASE("Can create identity matrix", "[mat_constexpr]") {
  constexpr auto a = vecpp::identity<vecpp::Mat<float, 4, 4>>;
  (void)a;
}
