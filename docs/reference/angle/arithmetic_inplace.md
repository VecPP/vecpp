[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::operator+=,-=(vecpp::Angle)

```
template<typename T>
constexpr Angle<T>& operator+=(Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr Angle<T>& operator-=(Angle<T>& lhs, const Angle<T>& rhs);
```
Numerically combine two angles, storing the result into the first.

### Parameters

Argument   | Role
-----------|---------------------------------
**lhs**    | The left-hand side of the operation and the destination
**rhs**    | The right-hand side of the operation

### Return value

A reference to `lhs`

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  angle_a += angle_b;

  std::cout << angle_a << "\n";
}
```

Output:
```
-90°
```

### See also

* [operator+,-()](arithmetic.md)