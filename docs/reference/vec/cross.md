
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::cross(vecpp::Vec)

```
template<typename T>
constexpr T cross(const Vec<T,3>& lhs, const Vec<T,3>& rhs);
```

Computes the cross product between two three-dimensional vectors.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector operand
**rhs**  | The second vector operand


### Return value
The cross product of the passed vectors.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec3 = vecpp::Vec<float, 3>;

  fVec3 x = {1.0f, 0.0f, 0.0f};
  fVec3 y = {0.0f, 1.0f, 0.0f};
  fVec3 z = {0.0f, 0.0f, 1.0f};

  fVec3 cross_val = cross(x, y);

  assert(length(cross_val-z) < 0.0001f);
}
```
