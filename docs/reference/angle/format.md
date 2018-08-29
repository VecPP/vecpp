[vecpp](../../../) :: [Angle<typename\>](../angle.md)
## vecpp::operator<<(vecpp::Angle)

```
template<typename T>
constexpr std::ostream& operator<<(std::ostream& stream, const Angle<T>& angle);
```

Formats the angle into the passed `std::ostream`. 

The angle will be represented as {DEG}°, where the output of DEG is delegated to
`operator<<(std::ostream&, T)`.

This is equivalent to:
```
stream << angle.as_deg() << "°";
```

### Parameters

Argument   | Role
-----------|---------------------------------
**stream** | The destination stream
**angle**  | The angle to format

### Return value
A reference to `stream`

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
