
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::begin(vecpp::Vec)

```
template<typename T, std::size_t L>
constexpr T* begin(Vec<T,L>& v);
```
```
template<typename T, std::size_t L>
constexpr const T* begin(const Vec<T,L>& v);  
```

Returns an iterator to the first element of the vector. This can be used 
directly, or indirectly through a range-based for loop.

### Parameters

Argument | Role
---------|---------------------------------
**v**    | The vector to get the iterator from

### Return value
Iterator to the first element.

### Example

```
#include "vecpp/vecpp.h"

#include <numeric>

float sum_elements(const vecpp::Vec<float, 3>& v) {
  return std::accumulate(begin(v), end(v), 0.0f);
}
```

### See also
* [end](end.md) : Returns an iterator to the end.