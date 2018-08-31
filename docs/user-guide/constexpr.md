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


* If an operation's algorithm is identical between constexpr and non-constexpr
versions, it will simply work. 
* Otherwise, algorithm selection will be driven by a `Flags` template parameter 
that will always default to the fast runtime-algorithm.
* If you attempt to use a ct-branching algorithm to generate a 
`constexpr` value without foricing it into the `constexpr`-friendly path, you
WILL get a compile error.

## `constexpr` workflow

The user workflow is simple:

1. Assume that everything transparently works as constexpr.
2. If you encounter a compile error that says something along the lines of
`call to non-constexpr function...`: 
     - wrap the offending parameters into a `vecpp::ct()` call.

For example:

```cpp

using vecpp::ct;
using Vec3 = vecpp::Vec<float, 3>;


constexpr Vec3 my_vec = {1.0f, 4.0f, 0.0f};
//constexpr float my_vec_len = length(my_vec); // Error, needs non-constexpr sqrt()
constexpr float my_vec_len = length(ct(my_vec)); // all clear
```

## Scalars

Scalar operations use a slightly nicer APi:


```cpp
constexpr vecpp::Flags ctf = vecpp::flags::compile_time;

constexpr sqrt_val = vecpp::sqrt<ctf>(16.0f);
```

Now at this point, you are probably wondering: "Why can't I use that nicer API"
with vectors? Wouldn;t the following be a lot nicer?

```cpp
// ****************** NOT REAL CODE ****************** // 
using Vec3 = vecpp::Vec<float, 3>;
constexpr vecpp::Flags ctf = vecpp::flags::compile_time;

constexpr Vec3 my_vec = {1.0f, 4.0f, 0.0f};
constexpr float my_vec_len = length<ctf>(my_vec); 
// ****************** NOT REAL CODE ****************** //
```

Well, yes, that would indeed be a lot nicer, and frankly easy to implement. 

The problem with that is that it cannot be applied to operators, which will 
become a massive pain once we start playing with matrices. And we want to avoid 
having multiple ways of doing the same thing.  

## Exceptions

- Uninitialized values cannot be employed in `constexpr` contexts, whereas vecpp
generalyy allows them at the user's discretion.

That's it
