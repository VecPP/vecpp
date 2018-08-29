# Vec

```
template<typename T, std::size_t L>
struct Vec;
```
In many respects, `Vec` behaves a lot like `std::array<>`, but with support for mathematical operations.

## Member types

Member Type | Definition
------------|-----------
value_type  | T

## Member functions

Member                              | Behavior
------------------------------------|------------------------
[(constructor)](vec/constructor.md) | initalize the Vector using aggregate initialization
(destructor)                        | destroy every element in the vectpr
operator=                           | ovewrite the vector with another vector
[at](vec/at.md)                     | access specific element with bounds checking 
[operator[]](vec/operator_at.md)    | access specific element
[data](vec/data.md)                 | access underlying array

## Non-member functions

### Range support

Function                            | Behavior
------------------------------------|------------------------
[begin](vec/begin.md)               | iterator to the beginning
[end](vec/end.md)                 | iterator to the end

### Per-member operations

Function                                  | Behavior
------------------------------------------|------------------------
[operator==](vec/op_cmp.md)               | compares two vectors for equality
[operator!=](vec/op_cmp.md)               | compares two vectors for inequality
[operator-=](vec/op_per_mem_compound.md)  | per-member substraction
[operator+=](vec/op_per_mem_compound.md)  | per-member addition
[operator*=](vec/op_per_mem_compound.md)  | per-member multiplication
[operator/=](vec/op_per_mem_compound.md)  | per-member division
[operator-](vec/op_per_mem.md)            | per-member substraction
[operator+](vec/op_per_mem.md)            | per-member addition
[operator*](vec/op_per_mem.md)            | per-member multiplication
[operator/](vec/op_per_mem.md)            | per-member division
[min](vec/min.md)                         | per-member min()
[max](vec/min.md)                         | per-member max()

### Unary operations

Function                                          | Behavior
--------------------------------------------------|------------------------
[operator-<sub>(unary)</sub>](vec/unary_minus.md) | negation

### Scalar operations

Function                                                 | Behavior
---------------------------------------------------------|---------------------
[operator/=<sub>(scalar)</sub>](vec/scaling_compound.md) | vector scaling
[operator*=<sub>(scalar)</sub>](vec/scaling_compound.md) | vector scaling
[operator/<sub>(scalar)</sub>](vec/scaling.md)           | vector scaling
[operator*<sub>(scalar)</sub>](vec/scaling.md)           | vector scaling

### Geometric functions

Function                            | Behavior
------------------------------------|------------------------
[lenght](vec/length.md)             | get vector's euclidian length
[dot](vec/dot.md)                   | dot product
[cross](vec/cross.md)               | cross product