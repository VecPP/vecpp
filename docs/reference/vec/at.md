
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)
## vecpp::Vec::at()

`constexpr T& at(std::size_t i);`  
`constexpr const T& at(std::size_t i) const;`

### Parameters

Argument | Role
---------|---------------------------------
 **i**   | index of the element to access.

### Return value
A reference to the requested element.

### Exceptions
`std::out_of_range`

### See also

* [operator[]](operator_at.md) : Access without bounds checking.