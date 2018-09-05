[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::Angle::from_clamped_deg,from_clamped_rad

```
static constexpr Angle from_clamped_deg(const T& val);
static constexpr Angle from_clamped_rad(const T& val);
```

Creates a new Angle from a raw value in a given unit.

Calling `from_clamped_deg()` with `val` not within the ]-180,180] range,
or `from_clamped_deg()` with `val` not within the ]-PI,PI] range is **undefined 
behavior**.

These functions are unsafe and should only be used to leverage situations where
you are certain that the precondition is met.

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

  auto angle_a = Angle::from_clamped_deg(90.0f);
  auto angle_b = Angle::from_clamped_deg(-90.0f);

  std::cout << angle_a << ", " << angle_b << "\n";
}
```

Output:
```
90°, -90°
```

### See also

* [from_*](from_clamped.md) : Create from unclamped value.