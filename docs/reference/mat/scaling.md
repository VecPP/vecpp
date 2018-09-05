[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)

## vecpp::operator*,/(vecpp::Mat, T)

1)
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator*(const Mat<T, C, R>& mat, const T& scale);

template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator*(const T& scale, const Mat<T, C, R>& mat);
```
2)
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator/(Mat<T, C, R>& mat, const T& scale);
```

Computes a matrix representing the passed matrix scaled by the operand.

1) Multiplies each member of the matrix by the operand
2) Divides each member of the matrix by the operand

### Parameters

Argument | Role
---------|---------------------------------
**mat**  | The vector to scale
**scale**  | The scaling operand


### Return value
A matrix equivalent to `mat` with each of its members scaled by `scale`

### N.B.
The implementation of the library may choose to use `operator*(T, T)` or 
`operator*=(T&, T)` interchangeably in order to implement this. If these two 
implementations are not consistent, then the result is undefined. 