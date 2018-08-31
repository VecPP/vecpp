# Compile-time evaluation

Almost every single thing you can do in vecpp, you can also do during compile 
time. 

*For the most part*, everything works transparently. You can just use any vecpp
construct within a constant expression, this includes 

```cpp

using Vec3 = vecpp::Vec<float, 3>;
using Angle = vecpp::Angle<float>;

constexpr Vec3 unit_x = {1.0f, 0.0f, 0.0f};
constexpr Vec3 unit_y = {0.0f, 1.0f, 0.0f};
constexpr Vec3 unit_z = {0.0f, 0.0f, 1.0f};

constexpr float x_dot_y = dot(unit_x, unit_y);
constexpr Vec3 y_cross_z = dot(unit_y, unit_z);

constexpr Angle rotation = Angle::from_deg(45.0f);
```

We say "for the most part", because fully implementing `vecpp` in `constexpr`,
while possible, would come at the cost of runtime performance. Specifically some
operations, such as `sqrt()` have extremely fast hardware support available to 
them on some platforms, and implementing such operations as constexpr-friendly 
alternatives would lock our users out from them, which is unnaceptible.

Unfortunately, it is currently impossible in standard C++ to write a function 
that has a compile-time switch for `constexpr` and `non-constexpr` 
implementations, so we have taken the following approach:

If an operation's algorithm is identical between constexpr and non-constexpr
versions, it will simply work. Otherwise, algorithm selection will be driven by
a `Flags` template parameter that will always default to the fast 
runtime-algorithm.

## Scalar operations

Scalar operations can be forced to use the constexpr version by passing them
the `vecpp::flags::compile_time` flag as a template parameter.

For example:

```cpp
constexpr vecpp::Flags ctf = vecpp::flags::compile_time;

constexpr y = vecpp::sqrt<ctf>(15.0f);  // Definitely great!
float x = vecpp::sqrt<ctf>(12.0f);      // Probably not what you want.
```

This will trigger the selection of the `constexpr`-friendly algorithm for sqrt,
but **does not guarantee compile-time evaluation** unless being used to generate
a `constexpr` value.

## Exceptions

- Uninitialized values cannot be employed in `constexpr` contexts, whereas vecpp
generalyy allows them at the user's discretion.

That's it
