[vecpp](../../) :: [reference](../) :: [Mat<typename, std::size_t, std::size_t\>](./)

`Mat<T, C, R>` does not define a constructor per-se, but instead relies entirely on
 aggregate initialization.

### default construction

Default-constructing a matrix will leave it in an undefined state.

**N.B.**

- Default-constructed matrices are not allowed in `constexpr` code, which is
  why you might see some `Mat v = {};` within the `vecpp` codebase where
  default initialization would have made sense.

### Examples:

```
using Mat2 = Mat<float, 2, 2>;

// default construction
Mat2 mat;

// value-construction
Mat2 identity = {
  1.0f, 0.0f, 
  0.0f, 1.0f
};

// copy-construction
Mat2 identity_copy = identity;

```