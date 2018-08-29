
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::operator+=,-=,*=,/=(vecpp::Vec)


```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator+=(Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator-=(Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator*=(Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator/=(Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

Performs binary operations member-wise on two vectors, and updates the first
with the result.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector to consume, and where the results are stored
**rhs**  | The second vector to consume


### Return value
A reference to lhs.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  a += b;

  assert(a[0] == 10.0f + 5.0f);
  assert(a[1] == 5.0f + 6.0f);
}
```