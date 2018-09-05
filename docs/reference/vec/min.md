[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::min(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr Vec<T,L> min(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

Performs `std::min()` member-wise on two vectors.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector to consume
**rhs**  | The second vector to consume


### Return value
A Vector containing the member-wise smallest element of each input vector.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;
  
  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  fVec2 c = min(a,b);
  assert(c[0] == 5.0f);
  assert(c[1] == 5.0f);
}
```

### See also
* [max](max.md) : per-member `max()`