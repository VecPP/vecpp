# Reference Guide

- [Angles](angle/index.md)
- [Vector](vec/index.md)
- [Matrices](mat/index.md)


## Cheat-Sheet

No time to browse the API reference? Here's a quick reference to the most 
commonly used parts of the library.

### Types:

How             | What
----------------|------------------
`Angle<T>`      | An angle, stored as `T`
`Vec<T, N>`     | A carthesian vector of length `N`, where each value is a `T`
`Mat<T, C, R>`  | A `CxR` Matrix, where each cell is a `T`
`Quat<T>`       | A quaternion, where each member is stored as a `T`

### Angles:

How                      | What
-------------------------|-------------------
**Construction**         |
`Angle<T>::from_deg(T)`  | angle from degrees
`Angle<T>::from_rad(T)`  | angle from radians
**Access**               |
`angle.as_deg()`         | get as degrees
`angle.as_rad()`         | get as radians
**Trigonometry**         |
`sin(Angle)`             | sine
`cos(Angle)`             | cosine
`tan(Angle)`             | tangent
**Format**               |
`ostream << Angle`         | Print to stream

### Vectors:

How                              | What
---------------------------------|-------------------
**Construction**                 |
`Vec<T, N> v = {T, ...}`         |
`Vec<T, N>{T, ...}`              | 
**Access**                       |
`vec.at(i)`                        |
`vec[i]`                           |
`for(auto v: vec) {}`              |
**Operations**                   |
`norm(vec)`                        |
`normalize(vec)`                   |
`dot(vec)`                         |
`cross(vec, vec)`                  | Cross-product (only for `Vec<T,3>`)
**Format**                       |
`ostream << vec`                   |

### Constants

How                  | What                
---------------------|-------------
`pi<Scalar>`         | π
`two_pi<Scalar>`     | 2π
`half_pi<Scalar>`    | π/2


