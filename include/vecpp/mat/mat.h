//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_MAT_MAT_H_INCLUDED
#define VECPP_MAT_MAT_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/flags.h"
#include "vecpp/vec/vec.h"

#include <array>
#include <cassert>
#include <cstddef>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t C, std::size_t R, Flags f = 0>
struct Mat {
  static constexpr Flags flags = f;
  static constexpr std::size_t rows = R;
  static constexpr std::size_t cols = C;

  using value_type = T;
  using col_type = Vec<value_type, rows, flags>;
  using row_type = Vec<value_type, cols, flags>;

  constexpr value_type& operator()(std::size_t i, std::size_t j) {
    assert(i < cols && j < rows);
    return data_[i*rows + j];
  }

  constexpr const value_type& operator()(std::size_t i, std::size_t j) const {
    assert(i < cols && j < rows);
    return data_[i*rows + j];
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

  constexpr value_type* data() {
    return data_.data();
  }

  constexpr const value_type* data() const {
    return data_.data();
  }
  
  // Left public for aggregate initialization.
  std::array<value_type, cols * rows> data_;
};

template <typename T, std::size_t C, std::size_t R, Flags fl, Flags fr>
constexpr bool operator==(const Mat<T, C, R, fl>& lhs, const Mat<T, C, R, fr>& rhs) {
  for(std::size_t i = 0 ; i < C; ++i) {
    for(std::size_t j = 0 ; j < R; ++j) {
      if(lhs(i, j) != rhs(i, j)) {
        return false;
      }
    }
  }  
  return true;
}

template <typename T, std::size_t C, std::size_t R, Flags mf, Flags vf>
constexpr Vec<T, R, vf> operator*(const Mat<T, C, R, mf>& mat,
                                  const Vec<T, C, vf>& vec) {
  Vec<T, R, vf> result = {};

  for (std::size_t i = 0; i < R; ++i) {
    T v = 0;
    for (std::size_t j = 0; j < C; ++j) {
      v += mat(j,i) * vec[j];
    }
    result[i] = v;
  }
  return result;
}

template <typename T, std::size_t C, std::size_t R, Flags mf, Flags vf>
constexpr Vec<T, C, vf> operator*(const Vec<T, R, vf>& vec,
                                  const Mat<T, C, R, mf>& mat) {
  Vec<T, C, vf> result = {};

  for (std::size_t j = 0; j < C; ++j) {
    T v = 0;
    for (std::size_t i = 0; i < R; ++i) {
      v += mat(j,i) * vec[i];
    }
    result[j] = v;
  }
  return result;
}

template <typename T, std::size_t C, std::size_t R, Flags f>
constexpr Mat<T, R, C, f> transpose(const Mat<T, C, R, f>& m) {
  Mat<T, R, C, f> result = {};

  for(std::size_t i = 0 ; i < R; ++i) {
    for(std::size_t j = 0 ; j < C; ++j) {
      result(i, j) = m(j, i);
    }
  }
  return result;
}
}

#endif