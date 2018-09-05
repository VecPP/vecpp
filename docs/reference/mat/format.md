[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator<<(vecpp::Mat)

```
template<typename T, std::size_t C, std::size_t R>
constexpr std::ostream& operator<<(std::ostream& stream, const Mat<T, C, R>& mat);
```

Formats the matrix into the passed `std::ostream`. 

### Parameters

Argument   | Role
-----------|---------------------------------
**stream** | The destination stream
**mat**    | The matrix to format

### Return value
A reference to `stream`