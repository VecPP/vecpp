[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::cos

```
template <typename T>
constexpr T cos(const Angle<T>& arg);
```

Computes the cosine of arg

### Parameters

Argument | Role
---------|---------------------------------
**arg**  | An angle

### Return value

The cosine of arg.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle = Angle::from_deg(90.0f);

  std::cout << cos(angle) << "\n";
}
```

Output:
```
0
```

### See also
* [sin](sin.md) : computes sine
* [tan](tan.md) : computes tangent
