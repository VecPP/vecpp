//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_MAT_MAT_H_INCLUDED
#define VECPP_MAT_MAT_H_INCLUDED

#include "vecpp/config.h"
#include "vecpp/vec/vec.h"

#include <array>
#include <cassert>
#include <cstddef>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t C, std::size_t R>
struct Mat {
  static_assert(C > 0 && R > 0);

  static constexpr std::size_t rows = R;
  static constexpr std::size_t cols = C;

  using value_type = T;

  constexpr value_type& operator()(std::size_t i, std::size_t j) {
    assert(i < cols && j < rows);
    return data_[i * rows + j];
  }

  constexpr const value_type& operator()(std::size_t i, std::size_t j) const {
    assert(i < cols && j < rows);
    return data_[i * rows + j];
  }

  constexpr value_type& at(std::size_t c, std::size_t r) {
    if (c >= cols || r >= rows) {
      throw std::out_of_range("out of range matrix access");
    }
    return (*this)(c, r);
  }

  constexpr const value_type& at(std::size_t c, std::size_t r) const {
    if (c >= cols || r >= rows) {
      throw std::out_of_range("out of range matrix access");
    }
    return (*this)(c, r);
  }

  constexpr value_type* data() { return data_.data(); }

  constexpr const value_type* data() const { return data_.data(); }

  // Left public for aggregate initialization.
  std::array<value_type, cols * rows> data_;
};

template <typename T, std::size_t C, std::size_t R>
constexpr bool operator==(const Mat<T, C, R>& lhs,
                          const Mat<T, C, R>& rhs) {
  for (std::size_t i = 0; i < C; ++i) {
    for (std::size_t j = 0; j < R; ++j) {
      if (lhs(i, j) != rhs(i, j)) {
        return false;
      }
    }
  }
  return true;
}

template <typename T, std::size_t C, std::size_t R>
std::ostream& operator<<(std::ostream& stream,
                         const Mat<T, C, R>& lhs) {
  stream << "[";
  for (std::size_t i = 0; i < R; ++i) {
    stream << " ";
    for (std::size_t j = 0; j < C; ++j) {
      stream << lhs(i, j) << ",";
    }
    stream << "\n";
  }
  stream << "]";

  return stream;
}

template <typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator/(const Mat<T, C, R>& mat,
                                         const T& v) {
  Mat<T, C, R> result = {};

  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = mat(i, j) / v;
    }
  }
  return result;
}

template <typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator*(const Mat<T, C, R>& mat,
                                         const T& v) {
  Mat<T, C, R> result = {};

  for (std::size_t i = 0; i < R; ++i) {
    for (std::size_t j = 0; j < C; ++j) {
      result(i, j) = mat(i, j) * v;
    }
  }
  return result;
}

template <typename T, std::size_t C, std::size_t R>
constexpr Vec<T, R> operator*(const Mat<T, C, R>& mat,
                                        const Vec<T, C>& vec) {
  Vec<T, R> result = {};

  for (std::size_t i = 0; i < R; ++i) {
    T v = 0;
    for (std::size_t j = 0; j < C; ++j) {
      v += mat(j, i) * vec[j];
    }
    result[i] = v;
  }
  return result;
}

template <typename T, std::size_t C, std::size_t R>
constexpr Vec<T, C> operator*(const Vec<T, R>& vec,
                                        const Mat<T, C, R>& mat) {
  Vec<T, C> result = {};

  for (std::size_t j = 0; j < C; ++j) {
    T v = 0;
    for (std::size_t i = 0; i < R; ++i) {
      v += mat(j, i) * vec[i];
    }
    result[j] = v;
  }
  return result;
}
}

#endif