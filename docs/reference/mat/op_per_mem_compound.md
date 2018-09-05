[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator+=,-=(vecpp::Mat)


```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R>& operator+=(Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```
```
template<typename T, std::size_t C, std::size_t R>
constexpr Mat<T, C, R>& operator-=(Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```
Performs binary operations member-wise on two matrices, and updates the first
with the result.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first matrix to consume, and where the results are stored
**rhs**  | The second matrix to consume


### Return value
A reference to lhs.
