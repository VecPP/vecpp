[vecpp](../../) :: [reference](../) :: [Angle<typename\>](./)
## vecpp::sin

```
template <typename T>
constexpr T sin(const Angle<T>& arg);
```

Computes the sin of arg

### Parameters

Argument | Role
---------|---------------------------------
**arg**  | An angle

### Return value

the sine of arg.

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Angle = vecpp::Angle<float>;

  auto angle = Angle::from_deg(90.0f);

  std::cout << sin(angle) << "\n";
}
```

Output:
```
1
```

### See also
* [cos](cos.md) : computes cosine
* [tan](tan.md) : computes tangent