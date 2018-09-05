[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::dot(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr T dot(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

Returns the dot product of the thw argument vectors

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector operand
**rhs**  | The second vector operand


### Return value
The dot product of the passed vectors.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {3.0f, 0.0f};
  fVec2 b = {1.0f, 1.0f};

  float dot_val = dot(a, b);
  assert(dot_val == 3.0f);
}
```
