[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator*=,/=(vecpp::Mat, T)

1)
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R>& operator*=(Mat<T, C, R>& lhs, const T& rhs);
```
2)
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R>& operator/=(Mat<T, C, R>& lhs, const T& rhs);
```

Scales each member of the matrix by the operand.

1) Multiplies each member of the matrix by the operand
2) Divides each member of the matrix by the operand

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The matrix to scale
**rhs**  | The scaling operand


### Return value
A reference to lhs.