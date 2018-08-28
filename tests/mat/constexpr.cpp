#include "catch.hpp"

#include "vecpp/vecpp.h"

TEST_CASE("Can create identity matrix", "[mat_constexpr]") {
  constexpr auto a = vecpp::Mat<float, 4, 4>::identity;
  (void)a;
}
