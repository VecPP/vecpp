[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::operator*,/(vecpp::Angle)

```
template<typename T>
constexpr Angle<T> operator*(const Angle<T>& angle, const T& factor);

template<typename T>
constexpr Angle<T> operator*(const T& factor, Angle<T>& angle);

template<typename T>
constexpr Angle<T> operator/(const Angle<T>& angle, const T& factor);
```
Compute the scaled value of an angle.

### Parameters

Argument   | Role
-----------|---------------------------------
**angle**  | The angle to scale
**factor** | The value by which to multiply (or divide) the angle

### Return value

An Angle containing the scaled value of `angle`

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);

  auto angle_c = 3.0f * angle_a;

  std::cout << angle_c << "\n";
}
```

Output:
```
-90°
```

### See also

* [operator*=,/=()](scale_inplace.md)