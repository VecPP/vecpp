[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::Mat::opertor[]()

`constexpr T& operator[](std::size_t c, std::size_t r);`  
`constexpr const T& operator[](std::size_t c, std::size_t r) const;`

### Parameters

Argument | Role
---------|---------------------------------
 **c**   | The column of the cell to access
 **r**   | The column of the row to access

### Return value
A reference to the requested element.

### N.B. 
Bounds checking is still performed in debug builds as a safety mechanism, but this should not be relied upon.

### See also
* [at()](at.md) : Access with bounds checking.