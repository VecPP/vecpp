[vecpp](../../) :: [reference](../)
# Vec

```
template<typename T, std::size_t L>
struct Vec;
```
In many respects, `Vec` behaves a lot like `std::array<>`, but with support for mathematical operations.

## Member types

Member Type   | Definition
--------------|-----------
`value_type`  | `T`

## Member functions

Member                              | Behavior
------------------------------------|------------------------
[(constructor)](constructor.md)     | initalize using aggregate initialization
(destructor)                        | destroy every element in the vectpr
operator=                           | ovewrite the vector with another vector
[at](at.md)                         | access specific element with bounds checking 
[operator[]](operator_at.md)        | access specific element
[data](data.md)                     | access underlying array

## Non-member functions

### Language support

Function                            | Behavior
------------------------------------|------------------------
[begin](begin.md)               | iterator to the beginning
[end](end.md)                   | iterator to the end
[operator<<](format.md)         | print to stream

### Per-member operations

Function                                  | Behavior
------------------------------------------|------------------------
[operator==](op_cmp.md)               | compares two vectors for equality
[operator!=](op_cmp.md)               | compares two vectors for inequality
[operator-=](op_per_mem_compound.md)  | per-member substraction
[operator+=](op_per_mem_compound.md)  | per-member addition
[operator*=](op_per_mem_compound.md)  | per-member multiplication
[operator/=](op_per_mem_compound.md)  | per-member division
[operator-](op_per_mem.md)            | per-member substraction
[operator+](op_per_mem.md)            | per-member addition
[operator*](op_per_mem.md)            | per-member multiplication
[operator/](op_per_mem.md)            | per-member division
[abs](abs.md)                         | per-member abs()
[min](min.md)                         | per-member min()
[max](min.md)                         | per-member max()

### Unary operations

Function                                          | Behavior
--------------------------------------------------|------------------------
[operator-<sub>(unary)</sub>](unary_minus.md)     | negation

### Scalar operations

Function                                                 | Behavior
---------------------------------------------------------|---------------------
[operator/=<sub>(scalar)</sub>](scaling_compound.md) | vector scaling
[operator*=<sub>(scalar)</sub>](scaling_compound.md) | vector scaling
[operator/<sub>(scalar)</sub>](scaling.md)           | vector scaling
[operator*<sub>(scalar)</sub>](scaling.md)           | vector scaling

### Geometric functions

Function                            | Behavior
------------------------------------|------------------------
[lenght](norm.md)                   | get vector's L2 norm
[dot](dot.md)                       | dot product
[cross](cross.md)                   | cross product