[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::operator*=,/=(vecpp::Vec, T)

1)
```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator*=(Vec<T,L>& lhs, const T& rhs);
```
2)
```
template<typename T, std::size_t L>
constexpr Vec<T,L>& operator/=(Vec<T,L>& lhs, const T& rhs);
```

Scales each member of the vector by the operand.

1) Multiplies each member of the vector by the operand
2) Divides each member of the vector by the operand

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The vector to scale
**rhs**  | The scaling operand


### Return value
A reference to lhs.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};

  a *= 3.0f;

  assert(a[0] == 3.0f * 10.0f);
  assert(a[1] == 3.0f * 5.0f);
}
```