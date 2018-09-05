[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator+,-(vecpp::Mat)


```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator+(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R> operator-(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```

Performs binary operations member-wise on two matrices.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first vector to consume
**rhs**  | The second vector to consume


### Return value
A Matrix containing the member-wise result of the binary operation applied on 
each input matrix.
