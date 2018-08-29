# Angle

```
template<typename T>
struct Angle;
```
Angle is a wrapper type around a representation that helps manage angles in a
consistent manner.

Angle values are always kepts within the ]-PI, PI] range at all times.

## Member types

Member Type | Definition
------------|-----------
value_type  | T

## Member functions

Member                                      | Behavior
--------------------------------------------|------------------------
(destructor)                                | does nothing
operator=                                   | ovewrite the angle with another angle
[from_deg](angle/from.md)                   | new angle from a degree value
[from_rad](angle/from.md)                   | new angle from a radian value
[from_clamped_deg](angle/from_clamped.md)   | unsafe new angle from a degree value
[from_clamped_rad](angle/from_clamped.md)   | unsafe new angle from a radian value
[as_deg](angle/as.md)                       | get the angle value as radians
[as_rad](angle/as.md)                       | get the angle value as degrees


## Non-member functions

### Language support

Function                            | Behavior
------------------------------------|------------------------
[operator<<](angle/format.md)         | print to stream

### Binary operations

Function                                  | Behavior
------------------------------------------|------------------------
[operator==](angle/op_cmp.md)             | compares two angles for equality
[operator!=](angle/op_cmp.md)             | compares two angles for inequality
[operator<](angle/op_cmp.md)              | compares two angles
[operator<=](angle/op_cmp.md)             | compares two angles
[operator>](angle/op_cmp.md)              | compares two angles
[operator>=](angle/op_cmp.md)             | compares two angles
[operator-=](angle/arithmetic_inplace.md) | in-place diff angles
[operator+=](angle/arithmetic_inplace.md) | in-place add angles
[operator-](angle/arithmetic.md)          | diff angles
[operator+](angle/arithmetic.md)          | add angles
[operator*=](angle/scale_inplace.md)      | in-place scale angle
[operator/=](angle/scale_inplace.md)      | in-place scale angle
[operator*](angle/scale.md)               | scale angle
[operator/](angle/scale.md)               | scale angle

### Unary operations

Function                                            | Behavior
----------------------------------------------------|------------------------
[operator-<sub>(unary)</sub>](angle/unary_minus.md) | negation
