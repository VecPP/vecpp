[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::operator+,-,*,/(vecpp::Vec)


```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator+(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator-(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator*(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```
```
template<typename T, std::size_t L>
constexpr Vec<T,L> operator/(const Vec<T,L>& lhs, const Vec<T,L>& rhs);
```

Performs binary operations member-wise on two vectors.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector to consume
**rhs**  | The second vector to consume


### Return value
A Vector containing the member-wise result of the binary operation applied on 
each input vector.

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using fVec2 = vecpp::Vec<float, 2>;

  fVec2 a = {10.0f, 5.0f};
  fVec2 b = {5.0f, 6.0f};

  fVec2 c = a + b;

  assert(c[0] == a[0] + b[0]);
  assert(c[1] == a[1] + b[1]);
}
```