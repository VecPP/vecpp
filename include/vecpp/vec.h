#ifndef VECPP_VEC_H_INCLUDED
#define VECPP_VEC_H_INCLUDED

#include "vecpp/config.h"

#include <array>
#include <cassert>
#include <cstddef>
#include <stdexcept>
#include <iostream>

namespace VECPP_NAMESPACE {

template <typename T, std::size_t len>
struct Vec {
 public:
  using value_type = T;

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
};

// Vectors may as well be ranges.
template <typename T, std::size_t len>
constexpr T* begin(Vec<T, len>& v) {
  return v.data();
}

template <typename T, std::size_t len>
constexpr T* end(Vec<T, len>& v) {
  return v.data() + len;
}

template <typename T, std::size_t len>
constexpr const T* begin(const Vec<T, len>& v) {
  return v.data();
}

template <typename T, std::size_t len>
constexpr const T* end(const Vec<T, len>& v) {
  return v.data() + len;
}

// std::ostream support
template <typename T, std::size_t L>
std::ostream& operator<<(std::ostream& stream, const Vec<T, L>& vec) {
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
template <typename T, std::size_t L>
constexpr bool operator==(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

template <typename T, std::size_t L>
constexpr bool operator!=(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    if (lhs[i] != rhs[i]) {
      return true;
    }
  }
  return false;
}

// Unary Operators
template <typename T, std::size_t L>
constexpr Vec<T, L> operator-(const Vec<T, L>& rhs) {
  Vec<T, L> result = {};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = -rhs[i];
  }
  return result;
}

// Binary Operators
template <typename T, std::size_t L>
constexpr Vec<T, L>& operator+=(Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] += rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator+(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = lhs;
  result += rhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L>& operator-=(Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] -= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator-(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = lhs;
  result -= rhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L>& operator*=(Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] *= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator*(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L>& operator/=(Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] /= rhs[i];
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator/(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = lhs;
  result /= rhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L>& operator*=(Vec<T, L>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] *= rhs;
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator*(const Vec<T, L>& lhs, const T& rhs) {
  Vec<T, L> result = lhs;
  result *= rhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator*(const T& lhs, const Vec<T, L>& rhs) {
  return rhs * lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L>& operator/=(Vec<T, L>& lhs, const T& rhs) {
  for (std::size_t i = 0; i < L; ++i) {
    lhs[i] /= rhs;
  }
  return lhs;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator/(const Vec<T, L>& lhs, const T& rhs) {
  Vec<T, L> result = lhs;
  result /= rhs;
  return result;
}

// Algorithm disptach
template <typename T, std::size_t L>
constexpr Vec<T, L> min(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = {0};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = std::min(lhs[i], rhs[i]);
  }
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> max(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
  Vec<T, L> result = {0};
  for (std::size_t i = 0; i < L; ++i) {
    result[i] = std::max(lhs[i], rhs[i]);
  }
  return result;
}

// Vector operations

// Dot product
template <typename T>
struct Dot_impl;

template <typename T, std::size_t L>
struct Dot_impl<Vec<T, L>> {
  constexpr static T dot(const Vec<T, L>& lhs, const Vec<T, L>& rhs) {
    T result = 0;

    for (std::size_t i = 0; i < L; ++i) {
      result += lhs[i] * rhs[i];
    }

    return result;
  }
};

template <typename T>
constexpr auto dot(const T& lhs, const T& rhs) {
  return Dot_impl<T>::dot(lhs, rhs);
}

// Vector legnth
template <typename T>
struct Length_impl;

template <typename T, std::size_t L>
struct Length_impl<Vec<T, L>> {
  constexpr static T length(const Vec<T, L>& v) { return std::sqrt(dot(v, v)); }
};

template <typename T>
constexpr auto length(const T& v) {
  return Length_impl<T>::length(v);
}

// Cross product
template <typename T>
struct Cross_impl;

template <typename T>
struct Cross_impl<Vec<T, 3>> {
  static constexpr Vec<T, 3> cross(const Vec<T, 3>& lhs, const Vec<T, 3>& rhs) {
    return {lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0]};
  }
};

template <typename T>
constexpr auto cross(const T& lhs, const T& rhs) {
  return Cross_impl<T>::cross(lhs, rhs);
}
}
#endif