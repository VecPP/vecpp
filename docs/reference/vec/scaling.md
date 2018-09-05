[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::operator*,/(vecpp::Vec, T)

1)
```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator*(const Vec<T,L>& vec, const T& scale);

template<typename T, std::size_t L>
constexpr Vec<T,L> operator*(const T& scale, const Vec<T,L>& vec);
```
2)
```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator/(Vec<T,L>& vec, const T& scale);
```

Computes a vector representing the passed vector scaled by the operand.

1) Multiplies each member of the vector by the operand
2) Divides each member of the vector by the operand

### Parameters

Argument | Role
---------|---------------------------------
**vec**  | The vector to scale
**scale**  | The scaling operand


### Return value
A vector equivalent to `vec` with each of its members scaled by `scale`

### N.B.
The implementation of the library may choose to use `operator*(T, T)` or 
`operator*=(T&, T)` interchangeably in order to implement this. If these two 
implementations are not consistent, then the result is undefined. 

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = a * 3.0f;

  assert(b[0] == 3.0f * 10.0f);
  assert(b[1] == 3.0f * 5.0f);
}
```