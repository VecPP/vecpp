//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_H_INCLUDED
#define VECPP_VEC_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/traits.h"

#include <array>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t len, typename Traits = Vec_traits<T>>
struct alignas(Traits::align) Vec {
 public:
  static_assert(len > 0);

  static constexpr std::size_t length = len;

  using value_type = T;
  using traits = Traits;

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

  // A vector is implicitely convertible to any vector differing only by flags
  template <typename new_traits>
  constexpr operator Vec<T, len, new_traits>() const {
    Vec<T, len, new_traits> result = {};
    for (std::size_t i = 0; i < length; ++i) {
      result[i] = data_[i];
    }
    return result;
  }
};

template <typename T, std::size_t l, typename traits>
constexpr auto ct(const Vec<T, l, traits>& v) {
  return Vec<T, l, Add_constexpr_t<traits>>(v);
}

// Vectors may as well be ranges.
template <typename T, std::size_t l, typename traits>
constexpr T* begin(Vec<T, l, traits>& v) {
  return v.data();
}

template <typename T, std::size_t l, typename traits>
constexpr T* end(Vec<T, l, traits>& v) {
  return v.data() + v.length;
}

template <typename T, std::size_t l, typename traits>
constexpr const T* begin(const Vec<T, l, traits>& v) {
  return v.data();
}

template <typename T, std::size_t l, typename traits>
constexpr const T* end(const Vec<T, l, traits>& v) {
  return v.data() + v.length;
}

// std::ostream support
template <typename T, std::size_t l, typename traits>
std::ostream& operator<<(std::ostream& stream, const Vec<T, l, traits>& vec) {
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
template <typename T, std::size_t l, typename traits1, typename traits2>
constexpr bool operator==(const Vec<T, l, traits1>& lhs,
                          const Vec<T, l, traits2>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, std::size_t l, typename traits1, typename traits2>
constexpr bool operator!=(const Vec<T, l, traits1>& lhs,
                          const Vec<T, l, traits2>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

// Unary Operators
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator-(const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = {};
  for (std::size_t i = 0; i < rhs.length; ++i) {
    result[i] = -rhs[i];
  }
  return result;
}

// Binary Operators
template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator+=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator+(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result += rhs;
  return result;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator-=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator-(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result -= rhs;
  return result;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator*=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator/=(Vec<T, l, traits>& lhs,
                                        const Vec<T, l, traits>& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator/(const Vec<T, l, traits>& lhs,
                                      const Vec<T, l, traits>& rhs) {
  Vec<T, l, traits> result = lhs;
  result /= rhs;
  return result;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator*=(Vec<T, l, traits>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] *= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const Vec<T, l, traits>& lhs,
                                      const T& rhs) {
  Vec<T, l, traits> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator*(const T& lhs,
                                      const Vec<T, l, traits>& rhs) {
  return rhs * lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits>& operator/=(Vec<T, l, traits>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.length; ++i) {
    lhs[i] /= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l, typename traits>
constexpr Vec<T, l, traits> operator/(const Vec<T, l, traits>& lhs,
                                      const T& rhs) {
  Vec<T, l, traits> result = lhs;
  result /= rhs;
  return result;
}

// Algorithm disptach

}  // namespace VECPP_NAMESPACE
#endif