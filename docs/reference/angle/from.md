
[vecpp](../../../) :: [Angle<typename\>](../angle.md)
## vecpp::Angle::from_deg,from_rad

```
static constexpr Angle from_deg(const T& val);
static constexpr Angle from_rad(const T& val);
```

Creates a new Angle from a raw value in a given unit.

The angle will be re-mapped in the ]-PI,PI] radians range.

### Parameters

Argument | Role
---------|---------------------------------
**val**  | The raw angle value in the matching unit


### Return value

An Angle instance representing the angle.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(270.0f);

  std::cout << angle_a << ", " << angle_b << "\n";
}
```

Output:
```
90°, -90°
```

### See also

* [from_clamped_*](from_clamped.md) : Create from clamped value.