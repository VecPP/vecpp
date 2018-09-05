[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)
## vecpp::operator==,!=(vecpp::Mat)

1)
```
template<typename T, std::size_t C, std::size_t R>
constexpr bool operator==(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```

2)
```
template<typename T, std::size_t C, std::size_t R>
constexpr bool operator!=(const Mat<T, C, R>& lhs, const Mat<T, C, R>& rhs);
```

Compares matrices for equality.

### Parameters

Argument | Role
---------|---------------------------------
**lhs**  | The first matrix to compare
**rhs**  | The second matrix to compare

**N.B.** `lhs` and `rhs` must be the exact same matrix type, mixed type comparisons 
are not supported.

### Return value
1) `true` if both matrices are equal element-wise
2) `true` if any element at a given location differs between the matrices
