[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::Mat::at()

`constexpr T& at(std::size_t c, std::size_t r);`  
`constexpr const T& at(std::size_t c, std::size_t r) const;`

### Parameters

Argument | Role
---------|---------------------------------
 **c**   | The column of the cell to access
 **r**   | The column of the row to access

### Return value
A reference to the requested element.

### Exceptions
`std::out_of_range`

### See also
* [operator[]](operator_at.md) : Access without bounds checking.