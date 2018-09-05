[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::operator==,!=,<,<=,>,>=(vecpp::Angle)

```
template<typename T>
constexpr bool operator==(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr bool operator!=(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr bool operator<(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr bool operator<=(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr bool operator>(const Angle<T>& lhs, const Angle<T>& rhs);

template<typename T>
constexpr bool operator>=(const Angle<T>& lhs, const Angle<T>& rhs);
```

Numerically compare two angles.

The test is performed on the clamped value.

### Parameters

Argument   | Role
-----------|---------------------------------
**lhs**    | The left-hand side of the comparison
**rhs**    | The right-hand side of the comparison

### Return value

Wether or not the numeric test passes.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(91.0f);
  auto angle_b = Angle::from_deg(450.0f);

  assert(angle_a > angle_b);
}
```