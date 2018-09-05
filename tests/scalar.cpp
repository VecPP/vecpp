#include "catch.hpp"

#ifdef VECPP_TEST_SINGLE_HEADER
#include "vecpp/vecpp_single.h"
#else
#include "vecpp/vecpp.h"
#endif

using ctf = vecpp::Add_constexpr_t<vecpp::Scalar_traits>;


// Check that Add_constexpr_t properly does nothing when redundant
using ctf_2 = vecpp::Add_constexpr_t<ctf>;
static_assert(std::is_same_v<ctf, ctf_2>);


TEST_CASE("constexpr sqrt", "[scalar]") {
  constexpr float x = vecpp::sqrt<ctf>(16.0f);
  static_assert(x == 4.0f);
}