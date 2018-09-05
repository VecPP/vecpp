[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::Vec::operator\[]()

`constexpr T& operator[](std::size_t i);`  
`constexpr const T& operator[](std::size_t i) const;`

### Parameters

Argument | Role
---------|---------------------------------
 **i**   | index of the element to access.

### Return value
A reference to the requested element.

### N.B. 

Bounds checking is still performed in debug builds as a safety mechanism, but this should not be relied upon.

### See also

* [at[]](at.md) : bounds-checked access.