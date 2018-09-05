[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator-(vecpp::Mat)<sub>unary</sub>


```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator-(const Vec<T,L>& rhs);
```

Returns the negated version of the vector

### Parameters

Argument | Role
---------|---------------------------------
**rhs**  | The vector to negate


### Return value
A vector equivalent to `rhs` where `operator-()` has been applied to it 
element-wise.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, -5.0f};

  fVec2 b = -a;

  assert(b[0] == -10.0f);
  assert(b[1] == 5.0f);
}
```