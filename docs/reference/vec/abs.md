
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::abs(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr Vec<T,L> abs(const Vec<T,L>& vec);
```

Performs `std::abs()` member-wise on a vector.

### Parameters

Argument | Role
---------|---------------------------------
**vec**  | The vector to consume


### Return value
A Vector containing the member-wise absolute value of the input vector.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, -5.0f};
  fVec2 b = abs(a);

  assert(b[0] == 10.0f);
  assert(b[1] == 5.0f);
}
```