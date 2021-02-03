//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_H_INCLUDED
#define VECPP_VEC_H_INCLUDED

#include "vecpp/config.h"

#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t len>
struct Vec {
 public:
  static_assert(len > 0);

  static constexpr std::size_t length = len;

  using value_type = T;
  
  constexpr T& at(std::size_t i) {
    if (i >= len) {
      throw std::out_of_range("out of range vector access");
    }
    return data_[i];
  }

  constexpr const T& at(std::size_t i) const {
    if (i >= len) {
      throw std::out_of_range("out of range vector access");
    }
    return data_[i];
  }

  constexpr T& operator[](std::size_t i) {
    assert(i < len);
    return data_[i];
  }

  constexpr const T& operator[](std::size_t i) const {
    assert(i < len);
    return data_[i];
  }

  constexpr T* data() { return data_.data(); }
  constexpr const T* data() const { return data_.data(); }

  // Left public for aggregate initialization.
  std::array<T, len> data_;
};

// Vectors may as well be ranges.
template <typename T, std::size_t l>
constexpr T* begin(Vec<T, l>& v) {
  return v.data();
}

template <typename T, std::size_t l>
constexpr T* end(Vec<T, l>& v) {
  return v.data() + v.length;
}

template <typename T, std::size_t l>
constexpr const T* begin(const Vec<T, l>& v) {
  return v.data();
}

template <typename T, std::size_t l>
constexpr const T* end(const Vec<T, l>& v) {
  return v.data() + v.length;
}

// std::ostream support
template <typename T, std::size_t l>
std::ostream& operator<<(std::ostream& stream, const Vec<T, l>& vec) {
  stream << "(";

  bool first = true;
  for (const auto& v : vec) {
    if (!first) {
      stream << ", ";
    } else {
      first = false;
    }

    stream << v;
  }

  stream << ")";
  return stream;
}

// Comparisons
template <typename T, std::size_t l>
constexpr bool operator==(const Vec<T, l>& lhs,
                          const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, std::size_t l>
constexpr bool operator!=(const Vec<T, l>& lhs,
                          const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

// Unary Operators
template <typename T, std::size_t l>
constexpr Vec<T, l> operator-(const Vec<T, l>& rhs) {
  Vec<T, l> result = {};
  for (std::size_t i = 0; i < rhs.length; ++i) {
    result[i] = -rhs[i];
  }
  return result;
}

// Binary Operators
template <typename T, std::size_t l>
constexpr Vec<T, l>& operator+=(Vec<T, l>& lhs,
                                        const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator+(const Vec<T, l>& lhs,
                                      const Vec<T, l>& rhs) {
  Vec<T, l> result = lhs;
  result += rhs;
  return result;
}

template <typename T, std::size_t l>
constexpr Vec<T, l>& operator-=(Vec<T, l>& lhs,
                                        const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator-(const Vec<T, l>& lhs,
                                      const Vec<T, l>& rhs) {
  Vec<T, l> result = lhs;
  result -= rhs;
  return result;
}

template <typename T, std::size_t l>
constexpr Vec<T, l>& operator*=(Vec<T, l>& lhs,
                                        const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator*(const Vec<T, l>& lhs,
                                      const Vec<T, l>& rhs) {
  Vec<T, l> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l>
constexpr Vec<T, l>& operator/=(Vec<T, l>& lhs,
                                        const Vec<T, l>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator/(const Vec<T, l>& lhs,
                                      const Vec<T, l>& rhs) {
  Vec<T, l> result = lhs;
  result /= rhs;
  return result;
}

template <typename T, std::size_t l>
constexpr Vec<T, l>& operator*=(Vec<T, l>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator*(const Vec<T, l>& lhs,
                                      const T& rhs) {
  Vec<T, l> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator*(const T& lhs,
                                      const Vec<T, l>& rhs) {
  return rhs * lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l>& operator/=(Vec<T, l>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l>
constexpr Vec<T, l> operator/(const Vec<T, l>& lhs,
                                      const T& rhs) {
  Vec<T, l> result = lhs;
  result /= rhs;
  return result;
}

// Algorithm disptach

}  // namespace VECPP_NAMESPACE
#endif