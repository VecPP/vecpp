
[vecpp](../../../) :: [Vec<typename, size_t\>](../vec.md)

## vecpp::Vec::Vec

`Vec<T, L>` does not define a constructor per-se, but instead relies entirely on
 aggregate initialization.

### default construction

Default-constructing a vector will leave it in an undefined state.

**N.B.**

- Default-constructed vectors are not allowed in `constexpr` code, which is
  why you might see some `Vec v = {};` within the `vecpp` codebase where
  default initialization would have made sense.

### Examples:

```
// default construction
Vec<float, 3> vec;

// value-construction
Vec<float, 3> y_axis = {0.0f, 1.0f, 0.0f};

// copy-construction
Vec<float, 3> y_axis_copy = y_axis;

```