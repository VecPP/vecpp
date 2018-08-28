#ifndef VECPP_VEC_H_INCLUDED
#define VECPP_VEC_H_INCLUDED

#include "vecpp/config.h"

#include <array>
#include <cstddef>

namespace VECPP_NAMESPACE {

// We could technically provide sane-ish defaults for most functions,
template <typename T, std::size_t len>
struct Vec {
 public:
  using value_type = T;

  constexpr std::size_t size() const { return len; }

  constexpr T& operator[](std::size_t i) { return data_[i]; }
  constexpr const T& operator[](std::size_t i) const { return data_[i]; }

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
  result += lhs;
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
  result -= lhs;
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator*(const Vec<T, L>& lhs, const T& rhs) {
  Vec<T, L> result = lhs;
  for (std::size_t i = 0; i < L; ++i) {
    result[i] *= rhs;
  }
  return result;
}

template <typename T, std::size_t L>
constexpr Vec<T, L> operator*(const T& lhs, const Vec<T, L>& rhs) {
  return rhs * lhs;
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
template <typename T>
struct Cross_impl {
  static constexpr Vec<T, 3> cross(const Vec<T, 3>& lhs, const Vec<T, 3>& rhs) {
    return {lhs[1] * rhs[2] - lhs[2] * rhs[1],
            lhs[2] * rhs[0] - lhs[0] * rhs[2],
            lhs[0] * rhs[1] - lhs[1] * rhs[0]};
  }
};

template <typename T>
constexpr Vec<T, 3> cross(const Vec<T, 3>& lhs, const Vec<T, 3>& rhs) {
  return Cross_impl<T>::cross(lhs, rhs);
}
}
#endif