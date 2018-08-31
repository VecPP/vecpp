//  Copyright 2018 Francois Chabot
//  (francois.chabot.dev@gmail.com)
//
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#ifndef VECPP_VEC_H_INCLUDED
#define VECPP_VEC_H_INCLUDED

#include "vecpp/config.h"

#include "vecpp/flags.h"

#include <array>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <iostream>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t len, Flags f=0>
struct Vec {
 public:
  using value_type = T;
  static constexpr Flags flags = f;

  constexpr std::size_t size() const { return len; }

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
  template <int new_flags>
  constexpr operator Vec<T, len, new_flags>() const {
    Vec<T, len, new_flags> result = {};
    for(int i = 0 ; i < len; ++i) {
      result[i] = data_[i];
    }
    return result;
  }
};

// Vectors may as well be ranges.
template <typename T, std::size_t l, Flags f>
constexpr T* begin(Vec<T, l, f>& v) {
  return v.data();
}

template <typename T, std::size_t l, Flags f>
constexpr T* end(Vec<T, l, f>& v) {
  return v.data() + v.size();
}

template <typename T, std::size_t l, Flags f>
constexpr const T* begin(const Vec<T, l, f>& v) {
  return v.data();
}

template <typename T, std::size_t l, Flags f>
constexpr const T* end(const Vec<T, l, f>& v) {
  return v.data() + v.size();
}

// std::ostream support
template <typename T, std::size_t l, Flags f>
std::ostream& operator<<(std::ostream& stream, const Vec<T, l, f>& vec) {
  stream << "(";

  bool first = true;
  for(const auto& v : vec) {
    if(!first) {
      stream << ", ";
    }
    else {
      first = false;
    }

    stream << v;
  }

  stream << ")";
  return stream;
}

// Comparisons
template <typename T, std::size_t l, Flags f>
constexpr bool operator==(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, std::size_t l, Flags f>
constexpr bool operator!=(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

// Unary Operators
template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator-(const Vec<T, l, f>& rhs) {
  Vec<T, l, f> result = {};
  for (std::size_t i = 0; i < rhs.size(); ++i) {
    result[i] = -rhs[i];
  }
  return result;
}

// Binary Operators
template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator+=(Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator+(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  Vec<T, l, f> result = lhs;
  result += rhs;
  return result;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator-=(Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator-(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  Vec<T, l, f> result = lhs;
  result -= rhs;
  return result;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator*=(Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] *= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator*(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  Vec<T, l, f> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator/=(Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] /= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator/(const Vec<T, l, f>& lhs, const Vec<T, l, f>& rhs) {
  Vec<T, l, f> result = lhs;
  result /= rhs;
  return result;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator*=(Vec<T, l, f>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] *= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator*(const Vec<T, l, f>& lhs, const T& rhs) {
  Vec<T, l, f> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator*(const T& lhs, const Vec<T, l, f>& rhs) {
  return rhs * lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f>& operator/=(Vec<T, l, f>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < lhs.size(); ++i) {
    lhs[i] /= rhs;
  }
  return lhs;
}

template <typename T, std::size_t l, Flags f>
constexpr Vec<T, l, f> operator/(const Vec<T, l, f>& lhs, const T& rhs) {
  Vec<T, l, f> result = lhs;
  result /= rhs;
  return result;
}

// Algorithm disptach

}
#endif