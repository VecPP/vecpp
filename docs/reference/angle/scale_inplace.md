[vecpp](../../../) :: [Angle<typename\>](../angle.md)
## vecpp::operator*,/(vecpp::Angle)

```
template<typename T>
constexpr Angle<T>& operator*=(Angle<T>& angle, const T& factor);

template<typename T>
constexpr Angle<T> operator/=(Angle<T>& angle, const T& factor);
```
Compute the scaled value of an angle in-place.

### Parameters

Argument   | Role
-----------|---------------------------------
**angle**  | The angle to scale
**factor** | The value by which to multiply (or divide) the angle

### Return value

A reference to `angle`, which has been scaled by `factor`

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  angle_a *= 3.0f;

  std::cout << angle_a << "\n";
}
```

Output:
```
-90°
```

### See also

* [operator*,/()](scale.md)