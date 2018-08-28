#ifndef VECPP_MAT_H_INCLUDED
#define VECPP_MAT_H_INCLUDED

#include "vecpp/config.h"
#include "vecpp/vec.h"

#include <array>
#include <cstddef>

namespace VECPP_NAMESPACE {

// We could technically provide sane-ish defaults for most functions,
template <typename T, std::size_t col_count, std::size_t row_count>
struct Mat {
  using value_type = T;
  using col_type = Vec<T, row_count>;

  constexpr col_type& operator[](std::size_t i) { return data_[i]; }
  constexpr const col_type& operator[](std::size_t i) const { return data_[i]; }

  col_type* data() { return data_.data(); }
  const col_type* data() const { return data_.data(); }

  static constexpr Mat make_identity();

  static constexpr Mat identity = make_identity();
  static constexpr Mat zero = {T(0)};


  // Left public for aggregate initialization.
  std::array<col_type, col_count> data_;
};

// Comparisons
template <typename T, std::size_t C, std::size_t R>
constexpr bool operator==(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs) {
  for (std::size_t i = 0; i < C; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, std::size_t C, std::size_t R>
constexpr bool operator!=(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs) {
  for (std::size_t i = 0; i < C; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

template <typename T, std::size_t col_count, std::size_t row_count>
constexpr Mat<T, col_count, row_count>
Mat<T, col_count, row_count>::make_identity() {
  Mat<T, col_count, row_count> result = zero;

  for (std::size_t i = 0; i < std::min(col_count, row_count); ++i) {
    result[i][i] = T(1);
  }

  return result;
}
}
#endif