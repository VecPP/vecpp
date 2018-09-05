[vecpp](../../) :: [reference](../)
# Mat

```
template<typename T, std::size_t C, std::size_t R>
struct Mat;
```
A regular mathematical dense matrix.

## Member types

Member Type | Definition
------------|-----------
`value_type`  | `T`
`col_type`    | `Vec<value_type, rows>`
`row_type`    | `Vec<value_type, cols>`

## Member constants
name     | type           | Definition
---------|----------------|-----------
`rows`   | `std::size_t`  | Number of rows
`cols`   | `std::size_t`  | Number of columns

## Member functions

Member                              | Behavior
------------------------------------|------------------------
[(constructor)](constructor.md)     | initalize using aggregate initialization
(destructor)                        | destroy every element in the matrix
operator=                           | ovewrite the matrix with another matrix
[at](at.md)                         | access specific element with bounds checking 
[operator[]](operator_at.md)         | access specific element
[data](data.md)                     | access underlying array

## Non-member functions

### Language support

Function                            | Behavior
------------------------------------|------------------------
[operator<<](format.md)             | print to stream

### Per-member operations

Function                                  | Behavior
------------------------------------------|------------------------
[operator==](op_cmp.md)               | compares two vectors for equality
[operator!=](op_cmp.md)               | compares two vectors for inequality
[operator-=](op_per_mem_compound.md)  | per-member substraction
[operator/=](op_per_mem_compound.md)  | per-member division
[operator-](op_per_mem.md)            | per-member substraction
[operator+](op_per_mem.md)            | per-member addition

### Unary operations

Function                                          | Behavior
--------------------------------------------------|------------------------
[operator-<sub>(unary)</sub>](unary_minus.md) | negation

### Scalar operations

Function                                                 | Behavior
---------------------------------------------------------|---------------------
[operator/=<sub>(scalar)</sub>](scaling_compound.md) | matrix scaling
[operator*=<sub>(scalar)</sub>](scaling_compound.md) | matrix scaling
[operator/<sub>(scalar)</sub>](scaling.md)           | matrix scaling
[operator*<sub>(scalar)</sub>](scaling.md)           | matrix scaling

### Geometric functions

Function                            | Behavior
------------------------------------|------------------------
[determinant](determinant.md)       | Calculate determinant
[transpose](transpose.md)           | Generate transposed matrix