[vecpp](../../) :: [reference](../)

# Angle

```
template<typename T>
struct Angle;
```
Angle is a wrapper type around a representation that helps manage angles in a
consistent manner.

Angle values are always kepts within the ]-PI, PI] range at all times.

## Member types

Member Type   | Definition
--------------|-----------
`value_type`  | `T`

## Member functions

Member                                      | Behavior
--------------------------------------------|------------------------
(destructor)                                | does nothing
operator=                                   | ovewrite the angle with another angle
[from_deg](from.md)                   | new angle from a degree value
[from_rad](from.md)                   | new angle from a radian value
[as_deg](as.md)                       | get the angle value as radians
[as_rad](as.md)                       | get the angle value as degrees


## Non-member functions

### Language support

Function                            | Behavior
------------------------------------|------------------------
[operator<<](format.md)         | print to stream

### Binary operations

Function                                  | Behavior
------------------------------------------|------------------------
[operator==](op_cmp.md)             | compares two angles for equality
[operator!=](op_cmp.md)             | compares two angles for inequality
[operator<](op_cmp.md)              | compares two angles
[operator<=](op_cmp.md)             | compares two angles
[operator>](op_cmp.md)              | compares two angles
[operator>=](op_cmp.md)             | compares two angles
[operator-=](arithmetic_inplace.md) | in-place diff angles
[operator+=](arithmetic_inplace.md) | in-place add angles
[operator-](arithmetic.md)          | diff angles
[operator+](arithmetic.md)          | add angles
[operator*=](scale_inplace.md)      | in-place scale angle
[operator/=](scale_inplace.md)      | in-place scale angle
[operator*](scale.md)               | scale angle
[operator/](scale.md)               | scale angle

### Unary operations

Function                                            | Behavior
----------------------------------------------------|------------------------
[operator-<sub>(unary)</sub>](unary_minus.md) | negation

### Trigonometric functions
Function                                            | Behavior
----------------------------------------------------|------------------------
[sin](sin.md)                                 | sine
[cos](cos.md)                                 | cosine
[tan](tan.md)                                 | tangent

### Advanced/unsafe functions

Member                                      | Behavior
--------------------------------------------|------------------------
[raw](raw.md)                         | gets the raw internal value of the angle
[from_clamped_deg](from_clamped.md)   | unsafe new angle from a degree value
[from_clamped_rad](from_clamped.md)   | unsafe new angle from a radian value