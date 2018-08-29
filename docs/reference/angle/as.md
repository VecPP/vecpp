[vecpp](../../../) :: [Angle<typename\>](../angle.md)
## vecpp::Angle::as_deg,as_rad

```
constexpr T as_deg() const;
constexpr T as_rad() const;
```

Obtain the numerical value of the angle in the requested unit.

### Return value

A scalar value containing the angle within the requested unit.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle = Angle::from_deg(90.0f);

  std::cout << angle.as_rad() << "\n";
}
```

Output:
```
1.5708
```
