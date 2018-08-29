
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::operator<<(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr std::ostream& operator<<(std::ostream& stream, const Vec<T,L>& vec);
```

Formats the vector into the passed `std::ostream`. 

The format is `(a, b, c, ...)`, where the individual members are generated using
`operator<<(std::ostream&, T)`.

### Parameters

Argument   | Role
-----------|---------------------------------
**stream** | The destination stream
**vec**    | The vector to format

### Return value
A reference to `stream`

### Example

```
#include "vecpp/vecpp.h"
#include <iostream>

int main() {
  using Vec3 = vecpp::Vec<int, 3>;

  Vec3 vec = {1, 2, 3};
  std::cout << vec << "\n";
}
```

Output:
```
(1, 2, 3)
```
