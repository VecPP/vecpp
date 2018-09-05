[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::operator-(vecpp::Angle)<sub>unary</sub>

```
template<typename T>
constexpr Angle<T> operator-(const Angle<T>& rhs);
```

Returns the negated version of the angle

Keep in mind that in the angle's clamp space, -PI == PI.

### Parameters

Argument | Role
---------|---------------------------------
**rhs**  | The angle to negate

### Return value
An angle of inverse magnitude as 'rhs'

### Example

```
#include "vecpp/vecpp.h"
#include <cassert>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle_a = Angle::from_deg(90.0f);
  auto angle_b = Angle::from_deg(180.0f);

  std::cout << -angle_a << " " << -angle_b << "\n";
}
```

Output:
```
-90° 180°
```