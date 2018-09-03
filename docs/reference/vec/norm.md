
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::norm(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr T norm(const Vec<T,L>& arg);
```

Returns the eunclidian norm of the vector

### Parameters

Argument | Role
---------|---------------------------------
**arg**  | The vector we want the legnth of


### Return value
The norm of the vector.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {3.0f, 0.0f};
  fVec2 b = {1.0f, 1.0f};

  assert(norm(a) == 3.0f);
  assert(norm(b) == std::sqrt(2.0f));
}
```
