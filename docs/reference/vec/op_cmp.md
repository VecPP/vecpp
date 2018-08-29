
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::operator==,!=(vecpp::Vec)

1)
```
template<typename T, std::size_t L>
constexpr bool operator==(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

2)
```
template<typename T, std::size_t L>
constexpr bool operator!=(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

Compares vectrs for equality.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector to compare
**rhs**  | The second vector to compare

**N.B.** `lhs` and `rhs` must be the exact same vector type, mixed type comparisons 
are not supported.

### Return value
1) `true` if both vectors are equal element-wise
2) `true` if any element at a given index differs between the vectors

### Example

```
#include "vecpp/vecpp.h"

void foo() {
  constexpr vecpp::Vec<float, 2> a = {1.0f, 1.0f};
  constexpr vecpp::Vec<float, 2> b = {1.0f, 1.0f};
  constexpr vecpp::Vec<float, 2> c = {1.0f, 2.0f};

  static_assert(a == b);
  static_assert(a != c);
}
```
