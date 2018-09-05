[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::tan

```
template <typename T>
constexpr T tan(const Angle<T>& arg);
```

Computes the tangent of arg

### Parameters

Argument | Role
---------|---------------------------------
**arg**  | An angle

### Return value

The tangent of arg.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle = Angle::from_deg(45.0f);

  std::cout << tan(angle) << "\n";
}
```

Output:
```
1
```

### See also
* [sin](sin.md) : computes sine
* [cos](cos.md) : computes cosine