[vecpp](../../../) :: [Vec<typename, size_t\>](./)
## vecpp::operator-(vecpp::Vec)<sub>unary</sub>


```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator-(const Mat<T, C, R>& rhs);
```

Returns the negated version of the matrix

### Parameters

Argument | Role
---------|---------------------------------
**rhs**  | The matrix to negate


### Return value
A matrix equivalent to `rhs` where `operator-()` has been applied to it 
element-wise.
