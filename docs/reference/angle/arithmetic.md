[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::operator+,-(vecpp::Angle)

```
template<typename T>
constexpr Angle<T> operator+(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr Angle<T> operator-(const Angle<T>& lhs, const Angle<T>& rhs);
```
Numerically combine two angles.

### Parameters

Argument   | Role
-----------|---------------------------------
**lhs**    | The left-hand side of the operation
**rhs**    | The right-hand side of the operation

### Return value

An angle containing either the sum or difference of the angles

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  auto angle_c = angle_a + angle_b;

  std::cout << angle_c << "\n";
}
```

Output:
```
-90°
```

### See also

* [operator+=,-=()](arithmetic_inplace.md)